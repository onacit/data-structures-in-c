//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presidents_of_united_states.h"
#include "presidents_of_united_states_misc.h"

bool current(struct president_of_united_state_iterator *iterator, long presidency, char *president) {
    assert(iterator != NULL);
    assert(president != NULL);
    struct president_of_united_state *environment = iterator->environment;
    environment->presidency = presidency;
    void *const reallocated = realloc(environment->president, strlen(president) + 1);
    if (reallocated == NULL) {
        fprintf(stderr, "failed to reallocate %p for %s\n", environment->president, president);
        return false;
    }
    environment->president = reallocated;
    environment->president = strcpy(environment->president, president);
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
        fprintf(stderr, "failed to allocate an env");
        free(iterator);
        return EXIT_FAILURE;
    }
    president->president = NULL;
    iterator->environment = president;
    iterator->accept = current;
    if (presidents_of_united_states_iterate_while(iterator) == EXIT_SUCCESS) {
        char s[5];
        const int l = presidency_to_ordinal_suffixed(s, president->presidency);
        assert (l >= 3 && l < 5); // '_st' ~ '__th'
        printf("%s is the %s and current president of the United States.\n", president->president, s);
    }
    free(president->president);
    president->president = NULL;
    free(president);
    president = NULL;
    free(iterator);
    iterator = NULL;
    return EXIT_SUCCESS;
}


