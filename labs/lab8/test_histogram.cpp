#include "histogram.h"

#include <gtest/gtest.h>
#include <iostream>

TEST(TestHistogram, CharCount) {
    std::stringstream ss{"aaabbcc"};
    Histogram h(ss);

    EXPECT_EQ(h.char_count('a'), 3);
    EXPECT_EQ(h.char_count('b'), 2);
    EXPECT_EQ(h.char_count('c'), 1);
    EXPECT_EQ(h.char_count('d'), 0);
}