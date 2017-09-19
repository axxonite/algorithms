// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

vector<vector<int>> BinaryTreeDepthOrder(const unique_ptr<BinaryTreeNode<int>>& tree)
{
	vector<vector<int>> result;
	return result;
}
#pragma region Test

void BinaryTreeDepthOrderTest()
{
#if TEST
	//      3
	//    2   5
	//  1    4 6
	// 10
	// 13
	unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{3, nullptr, nullptr});
	tree->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{2, nullptr, nullptr});
	tree->left->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{1, nullptr, nullptr});
	tree->left->left->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{10, nullptr, nullptr});
	tree->left->left->left->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{13, nullptr, nullptr});
	tree->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{5, nullptr, nullptr});
	tree->right->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{4, nullptr, nullptr});
	tree->right->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{6, nullptr, nullptr});
	// should output 3
	//               2 5
	//               1 4 6
	//               10
	//               13
	auto result = BinaryTreeDepthOrder(tree);
	vector<vector<int>> golden_res = { { 3 },{ 2, 5 },{ 1, 4, 6 },{ 10 },{ 13 } };
	assert(equal(golden_res.begin(), golden_res.end(), result.begin(),
		result.end()));
#endif
}

#pragma endregion Test
