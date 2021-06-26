//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "presidents_of_united_states.h"

static long presidency_to_match;

bool find_by_presidency(long *presidency, char *president) {
    assert(presidency != NULL);
    assert(president != NULL);
    if (*presidency == presidency_to_match) {
        printf("%-2ld %s\n", *presidency, president);
        return false;
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        fprintf(stderr, "missing an argument for presidency");
        return EXIT_FAILURE;
    }
    presidency_to_match = strtol(argv[1], NULL, 10);
    if (presidency_to_match == 0L) {
        fprintf(stderr, "failed to convert %s to a presidency\n", argv[1]);
        return EXIT_FAILURE;
    }
    return presidents_of_united_states_consume_while(find_by_presidency);
}


