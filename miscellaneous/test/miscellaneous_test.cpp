//
// Created by onacit on 2021-09-22.
//

#include "gtest/gtest.h"

extern "C" {
#include "miscellaneous.h"
};

TEST(Ordinal, HHU) {
    char ordinal[5];
    int const n = ordinal_hhu(ordinal, 0);
    ASSERT_EQ(3, n);
    ASSERT_EQ(ordinal_numeral(ordinal, (unsigned char) 10), 4);
}

TEST(Ordinal, HU) {
    char ordinal[5];
    int const n = ordinal_hu(ordinal, 0);
    ASSERT_EQ(3, n);
}

TEST(Ordinal, U) {
    char ordinal[5];
    int const n = ordinal_u(ordinal, 0U);
    ASSERT_EQ(3, n);
}

TEST(Ordinal, LU) {
    char ordinal[5];
    int const n = ordinal_lu(ordinal, 0LU);
    ASSERT_EQ(3, n);
}

TEST(Ordinal, LLU) {
    char ordinal[5];
    int const n = ordinal_llu(ordinal, 0LLU);
    ASSERT_EQ(3, n);
}

