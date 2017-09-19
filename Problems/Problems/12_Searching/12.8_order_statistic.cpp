// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 1

// Partition A[left, right] around pivotIndex, returns the new index of the pivot, newPivotIndex, after partition. After partitioning, A[left, newPivotIndex - 1] contains elements that are greater than the pivot, and
// A[newPivotIndex + 1, right] contains elements that are less than the pivot.
// Note: "less than" is defined by the Compare object.
// Returns the new index of the pivot element after partition.
template <typename Compare>
int PartitionAroundPivot(int left, int right, int pivotIndex, Compare comp, vector<int>& a)
{
	int pivotVal = a[pivotIndex];
	int newPivotIndex = left;
	swap(a[pivotIndex], a[right]);
	for (int i = left; i < right; ++i)
		if (comp(a[i], pivotVal))
			swap(a[i], a[newPivotIndex++]);
	swap(a[right], a[newPivotIndex]);
	return newPivotIndex;
}

// The numbering starts from one for k.
template <typename Compare>
int FindKth(int k, Compare comp, vector<int>& a)
{
	int left = 0, right = a.size() - 1;
	default_random_engine gen((random_device())());
	while (left <= right)
	{
		// Generates a random integer in [left, right].
		int pivotIndex = uniform_int_distribution<int>{left, right}(gen);
		int newPivotIndex = PartitionAroundPivot(left, right, pivotIndex, comp, a);
		if (newPivotIndex == k - 1)
			return a[newPivotIndex];
		if (newPivotIndex > k - 1)
			right = newPivotIndex - 1;
		else
			left = newPivotIndex + 1; // new_pivot_idx < k - 1.
	}
	throw length_error("no k-th node in array A");
}

int FindKthLargest(int k, vector<int>& a)
{
	return FindKth(k, greater<int>(), a);
}

int FindKthSmallest(int k, vector<int>& a)
{
	return FindKth(k, less<int>(), a);
}

#pragma region Test

static void SimpleTestKthSmallest()
{
	vector<int> a = {3, 1, 2, 0, 4, 6, 5};
	assert(0 == FindKthSmallest(1, a));
	assert(1 == FindKthSmallest(2, a));
	assert(2 == FindKthSmallest(3, a));
	assert(3 == FindKthSmallest(4, a));
	assert(4 == FindKthSmallest(5, a));
	assert(5 == FindKthSmallest(6, a));
	assert(6 == FindKthSmallest(7, a));
	a[2] = 6;
	assert(6 == FindKthSmallest(6, a));
	assert(6 == FindKthSmallest(7, a));
	assert(5 == FindKthSmallest(5, a));

	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	// -7 0 0 3 4 4 6 10 12
	assert(-7 == FindKthSmallest(1, a));

	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(0 == FindKthSmallest(2, a));

	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(0 == FindKthSmallest(3, a));

	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(3 == FindKthSmallest(4, a));

	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(4 == FindKthSmallest(5, a));

	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(4 == FindKthSmallest(6, a));

	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(6 == FindKthSmallest(7, a));

	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(10 == FindKthSmallest(8, a));

	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(12 == FindKthSmallest(9, a));

	assert(4 == FindKthSmallest(6, a));
	for (int i = 0; i < a.size(); i++)
	{
		if (i < 4)
		{
			assert(a[i] < 4);
		}
		else if (i > 5)
		{
			assert(a[i] > 4);
		}
	}
}

static void SimpleTestKthLargest()
{
	vector<int> a = {3, 1, 2, 0, 4, 6, 5};
	assert(6 == FindKthLargest(1, a));
	assert(5 == FindKthLargest(2, a));
	assert(4 == FindKthLargest(3, a));
	assert(3 == FindKthLargest(4, a));
	assert(2 == FindKthLargest(5, a));
	assert(1 == FindKthLargest(6, a));
	assert(0 == FindKthLargest(7, a));
	a[2] = 6;
	assert(6 == FindKthLargest(1, a));
	assert(6 == FindKthLargest(2, a));
	assert(5 == FindKthLargest(3, a));

	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	// 12 10 6 4 4 3 0 0 -7
	assert(12 == FindKthLargest(1, a));
	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(10 == FindKthLargest(2, a));
	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(6 == FindKthLargest(3, a));
	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(4 == FindKthLargest(4, a));
	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(4 == FindKthLargest(5, a));
	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(3 == FindKthLargest(6, a));
	a = {0, -7, 3, 4, 4, 12, 6, 10, 0};
	assert(4 == FindKthLargest(5, a));
	for (int i = 0; i < a.size(); ++i)
	{
		if (i < 3)
		{
			assert(a[i] > 4);
		}
		else if (i > 4)
		{
			assert(a[i] < 4);
		}
	}
}

