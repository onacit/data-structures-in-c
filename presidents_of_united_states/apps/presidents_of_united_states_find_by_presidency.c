//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "presidents_of_united_states.h"

static int c;
static long **v;

static long presidency_to_find;

bool find_by_presidency(long *presidency, char *president) {
    assert(presidency != NULL);
    assert(president != NULL);
    if (*presidency == presidency_to_find) {
        printf("%-2ld %s\n", *presidency, president);
        return false;
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        fprintf(stderr, "missing argument for presidency");
        return EXIT_FAILURE;
    }
    presidency_to_find = strtol(argv[1], NULL, 10);
    if (presidency_to_find == 0L) {
        fprintf(stderr, "failed to convert %s as a presidency\n", argv[1]);
        return EXIT_FAILURE;
    }
    if (presidents_of_united_states_consume(find_by_presidency) != EXIT_SUCCESS) {
        fprintf(stderr, "consuming failed\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


