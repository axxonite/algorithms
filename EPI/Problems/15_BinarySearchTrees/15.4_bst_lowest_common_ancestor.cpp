// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

// Input nodes are not nonempty and the key at a is less than or equal to that at b.
BSTNode<int>* FindLCA(const unique_ptr<BSTNode<int>>& tree, const unique_ptr<BSTNode<int>>& a, const unique_ptr<BSTNode<int>>& b)
{
	return nullptr;
}

#pragma region Test

void FindLCATest()
{
#if TEST
	unique_ptr<BSTNode<int>> tree = make_unique<BSTNode<int>>(BSTNode<int>{3});
	tree->left = make_unique<BSTNode<int>>(BSTNode<int>{2});
	tree->left->left = make_unique<BSTNode<int>>(BSTNode<int>{1});
	tree->right = make_unique<BSTNode<int>>(BSTNode<int>{5});
	tree->right->left = make_unique<BSTNode<int>>(BSTNode<int>{4});
	tree->right->right = make_unique<BSTNode<int>>(BSTNode<int>{6});
	assert(3 == FindLCA(tree, tree->left->left, tree->right->left)->data);
	assert(5 == FindLCA(tree, tree->right->left, tree->right->right)->data);
	assert(2 == FindLCA(tree, tree->left->left, tree->left)->data);
	assert(3 == FindLCA(tree, tree->left->left, tree->right)->data);
#endif
}

#pragma endregion Test
