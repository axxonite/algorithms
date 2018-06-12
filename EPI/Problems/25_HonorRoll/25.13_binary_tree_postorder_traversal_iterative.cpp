// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

vector<int> PostorderTraversal( const unique_ptr<BinaryTreeNode<int>>& tree )
{
	vector<int> result;
	return result;
}

#pragma region Test

template <typename T>
void GeneratePostorderHelper( const unique_ptr<BinaryTreeNode<T>>& r, vector<T>* ret ) 
{
	if ( r ) 
	{
		GeneratePostorderHelper( r->left, ret );
		GeneratePostorderHelper( r->right, ret );
		ret->emplace_back( r->data );
	}
}

template <typename T>
vector<T> GeneratePostorder( const unique_ptr<BinaryTreeNode<T>>& r ) 
{
	vector<T> ret;
	GeneratePostorderHelper( r, &ret );
	return ret;
}

void PostorderTraversalTest()
{
#if TEST
	//      3
	//    2   5
	//  1    4 6
	unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{3, nullptr, nullptr} );
	tree->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{2, nullptr, nullptr} );
	tree->left->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{1, nullptr, nullptr} );
	tree->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{5, nullptr, nullptr} );
	tree->right->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{4, nullptr, nullptr} );
	tree->right->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{6, nullptr, nullptr} );
	auto res = PostorderTraversal( tree ), golden_res = GeneratePostorder( tree );
	assert( equal( res.cbegin(), res.cend(), golden_res.cbegin(),
		golden_res.cend() ) );
#endif
}

#pragma endregion
