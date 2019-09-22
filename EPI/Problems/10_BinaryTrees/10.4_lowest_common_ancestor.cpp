// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

// #define TEST

BinaryTreeNodeP<int>* LCAParent( const unique_ptr<BinaryTreeNodeP<int>>& n0, const unique_ptr<BinaryTreeNodeP<int>>& n1 )
{
  return nullptr;
}

#pragma region Test

void LCAParentTest()
{
#ifdef TEST
	auto root = make_unique<BinaryTreeNodeP<int>>( BinaryTreeNodeP<int>{3, nullptr, nullptr, nullptr} );
	root->left = make_unique<BinaryTreeNodeP<int>>( BinaryTreeNodeP<int>{2, nullptr, nullptr, root.get()} );
	root->left->left = make_unique<BinaryTreeNodeP<int>>( BinaryTreeNodeP<int>{1, nullptr, nullptr, root->left.get()} );
	root->right = make_unique<BinaryTreeNodeP<int>>( BinaryTreeNodeP<int>{5, nullptr, nullptr, root.get()} );
	root->right->left = make_unique<BinaryTreeNodeP<int>>( BinaryTreeNodeP<int>{4, nullptr, nullptr, root->right.get()} );
	root->right->right = make_unique<BinaryTreeNodeP<int>>( BinaryTreeNodeP<int>{6, nullptr, nullptr, root->right.get()} );

	// should output 3
	assert( LCAParent( root->left, root->right )->data == 3 );
	cout << LCAParent( root->left, root->right )->data << endl;
	// should output 5
	assert( LCAParent( root->right->left, root->right->right )->data == 5 );
	cout << LCAParent( root->right->left, root->right->right )->data << endl;
	// should output 3
	assert( LCAParent( root->left, root->right->left )->data == 3 );
	cout << LCAParent( root->left, root->right->left )->data << endl;
	// should output 2
	assert( LCAParent( root->left, root->left->left )->data == 2 );
#endif
}

#pragma endregion
