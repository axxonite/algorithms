// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

list<const unique_ptr<BinaryTreeNode<int>>*> CreateListOfLeaves(const unique_ptr<BinaryTreeNode<int>>& t)
{
	list<const unique_ptr<BinaryTreeNode<int>>*> result;
	return result;
}

#pragma region Test

void CreateListOfLeavesTest()
{
#if TEST
	//      3
	//    2   5
	//  1    4 6
	unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3, nullptr, nullptr} );
	tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2, nullptr, nullptr} );
	auto L = CreateListOfLeaves( tree );
	assert( L.size() == 1 && ( *L.front() )->data == 2 );

	tree->left->left = make_unique<BinaryTreeNode<int>>( BinaryTreeNode<int>{1, nullptr, nullptr} );
	tree->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{5, nullptr, nullptr} );
	tree->right->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{4, nullptr, nullptr} );
	tree->right->right = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{6, nullptr, nullptr} );
	L = CreateListOfLeaves( tree );
	list<int> output;
	// should output 1, 4, 6
	for ( const auto* l : L ) 
	{
		output.push_back( ( *l )->data );
		cout << ( *l )->data << endl;
	}
	list<int> golden_res = { 1, 4, 6 };
	assert( equal( output.begin(), output.end(), golden_res.begin(), golden_res.end() ) );
#endif
}

#pragma endregion