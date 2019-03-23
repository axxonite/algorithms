#include "stdafx.h"
#include "SortingAlgorithms.h"
#include "MaxHeap.h"

using namespace std;

// --------------------------------------------------
// Bubble sort.
// O(n^2).
void BubbleSort(vector<int>& a)
{
	// Outer loop: iterate every element.
	for (auto i = 0; i < a.size(); i++)
	{
		// Inner loop: iterate elements from n-1 down to i+1
		for (auto j = a.size() - 1; j > i; j--)
		{
			// Swap the contiguous elements if they're in the wrong order.
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}

// --------------------------------------------------
// Insertion sort.
// O(n^2), but fast for small input sizes. Go through each value and insert in its appropriate location in the array.
void InsertionSort(vector<int>& values)
{
	// Skip first value.
	for (auto i = 1; i < values.size(); i++)
	{
		auto value = values[i];
		// Insert into sorted sequence. We have to insert somewhere before i.
		auto insertionPoint = i - 1;
		while (insertionPoint >= 0 && values[insertionPoint] > value)
		{
			values[insertionPoint + 1] = values[insertionPoint]; // Push values forward until the insertion point is <= key
			insertionPoint--;
		}
		values[insertionPoint + 1] = value;
	}
}

// --------------------------------------------------
// Selection sort.
// O(n^2)?

// ??????

// --------------------------------------------------
// Merge sort. Subdivide int two subarrays recursively which will create hierarchy of smaller, sorted subarrays down to size 1, then compare the entries of each sub array to merge them. 
// O(n log n)
void Merge(vector<int>& values, int first, int pivot, int last)
{
	vector<int> left(values.begin() + first, values.begin() + pivot);
	vector<int> right(values.begin() + pivot, values.begin() + last);
	left.push_back(numeric_limits<int>::max());
	right.push_back(numeric_limits<int>::max());

	// Insert into destination array based on comparison based left and right sub-arrays.
	auto l = 0, r = 0;
	for (auto i = first; i <= last; i++)
		values[i] = left[l] < right[r] ? left[l++] : right[r++];
}

void MergeSort(vector<int>& values, int first, int last)
{
	if (first < last)
	{
		auto pivot = (first + last) / 2; // Choose pivot in the middle.
		MergeSort(values, first, pivot); // Divide and conquer.
		MergeSort(values, pivot, last);
		Merge(values, first, pivot, last); // Merge the two sorted subarrays.
	}
}

void MergeSort(vector<int>& values)
{
	MergeSort(values, 0, values.size());
}

// --------------------------------------------------
// Quicksort - pick a key value, classify with respect to the key values as < or >, then run again on each < and > classication.
// O(n lg n)
int Partition(vector<int>& values, int first, int last)
{
	auto keyValue  = values[last];
	auto insertionPoint = first - 1;
	for (auto i = first; i < last; i++)
	{
		if (values[i] <= keyValue)
		{
			// Swap i with insertion point so i is in the left section
			insertionPoint++;
			swap(values[i], values[insertionPoint]);
		}
	}
	swap(values[last], values[insertionPoint + 1]);
	return insertionPoint + 1; // This is where the key value ended up at.
}

void Quicksort(vector<int>& values, int start, int end)
{
	if ( start < end )
	{
		auto pivotIndex = Partition(values, start, end);
		Quicksort(values, start, pivotIndex - 1);
		Quicksort(values, pivotIndex, end);
	}
}

void BalancedQuicksort(vector<int>& values, int start, int end)
{
	if (start < end)
	{
		// Swap the last entry with a random pivot so that we may get a balanced distribution regardless of input data.
		default_random_engine rnd;
		uniform_int_distribution<int> dis(start, end + 1);
		auto randomPivot = dis(rnd);
		swap(values[end], values[randomPivot]);
		auto pivotIndex = Partition(values, start, end);
		Quicksort(values, start, pivotIndex - 1);
		Quicksort(values, pivotIndex, end);
	}
}

void Quicksort(vector<int>& values)
{
	Quicksort(values, 0, values.size() - 1);
}

void BalancedQuicksort(vector<int>& values)
{
	BalancedQuicksort(values, 0, values.size() - 1);
}

// --------------------------------------------------
// Counting sort. O(n). Stable. Count the number of occurrences of each possible value, then add up a sum of the number of occurrences less than i for every i. Then build the destination array by running though
// from the highest to the lowest values, and inserting as many occurrences as there were in the input array.
vector<int> CountingSort(vector<int> values, int maxValue)
{
	vector<int> counts(maxValue + 1);
	vector<int> result(values.size());
	for (auto i = 0; i < values.size(); i++)
		counts[values[i]]++;
	for (auto i = 1; i < counts.size(); i++)
		counts[i] = counts[i] + counts[i - 1];
	// counts now contains the number of elements less than or equal to i for each possible value.
	for (int i = values.size() - 1; i >= 0; i--)
	{
		result[counts[values[i]] - 1] = values[i]; // SUbtract one, because when there is only one occurrence of the lowest value left, it must be inserted at position 0.
		counts[values[i]]--;
	}
	return result;
}

// Radix sort. O(n). Do a counting sort on each successive digit, starting from the lowest digit. This effectively categories the numbers in a hierarchy of digits from highest value to lowest value digits.
vector<int> RadixSort(vector<int> values, int maxDigits)
{
	vector<int> result(values.size());
	auto divider = 1;
	for ( auto d = 0; d < maxDigits; d++)
	{
		vector<int> counts(11);
		for (auto i = 0; i < values.size(); i++)
			counts[(values[i] / divider) % 10]++;
		for (auto i = 1; i < counts.size(); i++)
			counts[i] = counts[i] + counts[i - 1];
		// counts now contains the number of elements less than or equal to i for each possible value.
		for (int i = values.size() - 1; i >= 0; i--)
		{
			auto digit = (values[i] / divider) % 10;
			result[counts[digit] - 1] = values[i]; // Subtract one, because when there is only one occurrence of the lowest value left, it must be inserted at position 0.
			counts[digit]--;
		}
		values = result;
		divider *= 10;
	}
	return result;
}

// --------------------------------------------------
// Select the kth smallest value. k starts from zero. O(n ^ 2) worst case, O(n) expected. The run time analysis for this one is complex.
int SelectOrderStatistic(vector<int> values, int first, int last, int order)
{
	if (first == last)
		return values[first];
	auto pivot = Partition(values, first, last);
	auto k = pivot - first;
	if (order == k)
		return values[pivot]; // The pivot value is the answer.
	else if (order < k)
		return SelectOrderStatistic(values, first, pivot - 1, order);
	return SelectOrderStatistic(values, pivot + 1, last, order - k - 1); // - 1 on k since the pivot has +1
}

int SelectOrderStatistic(vector<int> values, int order)
{
	return SelectOrderStatistic(values, 0, values.size() - 1, order);
}

// --------------------------------------------------
// Tests
vector<int> GenerateDistribution(int max = numeric_limits<int>::max())
{
	vector<int> result;
	default_random_engine rnd;
	uniform_int_distribution<int> dis(0, max);
	for (auto i = 0; i < 1000; i++)
		result.push_back(dis(rnd));
	return result;
}

void ValidateSort(vector<int> input)
{
	for (auto i = 1; i < 1000; i++)
		assert(input[i] >= input[i - 1]);
}

void TestOrderStatistic()
{
	auto input = GenerateDistribution();
	auto result = SelectOrderStatistic(input, 500);
	auto lessThan = 0;
	for (auto i = 0; i < 1000; i++)
		if (input[i] < result)
			lessThan++;
	assert(lessThan == 500);
}

void TestSortingAlgorithms()
{
	auto input = GenerateDistribution();
	InsertionSort(input);
	ValidateSort(input);
	input = GenerateDistribution();
	MergeSort(input);
	ValidateSort(input);
	input = GenerateDistribution();
	Heapsort(input);
	ValidateSort(input);
	input = GenerateDistribution();
	Quicksort(input);
	ValidateSort(input);
	input = GenerateDistribution();
	BalancedQuicksort(input);
	ValidateSort(input);
	input = GenerateDistribution(100);
	input = CountingSort(input, 100);
	ValidateSort(input);
	input = GenerateDistribution(10000);
	input = RadixSort(input, 5);
	ValidateSort(input);
	TestOrderStatistic();
}