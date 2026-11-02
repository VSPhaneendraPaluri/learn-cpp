#include "Helpers.h"
#include <iostream>

void Helpers::print(std::vector<int32_t>& input)
{
	for (auto element : input) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

void Helpers::swap(std::vector<int32_t>& input, uint32_t left, uint32_t right)
{
	auto temp = input[left];
	input[left] = input[right];
	input[right] = temp;
}
