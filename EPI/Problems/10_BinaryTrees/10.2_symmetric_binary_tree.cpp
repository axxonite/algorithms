// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

bool IsSymmetric( const unique_ptr<BinaryTreeNode<int>>& tree ) 
{
	return false;
}

#pragma region Test

void CheckSymmetricSimpleTest() {
	auto symm_tree = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	assert( IsSymmetric( symm_tree ) );
	symm_tree->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	assert( !IsSymmetric( symm_tree ) );
	symm_tree->right = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	assert( IsSymmetric( symm_tree ) );
	symm_tree->right->right =
		make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	assert( !IsSymmetric( symm_tree ) );
}

void CheckSymmetricTest()
{
#if TEST
	CheckSymmetricSimpleTest();
	// Non symmetric tree test.
	//      x
	//    x   x
	//  x    x x
	auto non_symm_tree = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	non_symm_tree->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	non_symm_tree->left->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	non_symm_tree->right = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	non_symm_tree->right->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	non_symm_tree->right->right = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	assert( !IsSymmetric( non_symm_tree ) );
	cout << boolalpha << IsSymmetric( non_symm_tree ) << endl;
	// Symmetric tree test.
	unique_ptr<BinaryTreeNode<int>> symm_tree = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	symm_tree->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	symm_tree->right = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>() );
	assert( IsSymmetric( symm_tree ) == true );
	cout << boolalpha << IsSymmetric( symm_tree ) << endl;
	// Empty tree test.
	symm_tree = nullptr;
	assert( IsSymmetric( symm_tree ) == true ); 
#endif
}

#pragma endregion
