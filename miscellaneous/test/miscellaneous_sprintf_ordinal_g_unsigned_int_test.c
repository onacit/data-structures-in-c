
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "miscellaneous.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "no arguments provided");
        return EXIT_FAILURE;
    }
    int const l = snprintf(NULL, 0, "%u", UINT_MAX);
    char o[l + 3];
    unsigned long int c;
    for (int i = 1; i < argc; i++) {
        c = strtoul(argv[i], NULL, 0);
        if (errno == ERANGE) {
            fprintf(stderr, "unable to convert argv[%d]('%s') to an unsigned int", i, argv[i]);
            continue;
        }
        if (c > UINT_MAX) {
            return EXIT_FAILURE;
        }
        int const n = sprintf_ordinal_g(o, (unsigned int) c);
        assert(n < l + 3);
        printf("%*s: %s\n", l, argv[i], o);
    }
    printf("%*u\n", (l << 1) + 2, UINT_MAX);
    return EXIT_SUCCESS;
}