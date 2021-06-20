//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presidents_of_united_states.h"

static char filename[] = "presidents_of_united_states.txt";

int presidents_of_united_states_consume(bool (*const accept)(long *, char *)) {
    assert(accept != NULL);
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
        if (!(*accept)(&presidency, president)) {
            break;
        }
    }
    if (fclose(stream) != 0) {
        fprintf(stderr, "failed to close the stream");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int presidents_of_united_states_iterate(struct president_of_united_state_iterator *const iterator) {
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
        if (!iterator->accept(iterator, &presidency, president)) {
            break;
        }
    }
    if (fclose(stream) != 0) {
        fprintf(stderr, "failed to close the stream");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}




