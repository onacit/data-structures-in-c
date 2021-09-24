
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "miscellaneous.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "no arguments provided");
        return EXIT_FAILURE;
    }
    int const length = snprintf(NULL, 0, "%hu", USHRT_MAX);
    char ordinal[length + 3];
    unsigned long int c;
    for (int i = 1; i < argc; i++) {
        c = strtoul(argv[i], NULL, 0);
        if (errno == ERANGE) {
            return EXIT_FAILURE;
        }
        if (c > USHRT_MAX) {
            fprintf(stderr, "unable to convert argv[%d]('%s') to an unsigned short int", i, argv[i]);
            continue;
        }
        int const n = sprintf_ordinal_g(ordinal, (unsigned short int) c);
        assert(n < length + 3);
        printf("%*s: %s\n", length, argv[i], ordinal);
    }
    printf("%*hu\n", (length << 1) + 2, USHRT_MAX);
    return EXIT_SUCCESS;
}