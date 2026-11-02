#pragma once

#include "Helpers.h"

#include <stddef.h>
#include <vector>

class BubbleSort
{
public:
	BubbleSort(std::vector<int32_t> & v);
	~BubbleSort() = default;

	std::vector<int32_t>& sort();
private:
	std::vector<int32_t> _input;
	Helpers _helpers{};
};