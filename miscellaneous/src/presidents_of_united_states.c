//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presidents_of_united_states.h"

static char filename[] = "presidents_of_united_states.txt";

struct president_of_united_state * president_of_united_states(long presidency, char *president) {
    assert(presidency > 0L);
    assert(president != NULL);
    struct president_of_united_state *p = malloc(sizeof(struct president_of_united_state));
    if (p == NULL) {
        return NULL;
    }
    p-> presidency = presidency;
    p->president = malloc(strlen(president) + 1);
    strcpy(p->president, president);
    return p;
}

void president_of_united_states_free(struct president_of_united_state *p) {
    assert (p != NULL);
    free(p->president);
    free(p);
}

void president_of_united_states_free_void(void *p) {
    president_of_united_states_free((struct president_of_united_state *) p);
}


int presidents_of_united_states_consume_while(bool (*const accept)(long, char *)) {
    assert(accept != NULL);
    FILE *stream;
    if ((stream = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "failed to open %s\n", filename);
        return EXIT_FAILURE;
    }
    char buf[26];
    const int len = (sizeof buf / sizeof (char));
    long presidency;
    char *president;
    while (fgets(buf, len, stream)) {
        buf[strcspn(buf, "\r\n")] = 0;
        presidency = strtol(buf, &president, 10);
        ++president;
        if (!(*accept)(presidency, president)) {
            break;
        }
    }
    if (fclose(stream) != 0) {
        fprintf(stderr, "failed to close the stream");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int presidents_of_united_states_iterate_while(struct president_of_united_state_iterator *iterator) {
    assert(iterator != NULL);
    FILE *stream;
    if ((stream = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "failed to open %s\n", filename);
        return EXIT_FAILURE;
    }
    char buf[26];
    const int len = sizeof buf / sizeof (char);
    long presidency;
    char *president;
    while (fgets(buf, len, stream)) {
        buf[strcspn(buf, "\r\n")] = 0;
        presidency = strtol(buf, &president, 10);
        ++president;
        if (!iterator->accept(iterator, presidency, president)) {
            break;
        }
    }
    if (fclose(stream) != 0) {
        fprintf(stderr, "failed to close the stream");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}