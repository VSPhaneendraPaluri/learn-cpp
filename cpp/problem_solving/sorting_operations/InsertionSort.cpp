#include "InsertionSort.h"

InsertionSort::InsertionSort(std::vector<int32_t>& input)
    : _input(input)
{
}

std::vector<int32_t>& InsertionSort::sort()
{
    for (auto i = 1; i < _input.size(); i++) {
        int32_t pivot = _input[i];
        auto index = i - 1;
        while ((index >= 0) && (_input[index] > pivot)) {
            _input[index + 1] = _input[index];
            index--;
        }
        _input[index + 1] = pivot;
        //_helper.print(_input);
    }
    return _input;
}
