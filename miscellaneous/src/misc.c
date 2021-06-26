//
// Created by onacit on 2021-06-26.
//

#include <stdio.h>
#include "misc.h"

const char * ordinal_suffix_for_long(long ordinal) {
    switch (ordinal % 10) {
        case 1:
            return ordinal == 11 ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ST;
        case 2:
            return ordinal == 12 ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ND;
        case 3:
            return ordinal == 13 ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_RD;
        default:
            return ORDINAL_SUFFIX_TH;
    }
}

int long_to_ordinal_suffixed(char *s, size_t n, long ordinal) {
    return snprintf(s, n, "%ld%s", ordinal, ordinal_suffix_for_long(ordinal));
}

