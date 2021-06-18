//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "presidents_of_united_states.h"

bool print(struct president_of_united_state_iterator *iterator, long *ordinal, char *name) {
    assert(iterator != NULL);
    assert(ordinal != NULL);
    assert(name != NULL);
    printf("%-2ld %s\n", *ordinal, name);
    return true;
}

int main() {
    struct president_of_united_state_iterator *iterator = malloc(sizeof(struct president_of_united_state_iterator));
    if (iterator == NULL) {
        fprintf(stderr, "failed to allocate an iterator");
        return EXIT_FAILURE;
    }
    iterator->environment = NULL;
    iterator->consume = print;
    if (presidents_of_united_states_iterate(iterator) != EXIT_SUCCESS) {
        fprintf(stderr, "iteration failed\n");
    }
    free(iterator);
    return EXIT_SUCCESS;
}


