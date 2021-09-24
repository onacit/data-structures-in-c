
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "miscellaneous.h"

int main(int argc, char **argv) {
    if (argc == 1) {
        fprintf(stderr, "no arguments provided");
        return EXIT_FAILURE;
    }
    char uchar[snprintf(NULL, 0, "%hhu", UCHAR_MAX) + 3];
    char ushrt[snprintf(NULL, 0, "%hu", USHRT_MAX) + 3];
    char uint[snprintf(NULL, 0, "%u", UINT_MAX) + 3];
    char ulong[snprintf(NULL, 0, "%lu", ULONG_MAX) + 3];
    char ullong[snprintf(NULL, 0, "%llu", ULLONG_MAX) + 3];
    unsigned long long int c;
    for (int i = 1; i < argc; i++) {
        c = strtoull(argv[i], NULL, 10);
        if (c <= UCHAR_MAX) {
            int const n = sprintf_ordinal_g(uchar, (unsigned char) c);
            continue;
        }
        if (c <= USHRT_MAX) {
            int const n = sprintf_ordinal_g(ushrt, (unsigned short int) c);
            continue;
        }
        if (c <= UINT_MAX) {
            int const n = sprintf_ordinal_g(uint, (unsigned int) c);
            continue;
        }
        if (c <= ULONG_MAX) {
            int const n = sprintf_ordinal_g(ulong, (unsigned long int) c);
            continue;
        }
        if (c <= ULLONG_MAX) {
            int const n = sprintf_ordinal_g(ullong, (unsigned long long int) c);
            continue;
        }
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}