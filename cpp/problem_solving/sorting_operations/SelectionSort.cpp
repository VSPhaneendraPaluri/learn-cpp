#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<int32_t>& input)
	: _input(input)
{
}

std::vector<int32_t>& SelectionSort::sort()
{
	for (auto i = 0; i < _input.size() - 1; i++) {
		int32_t min = _input[i];
		auto index = i;
		for (auto j = i; j < _input.size(); j++) {
			if (min > _input[j]) {
				min = _input[j];
				index = j;
			}
		}
		_helper.swap(_input, i, index);
		//_helper.print(_input);
	}
	return _input;
}


