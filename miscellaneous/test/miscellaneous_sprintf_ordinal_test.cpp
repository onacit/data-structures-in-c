
#include <climits>
#include "gtest/gtest.h"

extern "C" {
#include "miscellaneous.h"
};

TEST(MiscellaneousSprintfOrdinal, 11th) {
    char o[5]; // "11th" + '\0'
    int const n = sprintf_ordinal_u(o, 11);
    ASSERT_EQ(4, n);
    EXPECT_STREQ("11th", o);
}

TEST(MiscellaneousSprintfOrdinal, 12th) {
    char o[5];
    int const n = sprintf_ordinal_u(o, 12);
    ASSERT_EQ(4, n);
    EXPECT_STREQ("12th", o);
}

TEST(MiscellaneousSprintfOrdinal, 13th) {
    char o[5];
    int const n = sprintf_ordinal_u(o, 13);
    ASSERT_EQ(4, n);
    EXPECT_STREQ("13th", o);
}

TEST(MiscellaneousSprintfOrdinal, UCHARMAX) {
    int const l = snprintf(NULL, 0, "%hhu", UCHAR_MAX);
    char o[l + 3];
    int const n = sprintf_ordinal_u(o, UCHAR_MAX);
    printf("UCHAR_MAX: %s (%d)\n", o, n);
    ASSERT_EQ(l + 2, n);
}

TEST(MiscellaneousSprintfOrdinal, USHRTMAX) {
    int const l = snprintf(NULL, 0, "%hu", USHRT_MAX);
    char o[l + 3];
    int const n = sprintf_ordinal_u(o, USHRT_MAX);
    printf("USHRT_MAX: %s (%d)\n", o, n);
    ASSERT_EQ(l + 2, n);
}

TEST(MiscellaneousSprintfOrdinal, UINTMAX) {
    int const l = snprintf(NULL, 0, "%u", UINT_MAX);
    char o[l + 3];
    int const n = sprintf_ordinal_u(o, UINT_MAX);
    printf("UINT_MAX: %s (%d)\n", o, n);
    ASSERT_EQ(l + 2, n);
}

TEST(MiscellaneousSprintfOrdinal, ULONGMAX) {
    int const l = snprintf(NULL, 0, "%lu", ULONG_MAX);
    char o[l + 3];
    int const n = sprintf_ordinal_lu(o, ULONG_MAX);
    printf("ULONG_MAX: %s (%d)\n", o, n);
    ASSERT_EQ(l + 2, n);
}

TEST(MiscellaneousSprintfOrdinal, ULLONGMAX) {
    int const l = snprintf(NULL, 0, "%llu", ULLONG_MAX);
    char o[l + 1];
    int const n = sprintf_ordinal_llu(o, ULLONG_MAX);
    printf("ULLONG_MAX: %s (%d)\n", o, n);
    ASSERT_EQ(l + 2, n);
}
