#include "StringOperations.h"

#include <gtest/gtest.h>

class TStringOperations: public StringOperations
	, public ::testing::Test
{
public:
	StringOperations stringOperations_;
};

TEST_F(TStringOperations, test_convert_character_uppercase_to_lowercase)
{
	char ch = 'A';

	EXPECT_EQ(stringOperations_.convertCharacterUppercaseToLowercase(ch), 'a');
}

TEST_F(TStringOperations, test_convert_character_lowercase_to_uppercase)
{
	char ch = 'a';

	EXPECT_EQ(stringOperations_.convertCharacterLowercaseToUppercase(ch), 'A');
}

TEST_F(TStringOperations, test_invert_character_case)
{
	char ch1 = 'a';
	char ch2 = 'B';

	EXPECT_EQ(stringOperations_.invertCharacterCase(ch1), 'A');
	EXPECT_EQ(stringOperations_.invertCharacterCase(ch2), 'b');
}

TEST_F(TStringOperations, test_alphabet_position)
{
	char ch1 = 'a';
	char ch2 = 'B';

	EXPECT_EQ(stringOperations_.invertCharacterCase(ch1), 'A');
	EXPECT_EQ(stringOperations_.invertCharacterCase(ch2), 'b');
}
