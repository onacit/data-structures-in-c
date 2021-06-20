//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presidents_of_united_states.h"

static char *president_to_match;

bool find_by_president(long *presidency, char *president) {
    assert(presidency != NULL);
    assert(president != NULL);
    if (strstr(president, president_to_match) != NULL) {
        printf("%-2ld %s\n", *presidency, president);
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        fprintf(stderr, "missing argument for president");
        return EXIT_FAILURE;
    }
    president_to_match = argv[1];
    if (presidents_of_united_states_consume(find_by_president) != EXIT_SUCCESS) {
        fprintf(stderr, "consuming failed\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


