#pragma once

#include "Helpers.h"

#include <vector>

class InsertionSort
{
public:
	InsertionSort(std::vector<int32_t>& input);
	~InsertionSort() = default;

	std::vector<int32_t>& sort();
private:
	std::vector<int32_t> _input;
	Helpers _helper{};
};