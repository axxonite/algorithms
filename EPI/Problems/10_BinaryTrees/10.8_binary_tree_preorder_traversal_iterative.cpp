// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

vector<int> PreorderTraversal( const unique_ptr<BinaryTreeNode<int>>& tree )
{
	return {};
}

#pragma region Test

template <typename T>
void GeneratePreorderHelper( const unique_ptr<BinaryTreeNode<T>>& r, vector<T>* ret ) {
	if ( r ) 
	{
		ret->emplace_back( r->data );
		GeneratePreorderHelper( r->left, ret );
		GeneratePreorderHelper( r->right, ret );
	}
}

template <typename T>
vector<T> GeneratePreorder( const unique_ptr<BinaryTreeNode<T>>& r ) 
{
	vector<T> ret;
	GeneratePreorderHelper( r, &ret );
	return ret;
}

void PreorderTraversalTest()
{
#if TEST
	//      3
	//    2   5
	//  1    4 6
	unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3, nullptr, nullptr} );
	tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2, nullptr, nullptr} );
	tree->left->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{1, nullptr, nullptr} );
	tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5, nullptr, nullptr} );
	tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4, nullptr, nullptr} );
	tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6, nullptr, nullptr} );
	auto res = PreorderTraversal( tree ), golden_res = GeneratePreorder( tree );
	assert( equal( res.cbegin(), res.cend(), golden_res.cbegin(), golden_res.cend() ) );
#endif
}

#pragma endregion