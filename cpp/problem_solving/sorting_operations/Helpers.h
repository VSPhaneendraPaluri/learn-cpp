#pragma once

#include <vector>

class Helpers
{
public:
	Helpers() = default;
	~Helpers() = default;

	void swap(std::vector<int32_t>& input, uint32_t left, uint32_t right);
	void print(std::vector<int32_t>& input);
};