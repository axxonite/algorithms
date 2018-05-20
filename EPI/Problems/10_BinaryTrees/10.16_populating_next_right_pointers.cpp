// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

template <typename T>
struct BinaryTreeNodeNext 
{
	T data;
	unique_ptr<BinaryTreeNodeNext<T>> left, right;
	BinaryTreeNodeNext<T>* next;  // Populates this field.
};

void ConstructRightSibling( BinaryTreeNodeNext<int>* tree ) 
{
}

#pragma region Test

void ConstructRightSiblingSimpleTest()
{
	//      3
	//    2   5
	unique_ptr<BinaryTreeNodeNext<int>> root = make_unique<BinaryTreeNodeNext<int>>(BinaryTreeNodeNext<int>{3, nullptr, nullptr, nullptr});
	root->left = make_unique<BinaryTreeNodeNext<int>>(BinaryTreeNodeNext<int>{2, nullptr, nullptr, nullptr});
	root->right = make_unique<BinaryTreeNodeNext<int>>(BinaryTreeNodeNext<int>{5, nullptr, nullptr, nullptr});
	ConstructRightSibling(root.get());
	assert(root->next == nullptr);
	assert(root->left->next == root->right.get());
	assert(root->right->next == nullptr);
}

void ConstructRightSiblingTest()
{
#if TEST
	ConstructRightSiblingSimpleTest();
	//      3
	//    2   5
	//  1  7 4 6
	unique_ptr<BinaryTreeNodeNext<int>> root = make_unique<BinaryTreeNodeNext<int>>(BinaryTreeNodeNext<int>{3, nullptr, nullptr, nullptr} );
	root->left = make_unique<BinaryTreeNodeNext<int>>(BinaryTreeNodeNext<int>{2, nullptr, nullptr, nullptr} );
	root->left->right = make_unique<BinaryTreeNodeNext<int>>(BinaryTreeNodeNext<int>{7, nullptr, nullptr, nullptr} );
	root->left->left = make_unique<BinaryTreeNodeNext<int>>(BinaryTreeNodeNext<int>{1, nullptr, nullptr, nullptr} );
	root->right = make_unique<BinaryTreeNodeNext<int>>(BinaryTreeNodeNext<int>{5, nullptr, nullptr, nullptr} );
	root->right->left = make_unique<BinaryTreeNodeNext<int>>(BinaryTreeNodeNext<int>{4, nullptr, nullptr, nullptr} );
	root->right->right = make_unique<BinaryTreeNodeNext<int>>(BinaryTreeNodeNext<int>{6, nullptr, nullptr, nullptr} );
	ConstructRightSibling( root.get() );
	assert( root->next == nullptr );
	assert( root->left->next == root->right.get() );
	assert( root->left->left->next == root->left->right.get() );
	assert( root->left->right->next == root->right->left.get() );
	assert( root->right->left->next == root->right->right.get() );
#endif
}

#pragma endregion
