#include "fun.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>

class TestProgrammingFun : public ::testing::Test
{
public:
	Fun fun_obj;
};

TEST_F(TestProgrammingFun, test_identify_little_endian)
{
	uint32_t input = 0x01020304; // 00000001-00000002-00000003-00000004
	auto return_val = fun_obj.is_little_endian(input);
	EXPECT_THAT(return_val, 0x04);
}

TEST_F(TestProgrammingFun, test_print_double_quotes)
{
	EXPECT_THAT("\"FUN-PROGRAMMING\"", fun_obj.print_double_quotes("FUN-PROGRAMMING"));
}

TEST_F(TestProgrammingFun, test_variable_swap)
{
	uint32_t a = 100, b = 200;
	auto return_val = fun_obj.variable_swap(a, b);
	EXPECT_THAT(std::get<0>(return_val), 200);
	EXPECT_THAT(std::get<1>(return_val), 100);
}

TEST_F(TestProgrammingFun, test_is_derived_from)
{
	class B {};
	class D : public B {};

	B b;
	D d;
	auto return_val = is_derived_from<B, D>(b, d);

	EXPECT_TRUE(return_val);
}