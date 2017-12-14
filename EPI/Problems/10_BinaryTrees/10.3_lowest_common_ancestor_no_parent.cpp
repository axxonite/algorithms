// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& tree, const unique_ptr<BinaryTreeNode<int>>& node0, const unique_ptr<BinaryTreeNode<int>>& node1)
{
	return nullptr;
}

#pragma region Test

void LCATest()
{
#if TEST
	//      3
	//    2   5
	//  1    4 6
	unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{3, nullptr, nullptr});
	tree->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{2, nullptr, nullptr});
	tree->left->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{1, nullptr, nullptr});
	tree->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{5, nullptr, nullptr});
	tree->right->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{4, nullptr, nullptr});
	tree->right->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{6, nullptr, nullptr});
	// should output 3
	auto* x = LCA(tree, tree->left, tree->right);
	assert(x->data == 3);
	cout << x->data << endl;
	// should output 5
	x = LCA(tree, tree->right->left, tree->right->right);
	assert(x->data == 5);
	cout << x->data << endl;
	// should output 5
	x = LCA(tree, tree->right, tree->right->right);
	assert(x->data == 5);
	cout << x->data << endl;
	// should output 3
	x = LCA(tree, tree->left->left, tree->right->right);
	assert(x->data == 3);
	cout << x->data << endl;
	// should output 3
	x = LCA(tree, tree->left->left, tree);
	assert(x->data == 3);
	cout << x->data << endl;
	// should output 2
	x = LCA(tree, tree->left, tree->left);
	assert(x->data == 2);
	cout << x->data << endl;
#endif
}

#pragma endregion Test
