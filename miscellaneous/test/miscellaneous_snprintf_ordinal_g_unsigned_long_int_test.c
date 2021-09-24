
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
    int const l = snprintf(NULL, 0, "%lu", ULONG_MAX);
    char o[l + 3];
    unsigned long int c;
    for (int i = 1; i < argc; i++) {
        c = strtoul(argv[i], NULL, 0);
        if (errno == ERANGE) {
            fprintf(stderr, "unable to convert argv[%d]('%s') to an unsigned long int", i, argv[i]);
            continue;
        }
        int const n = snprintf_ordinal_g(o, l + 3, c);
        assert(n < l + 3);
        printf("%*s: %s\n", l, argv[i], o);
    }
    printf("%*lu\n", (l << 1) + 2, ULONG_MAX);
    return EXIT_SUCCESS;
}