static void FindKthSimpleTest()
{
	vector<int> C = {9, 5};
	assert(9 == FindKthLargest(1, C));
	assert(5 == FindKthSmallest(1, C));

	vector<int> A = {123};
	assert(123 == FindKthLargest(1, A));
}

static void CheckOrderStatistic(int K, bool increasing_order,
                                vector<int>& a)
{
	vector<int> B(a);
	if (increasing_order)
	{
		FindKthSmallest(K, a);
	}
	else
	{
		FindKthLargest(K, a);
	}

	vector<int> B_sort(B);
	sort(B_sort.begin(), B_sort.end());
	if (!increasing_order)
	{
		reverse(B_sort.begin(), B_sort.end());
	}

	vector<int> A_sort(a);
	sort(A_sort.begin(), A_sort.end());
	if (!increasing_order)
	{
		reverse(A_sort.begin(), A_sort.end());
	}

	assert(equal(A_sort.begin(), A_sort.end(), B_sort.begin(), B_sort.end()));
}

static void TestAllOrders(const vector<int>& order, vector<int>& a)
{
	for (int K : order)
	{
		CheckOrderStatistic(K, true, a);
		CheckOrderStatistic(K, false, a);
	}
}

static void RandomTestFixedN(int N)
{
	vector<int> order;
	for (int i = 0; i < 5; ++i)
	{
		order.emplace_back(min(N, i + 1));
	}
	order.emplace_back(min(N, 7));
	order.emplace_back(min(N, 9));
	order.emplace_back(min(N, 12));
	order.emplace_back(min(N, max(N / 2 - 1, 1)));
	order.emplace_back(min(N, max(N / 2, 1)));
	order.emplace_back(min(N, N / 2 + 1));
	order.emplace_back(max(1, N - 1));
	order.emplace_back(N);

	vector<int> A;
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> dis(0, 9999999);
	for (int i = 0; i < N; ++i)
	{
		A.emplace_back(dis(gen));
	}
	TestAllOrders(order, A);

	A.clear();
	uniform_int_distribution<int> n_dis(0, N - 1);
	for (int i = 0; i < N; ++i)
	{
		A.emplace_back(n_dis(gen));
	}
	TestAllOrders(order, A);

	A.clear();
	uniform_int_distribution<int> n2_dis(0, 2 * N - 1);
	for (int i = 0; i < N; ++i)
	{
		A.emplace_back(n2_dis(gen));
	}
	TestAllOrders(order, A);

	A.clear();
	uniform_int_distribution<int> n_half_dis(0, max(N / 2, 1) - 1);
	for (int i = 0; i < N; ++i)
	{
		A.emplace_back(n_half_dis(gen));
	}
	TestAllOrders(order, A);
}

static void ComplexRandomTest()
{
	vector<int> N = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 50, 100};
	for (int i = 0; i < N.size(); ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			RandomTestFixedN(N[i]);
		}
	}
}

void FindKthTest()
{
#if TEST
	FindKthSimpleTest();
	SimpleTestKthLargest();
	SimpleTestKthSmallest();
	ComplexRandomTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		int n, k;
		uniform_int_distribution<int> n_dis(1, 100000);
		n = n_dis(gen);
		uniform_int_distribution<int> k_dis(1, n);
		k = k_dis(gen);
		vector<int> A;
		for (int i = 0; i < n; ++i)
		{
			uniform_int_distribution<int> dis(0, 9999999);
			A.emplace_back(dis(gen));
		}
		int result = FindKthLargest(k, A);
		nth_element(A.begin(), A.begin() + A.size() - k, A.end());
		assert(result == A[A.size() - k]);
	}
#endif
}

#pragma endregion Test
