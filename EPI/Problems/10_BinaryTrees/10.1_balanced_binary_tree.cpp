// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

// #define TEST

bool IsBalanced( const unique_ptr<BinaryTreeNode<int>>& tree )
{
	return true;
}

#pragma region Test

void IsBalancedTest()
{
#ifdef TEST
	unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	tree->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	tree->left->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	tree->right = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	tree->right->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	tree->right->right = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	assert( IsBalanced( tree ) == true );
	cout << boolalpha << IsBalanced( tree ) << endl;
	// Non-balanced binary tree test.
	tree = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	tree->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	tree->left->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	assert( IsBalanced( tree ) == false );
#endif
}

#pragma endregion