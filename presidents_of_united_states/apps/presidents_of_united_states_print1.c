//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "presidents_of_united_states.h"

bool print(long *ordinal, char *name) {
    assert(ordinal != NULL);
    assert(name != NULL);
    printf("%-2ld %s\n", *ordinal, name);
    return true;
}

int main() {
    if (presidents_of_united_states_consume(print) != EXIT_SUCCESS) {
        fprintf(stderr, "consuming failed\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


