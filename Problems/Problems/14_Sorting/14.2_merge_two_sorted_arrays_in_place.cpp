// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

void MergeTwoSortedArrays(int A[], int m, int B[], int n)
{
}

#pragma region Test

void MergeTwoSortedArraysCheckAns(const vector<int>& A)
{
	for (size_t i = 1; i < A.size(); ++i)
		assert(A[i - 1] <= A[i]);
}

void MergeTwoSortedArraysTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 100; ++times) {
		size_t m, n;
			uniform_int_distribution<size_t> size_dis(0, 10000);
			m = size_dis(gen), n = size_dis(gen);
		uniform_int_distribution<int> dis(-(m + n), m + n);
		vector<int> A(m + n), B;
		for (size_t i = 0; i < m; ++i) {
			A[i] = dis(gen);
		}
		generate_n(back_inserter(B), n, [&] { return dis(gen); });
		sort(A.begin(), A.begin() + m), sort(B.begin(), B.end());
		MergeTwoSortedArrays(A.data(), m, B.data(), n);
		MergeTwoSortedArraysCheckAns(A);
	}
#endif
}

#pragma endregion Test
