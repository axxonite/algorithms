#include "stdafx.h"
#include "Sorting.h"

using namespace std;

// --------------------------------------------------
// Insertion sort.
// O(n^2), but fast for small input sizes.
void InsertionSort(vector<int>& values)
{
	// Skip first value.
	for (auto i = 1; i < values.size(); i++)
	{
		auto value = values[i];
		// Insert into sorted sequence. We have to insert somewhere before j.
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
// Merge sort.
// O(n log n)
void Merge(vector<int>& values, int first, int pivot, int last)
{
	// Initialize the left and right arrays
	vector<int> left(values.begin() + first, values.begin() + pivot + 1); // Need iterator one past to include the element we want at the end.
	vector<int> right(values.begin() + pivot + 1, values.begin() + last + 1); // Same here.
	left.push_back(numeric_limits<int>::max());
	right.push_back(numeric_limits<int>::max());

	// Insert into destination array based on comparison based left and right sub-arrays.
	auto l = 0, r = 0;
	for (auto k = first; k <= last; k++)
		values[k] = left[l] < right[r] ? left[l++] : right[r++];
}

void MergeSort(vector<int>& values, int first, int last)
{
	if (first < last)
	{
		auto pivot = (first + last) / 2; // Choose pivot in the middle.
		// Divide and conquer.
		MergeSort(values, first, pivot);
		MergeSort(values, pivot + 1, last);
		// Merge the two sorted subarrays.
		Merge(values, first, pivot, last);
	}
}

void MergeSort(vector<int>& values)
{
	MergeSort(values, 0, values.size() - 1);
}

// --------------------------------------------------
// Quicksort
int Partition(vector<int>& values, int first, int last)
{
	auto pivotValue  = values[last];
	auto insertionPoint = first - 1;
	for (auto i = first; i < last; i++)
	{
		if (values[i] <= pivotValue) // Smaller than pivot
		{
			// Swap i with insertion point so i is in the left section
			insertionPoint++;
			swap(values[i], values[insertionPoint]);
		}
	}
	swap(values[last], values[insertionPoint + 1]);
	return insertionPoint + 1; // This is where the pivot value ended up at.
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

void Quicksort(vector<int>& values)
{
	Quicksort(values, 0, values.size() - 1);
}

// --------------------------------------------------
// Tests
vector<int> GenerateDistribution()
{
	vector<int> result;
	default_random_engine rnd;
	uniform_int_distribution<int> dis(0, std::numeric_limits<int>::max());
	for (auto i = 0; i < 1000; i++)
		result.push_back(dis(rnd));
	return result;
}

void ValidateSort(vector<int> input)
{
	for (auto i = 1; i < 1000; i++)
		assert(input[i] >= input[i - 1]);
}

void TestSorting()
{
	auto input = GenerateDistribution();
	InsertionSort(input);
	ValidateSort(input);
	input = GenerateDistribution();
	MergeSort(input);
	ValidateSort(input);
	input = GenerateDistribution();
	Quicksort(input);
	ValidateSort(input);
}
