#include "BubbleSort.h"

BubbleSort::BubbleSort(std::vector<int>& v)
	: _input(v)
{
	_helpers = Helpers();
}

std::vector<int>& BubbleSort::sort()
{
	for (auto i = 0; i < _input.size() - 2; i++) {
		for (auto i = 0; i < _input.size() - 1; i++) {
			if (_input[i] > _input[i + 1]) {
				_helpers.swap(_input, i, i + 1);
			}
			//_helpers.print(_input);
		}
	}
	return _input;
}

