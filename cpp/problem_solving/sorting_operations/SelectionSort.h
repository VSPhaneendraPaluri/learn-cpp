#pragma once

#include "Helpers.h"

#include <vector>

class SelectionSort
{
public:
	SelectionSort(std::vector<int32_t>& input);
	~SelectionSort() = default;

	std::vector<int32_t>& sort();
private:
	Helpers _helper{};
	std::vector<int32_t> _input;
};