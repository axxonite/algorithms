// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

// #define TEST

vector<int> InorderTraversal( const unique_ptr<BinaryTreeNodeP<int>>& tree ) 
{
	vector<int> result;
	return result;
}

#pragma region Test

void InorderTraversalTest()
{
#ifdef TEST
	//      3
	//    2   5
	//  1    4 6
	unique_ptr<BinaryTreeNodeP<int>> root = make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{3, nullptr, nullptr} );
	root->parent = nullptr;
	auto result = InorderTraversal( root );
	vector<int> golden_res = { 3 };
	assert( equal( golden_res.begin(), golden_res.end(), result.begin(), result.end() ) );

	root->left = make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{2, nullptr, nullptr} );
	root->left->parent = root.get();
	root->left->left = make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{1, nullptr, nullptr} );
	root->left->left->parent = root->left.get();
	result = InorderTraversal( root );
	golden_res = { 1, 2, 3 };
	assert( equal( golden_res.begin(), golden_res.end(), result.begin(), result.end() ) );

	root->right = make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{5, nullptr, nullptr} );
	root->right->parent = root.get();
	root->right->left = make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{4, nullptr, nullptr} );
	root->right->left->parent = root->right.get();
	root->right->right = make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{6, nullptr, nullptr} );
	root->right->right->parent = root->right.get();

	result = InorderTraversal( root );
	golden_res = { 1, 2, 3, 4, 5, 6 };
	assert( equal( golden_res.begin(), golden_res.end(), result.begin(),
		result.end() ) );
#endif
}

#pragma endregion