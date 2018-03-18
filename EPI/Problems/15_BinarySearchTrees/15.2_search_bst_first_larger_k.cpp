// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

BSTNode<int>* FindFirstGreaterThanK(const unique_ptr<BSTNode<int>>& tree, int k) 
{
	return nullptr;
}

#pragma region Test

void FindFirstGreaterThanKTest()
{
#if TEST
	//    3
	//  2   5
	// 1   4 7
	auto tree = make_unique<BSTNode<int>>(BSTNode<int>{3});
	tree->left = make_unique<BSTNode<int>>(BSTNode<int>{2});
	tree->left->left = make_unique<BSTNode<int>>(BSTNode<int>{1});
	tree->right = make_unique<BSTNode<int>>(BSTNode<int>{5});
	tree->right->left = make_unique<BSTNode<int>>(BSTNode<int>{4});
	tree->right->right = make_unique<BSTNode<int>>(BSTNode<int>{7});
	assert(FindFirstGreaterThanK(tree, 1) == tree->left.get());
	assert(FindFirstGreaterThanK(tree, 5) == tree->right->right.get());
	assert(FindFirstGreaterThanK(tree, 6) == tree->right->right.get());
	assert(!FindFirstGreaterThanK(tree, 7));
#endif
}

#pragma endregion Test
