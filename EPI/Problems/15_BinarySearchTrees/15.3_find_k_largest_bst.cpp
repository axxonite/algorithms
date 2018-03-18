// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<int> FindKLargestInBST(const unique_ptr<BSTNode<int>>& tree, int k)
{
	return {};
}

#pragma region Test

void FindKLargestInBSTTest()
{
#if TEST
	//    3
	//  2   5
	// 1   4 6
	unique_ptr<BSTNode<int>> tree = make_unique<BSTNode<int>>(BSTNode<int>{3});
	tree->left = make_unique<BSTNode<int>>(BSTNode<int>{2});
	tree->left->left = make_unique<BSTNode<int>>(BSTNode<int>{1});
	tree->right = make_unique<BSTNode<int>>(BSTNode<int>{5});
	tree->right->left = make_unique<BSTNode<int>>(BSTNode<int>{4});
	tree->right->right = make_unique<BSTNode<int>>(BSTNode<int>{6});
	default_random_engine gen((random_device())());
	int k;
	uniform_int_distribution<int> dis(1, 6);
	k = dis(gen);
	cout << "k = " << k << endl;
	vector<int> ans = FindKLargestInBST(tree, k);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
	for (int i = 1; i < ans.size(); ++i)
	{
		assert(ans[i - 1] >= ans[i]);
	}
	ans = FindKLargestInBST(tree, 2);
	assert(ans[0] == 6);
	assert(ans[1] == 5);

	//    3
	//  3   4
	// 1   4 6
	tree = make_unique<BSTNode<int>>(BSTNode<int>{3});
	tree->left = make_unique<BSTNode<int>>(BSTNode<int>{3});
	tree->left->left = make_unique<BSTNode<int>>(BSTNode<int>{1});
	tree->right = make_unique<BSTNode<int>>(BSTNode<int>{4});
	tree->right->left = make_unique<BSTNode<int>>(BSTNode<int>{4});
	tree->right->right = make_unique<BSTNode<int>>(BSTNode<int>{6});
	ans = FindKLargestInBST(tree, 3);
	assert(ans[0] == 6);
	assert(ans[1] == 4);
	assert(ans[1] == 4);
#endif
}

#pragma endregion Test