// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Merge two sorted subarrays A[start, mid - 1] and A[mid, end - 1] into A[start, end - 1] and return the number of inversions across A[start, mid -1] and A[mid, end - 1].
	int MergeSortAndCountInversionsAcrossSubarrays(int start, int mid, int end, vector<int>* A_ptr)
	{
		vector<int> sorted_A;
		int left_start = start, right_start = mid, inversion_count = 0;

		vector<int>& A = *A_ptr;
		while (left_start < mid && right_start < end)
		{
			if (A[left_start] <= A[right_start])
				sorted_A.emplace_back(A[left_start++]);
			else
			{
				// A[left_start, mid - 1] are the inversions of A[right_start].
				inversion_count += mid - left_start;
				sorted_A.emplace_back(A[right_start++]);
			}
		}
		copy(A.begin() + left_start, A.begin() + mid, back_inserter(sorted_A));
		copy(A.begin() + right_start, A.begin() + end, back_inserter(sorted_A));

		// Updates A with sorted_A.
		copy(sorted_A.begin(), sorted_A.end(), A.begin() + start);
		return inversion_count;
	}

	// Return the number of inversions in (*A_ptr)[start, end - 1].
	int CountSubarrayInversions(int start, int end, vector<int>* A_ptr)
	{
		if (end - start <= 1)
			return 0;

		int mid = start + (end - start) / 2;
		return CountSubarrayInversions(start, mid, A_ptr) + CountSubarrayInversions(mid, end, A_ptr) + MergeSortAndCountInversionsAcrossSubarrays(start, mid, end, A_ptr);
	}

	int CountInversions(vector<int> A)
	{
		return CountSubarrayInversions(0, A.size(), &A);
	}
}