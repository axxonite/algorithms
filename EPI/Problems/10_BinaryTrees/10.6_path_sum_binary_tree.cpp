// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

bool HasPathSum( const unique_ptr<BinaryTreeNode<int>>& tree, int targetWeight )
{
	return false;
}

#pragma region Test

void HasPathSumTest()
{
#if TEST
	unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3, nullptr, nullptr} );
	assert( HasPathSum( tree, 3 ) );
	tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2, nullptr, nullptr} );
	assert( HasPathSum( tree, 5 ) );
	tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1, nullptr, nullptr} );
	assert( HasPathSum( tree, 6 ) );
	tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5, nullptr, nullptr} );
	assert( HasPathSum( tree, 8 ) );
	assert( !HasPathSum( tree, 7 ) );
	tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4, nullptr, nullptr} );
	assert( HasPathSum( tree, 12 ) );
	assert( !HasPathSum( tree, 1 ) );
	assert( !HasPathSum( tree, 3 ) );
	assert( !HasPathSum( tree, 5 ) );
	tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6, nullptr, nullptr} );
	assert( HasPathSum( tree, 6 ) );
	assert( !HasPathSum( tree, 7 ) );
	assert( HasPathSum( tree, 14 ) );
	assert( !HasPathSum( tree, -1 ) );
	assert( !HasPathSum( tree, numeric_limits<int>::max() ) );
	assert( !HasPathSum( tree, numeric_limits<int>::min() ) );
#endif
}

#pragma endregion
