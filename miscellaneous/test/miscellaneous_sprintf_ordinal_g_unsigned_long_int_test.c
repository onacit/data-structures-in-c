
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "miscellaneous.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "no arguments provided");
        return EXIT_FAILURE;
    }
    int const length = snprintf(NULL, 0, "%lu", ULONG_MAX);
    char ordinal[length + 3];
    unsigned long int c;
    for (int i = 1; i < argc; i++) {
        c = strtoul(argv[i], NULL, 0);
        if (errno == ERANGE) {
            fprintf(stderr, "unable to convert argv[%d]('%s') to an unsigned long int", i, argv[i]);
            continue;
        }
        int const n = sprintf_ordinal_g(ordinal, c);
        printf("%*s: %s\n", length, argv[i], ordinal);
    }
    printf("%*lu\n", (length << 1) + 2, ULONG_MAX);
    return EXIT_SUCCESS;
}