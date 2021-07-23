//
// Created by onacit on 2021-06-26.
//

#include <stdio.h>
#include "miscellaneous.h"

static const char * const ORDINAL_SUFFIX_ST = "st";
static const char * const ORDINAL_SUFFIX_ND = "nd";
static const char * const ORDINAL_SUFFIX_RD = "rd";
static const char * const ORDINAL_SUFFIX_TH = "th";

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

