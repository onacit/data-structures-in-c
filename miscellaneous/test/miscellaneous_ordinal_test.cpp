//
// Created by onacit on 2021-09-22.
//

#include "gtest/gtest.h"

extern "C" {
#include "miscellaneous.h"
};

TEST(Ordinal, 11th) {
    int const l = snprintf(NULL, 0, "%d", 11);
    char ordinal[l + 1];
    int const n = sprintf_ordinal_u(ordinal, 11);
    ASSERT_EQ(l + 2, n);
    EXPECT_STREQ("11th", ordinal);
}

TEST(Ordinal, 12th) {
    int const l = snprintf(NULL, 0, "%d", 12);
    char ordinal[l + 1];
    int const n = sprintf_ordinal_u(ordinal, 12);
    ASSERT_EQ(l + 2, n);
    EXPECT_STREQ("12th", ordinal);
}

TEST(Ordinal, 13th) {
    int const l = snprintf(NULL, 0, "%d", 13);
    char ordinal[l + 1];
    int const n = sprintf_ordinal_u(ordinal, 13);
    ASSERT_EQ(l + 2, n);
    EXPECT_STREQ("13th", ordinal);
}

TEST(Ordinal, UCHARMAX) {
    int const l = snprintf(NULL, 0, "%hhu", UCHAR_MAX);
    char ordinal[l + 1];
    int const n = sprintf_ordinal_u(ordinal, UCHAR_MAX);
    printf("UCHAR_MAX: %s (%d)\n", ordinal, n);
    ASSERT_EQ(l + 2, n);
}

TEST(Ordinal, USHRTMAX) {
    int const l = snprintf(NULL, 0, "%hu", USHRT_MAX);
    char ordinal[l + 1];
    int const n = sprintf_ordinal_u(ordinal, USHRT_MAX);
    printf("USHRT_MAX: %s (%d)\n", ordinal, n);
    ASSERT_EQ(l + 2, n);
}

TEST(Ordinal, UINTMAX) {
    int const l = snprintf(NULL, 0, "%u", UINT_MAX);
    char ordinal[l + 1];
    int const n = sprintf_ordinal_u(ordinal, UINT_MAX);
    printf("UINT_MAX: %s (%d)\n", ordinal, n);
    ASSERT_EQ(l + 2, n);
}

TEST(Ordinal, ULONGMAX) {
    int const l = snprintf(NULL, 0, "%lu", ULONG_MAX);
    char ordinal[l + 1];
    int const n = sprintf_ordinal_lu(ordinal, ULONG_MAX);
    printf("ULONG_MAX: %s (%d)\n", ordinal, n);
    ASSERT_EQ(l + 2, n);
}

TEST(Ordinal, ULLONGMAX) {
    int const l = snprintf(NULL, 0, "%llu", ULLONG_MAX);
    char ordinal[l + 1];
    int const n = sprintf_ordinal_llu(ordinal, ULLONG_MAX);
    printf("ULLONG_MAX: %s (%d)\n", ordinal, n);
    ASSERT_EQ(l + 2, n);
}