
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("CHAR_BIT:   %u\n", CHAR_BIT);
    printf("SCHAR_MIN:  %+hhi\n", SCHAR_MIN);
    printf("SCHAR_MAX:  %+hhi\n", SCHAR_MAX);
    printf("UCHAR_MAX:  %hhu\n", UCHAR_MAX);
//    printf("MB_CUR_MAX: %u\n", MB_CUR_MAX);
//    printf("MB_LEN_MAX: %u\n", MB_LEN_MAX);
    printf("SHRT_MIN:   %+hi\n", SHRT_MIN);
    printf("SHRT_MAX:   %+hd\n", SHRT_MAX);
    printf("USHRT_MAX:  %hu\n", USHRT_MAX);
    printf("INT_MIN:    %+i\n", INT_MIN);
    printf("INT_MAX:    %+d\n", INT_MAX);
    printf("UINT_MAX:   %u\n", UINT_MAX);
    printf("LONG_MIN:   %+li\n", LONG_MIN);
    printf("LONG_MAX:   %+ld\n", LONG_MAX);
    printf("ULONG_MAX:  %lu\n", ULONG_MAX);
    printf("LLONG_MIN:  %+lli\n", LLONG_MIN);
    printf("LLONG_MAX:  %+lld\n", LLONG_MAX);
    printf("ULLONG_MAX: %llu\n", ULLONG_MAX);
    return EXIT_SUCCESS;
}
