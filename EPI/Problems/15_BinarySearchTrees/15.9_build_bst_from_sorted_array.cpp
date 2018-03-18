// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

unique_ptr<BSTNode<int>> BuildMinHeightBSTFromSortedArray(const vector<int>& A)
{
	return {};
}

#pragma region Test

template <typename T>
void TraversalCheck(const unique_ptr<BSTNode<T>>& tree, T* target)
{
	if (tree)
	{
		TraversalCheck(tree->left, target);
		assert(*target == tree->data);
		++*target;
		TraversalCheck(tree->right, target);
	}
}

static void BBuildMinHeightBSTFromSortedArraySimpleTest()
{
	vector<int> A = {1, 2, 3, 4};
	unique_ptr<BSTNode<int>> result = BuildMinHeightBSTFromSortedArray(A);
	assert(3 == result->data);
	assert(2 == result->left->data);
	assert(1 == result->left->left->data);
	assert(4 == result->right->data);
}

void BuildMinHeightBSTFromSortedArrayTest()
{
#if TEST
	BBuildMinHeightBSTFromSortedArraySimpleTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		int n;
		uniform_int_distribution<int> dis(1, 1000);
		n = dis(gen);
		vector<int> A(n);
		iota(A.begin(), A.end(), 0);
		unique_ptr<BSTNode<int>> tree = BuildMinHeightBSTFromSortedArray(A);
		int target = 0;
		TraversalCheck<int>(tree, &target);
	}
#endif
}

#pragma endregion Test
