#include <gtest/gtest.h>

using namespace ::testing;

class TestPatterns : public ::Test
{
};

TEST_F(TestPatterns, default_works) {
    EXPECT_EQ(0x2, (0x1 + 0x1));
}
