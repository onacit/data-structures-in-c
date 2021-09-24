
#include <climits>
#include "gtest/gtest.h"

extern "C" {
#include "miscellaneous.h"
};

TEST(MiscellaneousSnprintfOrdinal, 11th) {
    char o[5];
    int const n = snprintf_ordinal_u(o, 5, 11);
    ASSERT_EQ(4, n);
    EXPECT_STREQ("11th", o);
}

TEST(MiscellaneousSnprintfOrdinal, 12th) {
    char o[5];
    int const n = snprintf_ordinal_u(o, 5, 12);
    ASSERT_EQ(4, n);
    EXPECT_STREQ("12th", o);
}

TEST(MiscellaneousSnprintfOrdinal, 13th) {
    char o[5];
    int const n = snprintf_ordinal_u(o, 5, 13);
    ASSERT_EQ(4, n);
    EXPECT_STREQ("13th", o);
}

TEST(MiscellaneousSnprintfOrdinal, UCHARMAX) {
    int const l = snprintf(NULL, 0, "%hhu", UCHAR_MAX);
    char o[l + 3];
    int const n = snprintf_ordinal_u(o, l + 3, UCHAR_MAX);
    ASSERT_EQ(l + 2, n);
}

TEST(MiscellaneousSnprintfOrdinal, USHRTMAX) {
    int const l = snprintf(NULL, 0, "%hu", USHRT_MAX);
    char o[l + 3];
    int const n = snprintf_ordinal_u(o, l + 3, USHRT_MAX);
    printf("USHRT_MAX: %s (%d)\n", o, n);
    ASSERT_EQ(l + 2, n);
}

TEST(MiscellaneousSnprintfOrdinal, UINTMAX) {
    int const l = snprintf(NULL, 0, "%u", UINT_MAX);
    char o[l + 3];
    int const n = snprintf_ordinal_u(o, l + 3, UINT_MAX);
    printf("UINT_MAX: %s (%d)\n", o, n);
    ASSERT_EQ(l + 2, n);
}

TEST(MiscellaneousSnprintfOrdinal, ULONGMAX) {
    int const l = snprintf(NULL, 0, "%lu", ULONG_MAX);
    char o[l + 3];
    int const n = snprintf_ordinal_lu(o, l + 3, ULONG_MAX);
    printf("ULONG_MAX: %s (%d)\n", o, n);
    ASSERT_EQ(l + 2, n);
}

TEST(MiscellaneousSnprintfOrdinal, ULLONGMAX) {
    int const l = snprintf(NULL, 0, "%llu", ULLONG_MAX);
    char o[l + 3];
    int const n = snprintf_ordinal_llu(o, l, ULLONG_MAX);
    printf("ULLONG_MAX: %s (%d)\n", o, n);
    ASSERT_EQ(l + 2, n);
}
