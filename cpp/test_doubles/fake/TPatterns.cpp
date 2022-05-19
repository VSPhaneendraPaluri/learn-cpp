#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>
#include <regex>

using namespace ::testing;

class TestFakes : public ::Test
{
public:
  void SetUp() override
  {
  }
  const std::string input1_{"This is the first exercise.\n We have to learn many more regex patterns"};
  const std::string input2_{ "Today's date is 13th May, 2022" };
};

TEST_F(TestFakes, find_new_line_character) {
  EXPECT_EQ(0x1, (2 - 1));
  EXPECT_THAT(true, IsTrue());
}
