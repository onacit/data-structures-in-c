
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "miscellaneous.h"

int main(int argc, char **argv) {
    int const l = snprintf(NULL, 0, "%hhu", UCHAR_MAX);
    char ordinal[l + 1];
    int const n = sprintf_ordinal_g(ordinal, UCHAR_MAX);
    printf("UCHAR_MAX: %s (%d)\n", ordinal, n);
    return l + 2 == n ? EXIT_SUCCESS : EXIT_FAILURE;
}