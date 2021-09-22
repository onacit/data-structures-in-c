//
// Created by onacit on 2021-06-26.
//

#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include "miscellaneous.h"

static const char *const ORDINAL_SUFFIX_ST = "st";
static const char *const ORDINAL_SUFFIX_ND = "nd";
static const char *const ORDINAL_SUFFIX_RD = "rd";
static const char *const ORDINAL_SUFFIX_TH = "th";

const char *ordinal_suffix_hhu(unsigned char const c) {
    switch (c % 10) {
        case 1:
            return c == 11 ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ST;
        case 2:
            return c == 12 ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ND;
        case 3:
            return c == 13 ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_RD;
        default:
            return ORDINAL_SUFFIX_TH;
    }
}

int ordinal_hhu(char *const s, unsigned char const c) {
    assert(s != NULL);
    return sprintf(s, "%hhu%s", c, ordinal_suffix_hhu(c));
}

int ordinal_hhu_n(char *const s, size_t const n, unsigned char const c) {
    assert(s != NULL);
    return snprintf(s, n, "%hhu%s", c, ordinal_suffix_hhu(c));
}

const char *ordinal_suffix_hu(unsigned short const c) {
    switch (c % 10) {
        case 1:
            return c == 11 ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ST;
        case 2:
            return c == 12 ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ND;
        case 3:
            return c == 13 ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_RD;
        default:
            return ORDINAL_SUFFIX_TH;
    }
}

int ordinal_hu(char *const s, unsigned short const c) {
    assert(s != NULL);
    return sprintf(s, "%hu%s", c, ordinal_suffix_hu(c));
}

int ordinal_hu_n(char *const s, size_t const n, unsigned short const c) {
    assert(s != NULL);
    return snprintf(s, n, "%hu%s", c, ordinal_suffix_hu(c));
}

const char *ordinal_suffix_u(unsigned int const c) {
    switch (c % 10U) {
        case 1:
            return c == 11U ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ST;
        case 2:
            return c == 12U ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ND;
        case 3:
            return c == 13U ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_RD;
        default:
            return ORDINAL_SUFFIX_TH;
    }
}

int ordinal_u(char *const s, unsigned int const c) {
    assert(s != NULL);
    return sprintf(s, "%u%s", c, ordinal_suffix_u(c));
}

int ordinal_u_n(char *const s, size_t const n, unsigned int const c) {
    assert(s != NULL);
    return snprintf(s, n, "%u%s", c, ordinal_suffix_u(c));
}

const char *ordinal_suffix_lu(unsigned long const c) {
    switch (c % 10LU) {
        case 1L:
            return c == 11LU ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ST;
        case 2L:
            return c == 12LU ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ND;
        case 3L:
            return c == 13LU ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_RD;
        default:
            return ORDINAL_SUFFIX_TH;
    }
}

int ordinal_lu(char *const s, unsigned long const c) {
    return sprintf(s, "%lu%s", c, ordinal_suffix_lu(c));
}

int ordinal_lu_n(char *const s, size_t const n, unsigned long int const c) {
    return snprintf(s, n, "%lu%s", c, ordinal_suffix_lu(c));
}

const char *ordinal_suffix_llu(unsigned long long int const c) {
    switch (c % 10LLU) {
        case 1LLU:
            return c == 11LLU ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ST;
        case 2LLU:
            return c == 12LLU ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_ND;
        case 3LLU:
            return c == 13LLU ? ORDINAL_SUFFIX_TH : ORDINAL_SUFFIX_RD;
        default:
            return ORDINAL_SUFFIX_TH;
    }
}

int ordinal_llu(char *const s, unsigned long long int const c) {
    return sprintf(s, "%llu%s", c, ordinal_suffix_llu(c));
}

int ordinal_llu_n(char *const s, size_t const n, unsigned long long int const c) {
    return snprintf(s, n, "%llu%s", c, ordinal_suffix_llu(c));
}





