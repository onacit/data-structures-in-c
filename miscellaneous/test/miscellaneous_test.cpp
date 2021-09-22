//
// Created by onacit on 2021-09-22.
//

#include "gtest/gtest.h"

extern "C" {
#include "miscellaneous.h"
};

TEST(OrdinalTest, BasicAssertions) {
ASSERT_EQ(ordinal_((unsigned char) 0),"0th");
}