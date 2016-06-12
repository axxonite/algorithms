#include "stdafx.h"
#include "Sorting.h"

int Partition(int* in, int first, int last)
{
	auto pivotValue  = in[last];
	auto insertionPoint = first - 1;
	for (auto i = first; i < last; i++)
	{
		if (in[i] <= pivotValue) // Smaller than pivot
		{
			insertionPoint++;
			// Swap i with insertion point so i is in the left section
			auto temp = in[i];
			in[i] = in[insertionPoint];
			in[insertionPoint] = temp;
		}
	}
	in[last] = in[insertionPoint + 1];
	in[insertionPoint + 1] = pivotValue; // Pivot value came from in[insertionPoint + 1]
	return insertionPoint + 1; // This is where the pivot value ended up at.
}

void Quicksort(int* in, int start, int end)
{
	if ( start < end )
	{
		auto pivotIndex = Partition(in, start, end);
		Quicksort(in, start, pivotIndex - 1);
		Quicksort(in, pivotIndex, end);
	}
}

void Quicksort(int* in, int count)
{
	Quicksort(in, 0, count - 1);
}

void TestSorting()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int<int> dis(0, std::numeric_limits<int>::max());
	int input[1000];
	for (auto i = 0; i < 1000; i++)
		input[i] = dis(gen);
	Quicksort(input, 1000);
	for (auto i = 1; i < 1000; i++)
		assert(input[i] >= input[i - 1]);
}