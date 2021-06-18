//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presidents_of_united_states.h"

static char FileName[] = "presidents_of_united_states.txt";

int presidents_of_united_states_consume(bool (*accept)(long *, char *)) {
    assert(accept != NULL);
    FILE *stream;
    if ((stream = fopen(FileName, "r")) == NULL) {
        fprintf(stderr, "failed to open %s\n", FileName);
        return EXIT_FAILURE;
    }
    char buffer[27];
    long ordinal;
    char *name;
    while (fgets(buffer, 27, stream)) {
        buffer[strcspn(buffer, "\r\n")] = 0;
        ordinal = strtol(buffer, &name, 10);
        ++name;
        if (!(*accept)(&ordinal, name)) {
            break;
        }
    }
    if (fclose(stream) != 0) {
        fprintf(stderr, "failed to close the stream");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int presidents_of_united_states_iterate(struct president_of_united_state_iterator *iterator) {
    assert(iterator != NULL);
    FILE *stream;
    if ((stream = fopen(FileName, "r")) == NULL) {
        fprintf(stderr, "failed to open %s\n", FileName);
        return EXIT_FAILURE;
    }
    char buffer[27];
    long ordinal;
    char *name;
    while (fgets(buffer, 27, stream)) {
        buffer[strcspn(buffer, "\r\n")] = 0;
        ordinal = strtol(buffer, &name, 10);
        ++name;
        if (!iterator->accept(iterator, &ordinal, name)) {
            break;
        }
    }
    if (fclose(stream) != 0) {
        fprintf(stderr, "failed to close the stream");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}




