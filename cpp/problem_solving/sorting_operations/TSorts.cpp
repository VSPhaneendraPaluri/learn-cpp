#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <numeric>

class TSorts : public testing::Test
{
public:
	void generate_random_integer_vector(std::vector<int32_t>& input)
	{
		std::random_device random_device;
		std::mt19937 generator(random_device());
		std::uniform_int_distribution<int32_t> distribution{ std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::max() };
		auto generate_function = [&distribution, &generator]() {
			return distribution(generator);
			};
		std::generate(std::begin(input), std::end(input), generate_function);
	}
};

TEST_F(TSorts, bubble_sort)
{
	uint32_t size{ 10000 };
	std::vector<int32_t> input(size);
	std::chrono::steady_clock::time_point start, stop;

	generate_random_integer_vector(input);

	// Sort Random Array
	start = std::chrono::high_resolution_clock::now();
	BubbleSort bubbleSort1(input);
	stop = std::chrono::high_resolution_clock::now();
	auto random_sort = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	auto actual = bubbleSort1.sort();
	EXPECT_TRUE(std::is_sorted(actual.begin(), actual.end()));

	start = std::chrono::high_resolution_clock::now();
	BubbleSort bubbleSort2(actual);
	stop = std::chrono::high_resolution_clock::now();
	auto sorted_sort = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::reverse(actual.begin(), actual.end());
	start = std::chrono::high_resolution_clock::now();
	BubbleSort bubbleSort3(actual);
	stop = std::chrono::high_resolution_clock::now();
	auto reverse_sorted_sort = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "---- Bubble Sort ----" << std::endl
		<< "Random: " << random_sort.count()
		<< ", Sorted: " << sorted_sort.count()
		<< ", Reverse Sorted: " << reverse_sorted_sort.count()
		<< std::endl;
}

TEST_F(TSorts, selection_sort)
{
	uint32_t size{ 10000 };
	std::vector<int32_t> input(size);
	std::chrono::steady_clock::time_point start, stop;

	generate_random_integer_vector(input);

	// Sort Random Array
	start = std::chrono::high_resolution_clock::now();
	SelectionSort selectionSort1(input);
	stop = std::chrono::high_resolution_clock::now();
	auto random_sort = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	auto actual = selectionSort1.sort();
	EXPECT_TRUE(std::is_sorted(actual.begin(), actual.end()));

	start = std::chrono::high_resolution_clock::now();
	SelectionSort selectionSort2(actual);
	stop = std::chrono::high_resolution_clock::now();
	auto sorted_sort = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::reverse(actual.begin(), actual.end());
	start = std::chrono::high_resolution_clock::now();
	SelectionSort selectionSort3(actual);
	stop = std::chrono::high_resolution_clock::now();
	auto reverse_sorted_sort = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "---- Selection Sort ----" << std::endl
		<< "Random: " << random_sort.count()
		<< ", Sorted: " << sorted_sort.count()
		<< ", Reverse Sorted: " << reverse_sorted_sort.count() 
		<< std::endl;
}

TEST_F(TSorts, insertion_sort)
{
	uint32_t size{ 10000 };
	std::vector<int32_t> input(size);
	std::chrono::steady_clock::time_point start, stop;

	generate_random_integer_vector(input);

	// Sort Random Array
	start = std::chrono::high_resolution_clock::now();
	InsertionSort insertionSort1(input);
	stop = std::chrono::high_resolution_clock::now();
	auto random_sort = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	auto actual = insertionSort1.sort();
	EXPECT_TRUE(std::is_sorted(actual.begin(), actual.end()));

	start = std::chrono::high_resolution_clock::now();
	InsertionSort insertionSort2(actual);
	stop = std::chrono::high_resolution_clock::now();
	auto sorted_sort = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::reverse(actual.begin(), actual.end());
	start = std::chrono::high_resolution_clock::now();
	InsertionSort insertionSort3(actual);
	stop = std::chrono::high_resolution_clock::now();
	auto reverse_sorted_sort = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "---- Insertion Sort ----" << std::endl
		<< "Random: " << random_sort.count()
		<< ", Sorted: " << sorted_sort.count()
		<< ", Reverse Sorted: " << reverse_sorted_sort.count()
		<< std::endl;
}
