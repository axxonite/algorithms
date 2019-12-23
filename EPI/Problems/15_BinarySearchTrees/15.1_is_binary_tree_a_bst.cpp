// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"
#include "binary_tree_utils.h"

// #define TEST

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree)
{
	return false;
}

#pragma region Test

bool InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree, BinaryTreeNode<int>** prev)
{
	if (!tree)
		return true;
	if (!InorderTraversal(tree->left, prev))
		return false;
	if (*prev && (*prev)->data > tree->data)
		return false;
	*prev = tree.get();
	return InorderTraversal(tree->right, prev);
}

bool IsBinaryTreeBSTAlternative(const unique_ptr<BinaryTreeNode<int>>& tree)
{
	BinaryTreeNode<int>* prev = nullptr;
	return InorderTraversal(tree, &prev);
}

void IsBinaryTreeBSTSimpleTest()
{
	//      3
	//    2   5
	//  1    4 6
	auto tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3});
	tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2});
	tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1});
	tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5});
	tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4});
	tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6});
	// should output true.
	assert(IsBinaryTreeBST(tree) == true);
	assert(IsBinaryTreeBSTAlternative(tree) == true);
	//      10
	//    2   5
	//  1    4 6
	tree->data = 10;
	// should output false.
	assert(!IsBinaryTreeBST(tree));
	assert(!IsBinaryTreeBSTAlternative(tree));
	// should output true.
	assert(IsBinaryTreeBST(nullptr) == true);
	assert(IsBinaryTreeBSTAlternative(nullptr) == true);
}

void IsBinaryTreeBSTTest()
{
#ifdef TEST
	IsBinaryTreeBSTSimpleTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		int n;
		uniform_int_distribution<int> dis(0, 5);
		n = dis(gen);
		unique_ptr<BinaryTreeNode<int>> root =
			GenerateRandBinaryTree<int>(n, false);
		assert(IsBinaryTreeBST(root) == IsBinaryTreeBSTAlternative(root));
		DeleteBinaryTree(&root);
	}
#endif
}

#pragma endregion Test
