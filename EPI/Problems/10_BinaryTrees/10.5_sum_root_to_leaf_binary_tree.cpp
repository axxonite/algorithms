// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

int SumRootToLeaf( const unique_ptr<BinaryTreeNode<int>>& tree )
{
	return 0;
}

#pragma region Test

void SumRootToLeafTest()
{
#if TEST
	//      1
	//    1   0
	//  0    1 0
	unique_ptr<BinaryTreeNode<int>> root = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>{1, nullptr, nullptr} );
	assert( SumRootToLeaf( root ) == 1 );
	root->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1, nullptr, nullptr} );
	assert( SumRootToLeaf( root ) == 3 );
	root->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0, nullptr, nullptr} );
	assert( SumRootToLeaf( root ) == 6 );
	root->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0, nullptr, nullptr} );
	assert( SumRootToLeaf( root ) == 8 );
	root->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1, nullptr, nullptr} );
	assert( SumRootToLeaf( root ) == 11 );
	root->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0, nullptr, nullptr} );
#endif
}

#pragma endregion
