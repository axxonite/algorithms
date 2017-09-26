// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

#define TEST 0

BinaryTreeNodeP<int>* LCA2(const unique_ptr<BinaryTreeNodeP<int>>& node0, const unique_ptr<BinaryTreeNodeP<int>>& node1)
{
	return nullptr;
}

#pragma region Test

void LCA2Test()
{
#if TEST
	//      3
	//    2   5
	//  1    4 6
	unique_ptr<BinaryTreeNodeP<int>> root = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{3, nullptr, nullptr});
	root->parent = nullptr;
	root->left = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{2, nullptr, nullptr});
	root->left->parent = root.get();
	root->left->left = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{1, nullptr, nullptr});
	root->left->left->parent = root->left.get();
	root->right = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{5, nullptr, nullptr});
	root->right->parent = root.get();
	root->right->left = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{4, nullptr, nullptr});
	root->right->left->parent = root->right.get();
	root->right->right = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{6, nullptr, nullptr});
	root->right->right->parent = root->right.get();

	// should output 3
	assert(LCA2(root->left, root->right)->data == 3);
	cout << (LCA2(root->left, root->right))->data << endl;
	// should output 5
	assert(LCA2(root->right->left, root->right->right)->data == 5);
	cout << (LCA2(root->right->left, root->right->right)->data) << endl;
#endif
}

#pragma endregion Test
