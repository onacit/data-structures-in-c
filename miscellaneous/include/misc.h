//
// Created by onacit on 2021-06-26.
//

#ifndef DATA_STRUCTURES_IN_C_MISC_H
#define DATA_STRUCTURES_IN_C_MISC_H

static const char * const ORDINAL_SUFFIX_ST = "st";
static const char * const ORDINAL_SUFFIX_ND = "nd";
static const char * const ORDINAL_SUFFIX_RD = "rd";
static const char * const ORDINAL_SUFFIX_TH = "th";

const char * ordinal_suffix_for_long(long ordinal);

int long_to_ordinal_suffixed(char *s, size_t n, long ordinal);

#endif //DATA_STRUCTURES_IN_C_MISC_H
