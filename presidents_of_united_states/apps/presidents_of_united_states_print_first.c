//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "presidents_of_united_states.h"

bool print(long *const presidency, char *const president) {
    assert(presidency != NULL);
    assert(president != NULL);
    printf("%s is the latest president of United States.\n", president);
    return false;
}

int main() {
    if (presidents_of_united_states_consume(print) != EXIT_SUCCESS) {
        fprintf(stderr, "consuming failed\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


