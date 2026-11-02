#pragma once

#include <stdint.h>
#include <string>
#include <tuple>

class Fun
{
public:
	uint8_t is_little_endian(uint32_t& input);
	std::string print_double_quotes(const std::string& input);
	std::tuple<uint32_t, uint32_t> variable_swap(uint32_t a, uint32_t b);
};

template<typename Base, typename Derived>
bool is_derived_from(Base b, Derived d)
{
	return std::is_base_of<Base, Derived>::value;
}
