#include "BitManipulations.h"

#include <gtest/gtest.h>

class TBitManipulations : public BitManipulations
	, public ::testing::Test
{
public:
	BitManipulations bitManipulations_;
};

TEST_F(TBitManipulations, test_check_if_the_ith_bit_is_set)
{
	uint32_t input = 0x12345678; // 0001-0010-0011-0100-0101-0110-0111-1000

	EXPECT_TRUE(bitManipulations_.isIthBitSet(input, 3));
	EXPECT_TRUE(bitManipulations_.isIthBitSet(input, 4));
	EXPECT_TRUE(bitManipulations_.isIthBitSet(input, 5));
	EXPECT_TRUE(bitManipulations_.isIthBitSet(input, 6));
	EXPECT_TRUE(bitManipulations_.isIthBitSet(input, 28));

	EXPECT_FALSE(bitManipulations_.isIthBitSet(input, 0));
	EXPECT_FALSE(bitManipulations_.isIthBitSet(input, 1));
	EXPECT_FALSE(bitManipulations_.isIthBitSet(input, 2));
}

TEST_F(TBitManipulations, test_set_ith_bit)
{
	uint32_t input = 0x04030201; // 0000-0100-0000-0011-0000-0010-0000-0001

	// Set 5th, 15th, 31st bit
	bitManipulations_.setIthBit(input, 5);
	bitManipulations_.setIthBit(input, 15);
	bitManipulations_.setIthBit(input, 31);

	EXPECT_TRUE(input && (1 << 5));
	EXPECT_TRUE(input && (1 << 15));
	EXPECT_TRUE(input && (1 << 31));
}

TEST_F(TBitManipulations, test_clear_ith_bit)
{
	uint32_t input = 0x04030201; // 0000-0100-0000-0011-0000-0010-0000-0001

	// clear 0th, 9th, 16th, 17th, 26th bits
	bitManipulations_.clearIthBit(input, 0);
	bitManipulations_.clearIthBit(input, 9);
	bitManipulations_.clearIthBit(input, 16);
	bitManipulations_.clearIthBit(input, 17);
	bitManipulations_.clearIthBit(input, 26);

	EXPECT_EQ(input, 0);
}

TEST_F(TBitManipulations, test_remove_the_last_set_bit_of_a_number)
{
	uint32_t input = 0x0403020E; // 0000-0100-0000-0011-0000-0010-0000-1110

	bitManipulations_.removeLastSetBit(input);

	EXPECT_EQ(input, 0x0403020C);
}

TEST_F(TBitManipulations, test_find_whether_a_number_is_even)
{
	uint32_t input = 0x0403020E; // 0000-0100-0000-0011-0000-0010-0000-1110

	EXPECT_TRUE(bitManipulations_.isGivenNumberEven(input));
}

TEST_F(TBitManipulations, test_find_whether_a_number_is_odd)
{
	uint32_t input = 0x0403020F; // 0000-0100-0000-0011-0000-0010-0000-1111

	EXPECT_TRUE(bitManipulations_.isGivenNumberOdd(input));
}

TEST_F(TBitManipulations, test_check_if_the_number_is_a_power_of_2)
{
	auto input1 = 0x0403020F; // 0000-0100-0000-0011-0000-0010-0000-1111
	auto input2 = 0x10; // 0000-0000-0000-0000-0000-0000-0001-0000

	EXPECT_FALSE(bitManipulations_.isGivenNumberPowerOf2(input1));
	EXPECT_TRUE(bitManipulations_.isGivenNumberPowerOf2(input2));
}

TEST_F(TBitManipulations, test_check_if_the_number_is_a_power_of_4)
{
	uint32_t input1 = 0x22; // 0000-0000-0000-0000-0000-0000-0010-0010
	uint32_t input2 = 0x10; // 0000-0000-0000-0000-0000-0000-0001-0000

	EXPECT_FALSE(bitManipulations_.isGivenNumberPowerOf4(input1));
	EXPECT_TRUE(bitManipulations_.isGivenNumberPowerOf4(input2));
}

TEST_F(TBitManipulations, test_check_if_the_number_is_a_power_of_8)
{
	uint32_t input1 = 8;  // 0000-0000-0000-0000-0000-0000-0000-1000
	uint32_t input2 = 64; // 0000-0000-0000-0000-0000-0000-0100-0000
	uint32_t input3 = 20; // 0000-0000-0000-0000-0000-0000-0010-0100

	EXPECT_TRUE(bitManipulations_.isGivenNumberPowerOf8(input1));
	EXPECT_TRUE(bitManipulations_.isGivenNumberPowerOf8(input2));
	EXPECT_FALSE(bitManipulations_.isGivenNumberPowerOf8(input3));
}

TEST_F(TBitManipulations, test_check_if_the_number_is_a_power_of_16)
{
	uint32_t input1 = 16;  // 0000-0000-0000-0000-0000-0000-0000-1000
	uint32_t input2 = 32; // 0000-0000-0000-0000-0000-0000-0100-0000
	uint32_t input3 = 256; // 0000-0000-0000-0000-0000-0000-0010-0100

	EXPECT_TRUE(bitManipulations_.isGivenNumberPowerOf16(input1));
	EXPECT_FALSE(bitManipulations_.isGivenNumberPowerOf16(input2));
	EXPECT_TRUE(bitManipulations_.isGivenNumberPowerOf16(input3));
}

TEST_F(TBitManipulations, test_toggle_ith_bit)
{
	uint32_t input = 0x12345678; // 0001-0010-0011-0100-0101-0110-0111-1000

	// Toggle 3rd bit position (bit position starts with 0)
	bitManipulations_.toggleIthBit(input, 3);
	EXPECT_EQ(input, 0x12345670);

	// Toggle 28th bit position (bit position starts with 0)
	bitManipulations_.toggleIthBit(input, 28);
	EXPECT_EQ(input, 0x02345670);
}

TEST_F(TBitManipulations, test_count_set_bits_in_a_given_number)
{
	uint32_t input = 0x12345678; // 0001-0010-0011-0100-0101-0110-0111-1000

	EXPECT_EQ(bitManipulations_.getSetBitsCount(input), 13);
}
