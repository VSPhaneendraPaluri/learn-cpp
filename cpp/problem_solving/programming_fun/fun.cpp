#include "fun.h"

#include <iostream>

uint8_t Fun::is_little_endian(uint32_t& input)
{
	uint8_t read_byte = 0x0;
	std::memcpy(&read_byte, reinterpret_cast<uint8_t*>(&input), 0x1);

	auto read_byte_2 = (*reinterpret_cast<char*>(&input));

	return read_byte & read_byte_2;
}

std::string Fun::print_double_quotes(const std::string& input)
{
	return '"' + input + '"';
}

std::tuple<uint32_t, uint32_t> Fun::variable_swap(uint32_t a, uint32_t b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	return std::make_tuple(a, b);
}
