#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

class TSortsFunctional : public testing::Test
{
};

TEST_F(TSortsFunctional, bubble_sort_functional_works)
{
	std::vector<int32_t> input{ 5, 6, 2, 4, 1, 8, 7 };
	std::vector<int32_t> expected{ 1, 2, 4, 5, 6, 7, 8 };
	BubbleSort bubbleSort(input);
	auto actual = bubbleSort.sort();
	EXPECT_THAT(actual, expected);
}

TEST_F(TSortsFunctional, selection_sort_functional_works)
{
	std::vector<int32_t> input{ 5, 6, 2, 4, 1, 8, 7 };
	std::vector<int32_t> expected{ 1, 2, 4, 5, 6, 7, 8 };
	SelectionSort selectionSort(input);
	auto actual = selectionSort.sort();
	EXPECT_THAT(actual, expected);
}

TEST_F(TSortsFunctional, insertion_sort_functional_works)
{
	std::vector<int32_t> input{ 5, 6, 2, 4, 1, 8, 7 };
	std::vector<int32_t> expected{ 1, 2, 4, 5, 6, 7, 8 };
	InsertionSort insertionSort(input);
	auto actual = insertionSort.sort();
	EXPECT_THAT(actual, expected);
}
