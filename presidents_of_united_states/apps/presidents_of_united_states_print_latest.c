//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presidents_of_united_states.h"

bool accept(struct president_of_united_state_iterator *iterator, long *presidency, char *president) {
    assert(iterator != NULL);
    assert(presidency != NULL);
    assert(president != NULL);
    struct president_of_united_state *environment = iterator->environment;
    environment->presidency = *presidency;
    void *const reallocated = realloc(environment->president, strlen(president) + 1);
    if (reallocated == NULL) {
        fprintf(stderr, "failed to reallocate %p for %s\n", environment->president, president);
        return false;
    }
    environment->president = reallocated;
    environment->president = strcpy(environment->president, president);
//    printf("%-2ld %s\n", *presidency, president);
    return true;
}

int main() {
    struct president_of_united_state_iterator *iterator = malloc(sizeof(struct president_of_united_state_iterator));
    if (iterator == NULL) {
        fprintf(stderr, "failed to allocate an iterator");
        return EXIT_FAILURE;
    }
    struct president_of_united_state *president = malloc(sizeof(struct president_of_united_state));
    if (president == NULL) {
        fprintf(stderr, "failed to allocate an environment");
        free(iterator);
        return EXIT_FAILURE;
    }
    president->president = NULL;
    iterator->environment = president;
    iterator->accept = accept;
    if (presidents_of_united_states_iterate(iterator) == EXIT_SUCCESS) {
        printf("%s is the latest president of United States.\n", president->president);
    } else {
        fprintf (stderr, "iteration failed\n");
    }
    free(president->president);
    president->president = NULL;
    free(president);
    president = NULL;
    free(iterator);
    iterator = NULL;
    return EXIT_SUCCESS;
}


