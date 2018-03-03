// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

template <typename T>
struct BinaryTreeNodeWithSize 
{
	T data;
	unique_ptr<BinaryTreeNodeWithSize<T>> left, right;
	int size;
};

const BinaryTreeNodeWithSize<int>* FindKthNodeBinaryTree( const unique_ptr<BinaryTreeNodeWithSize<int>>& tree, int k )
{
	return nullptr;
}

#pragma region Test

void FindKthNodeBinaryTreeTest()
{
#if TEST
	//  size field
	//      6
	//    2   3
	//  1    1 1
	//
	//  data field
	//      3
	//    2   5
	//  1    4 6
	auto root = make_unique<BinaryTreeNodeWithSize<int>>( BinaryTreeNodeWithSize<int>() );
	root->size = 6;
	root->data = 3;
	root->left = make_unique<BinaryTreeNodeWithSize<int>>( BinaryTreeNodeWithSize<int>() );
	root->left->size = 2;
	root->left->data = 2;
	root->left->left = make_unique<BinaryTreeNodeWithSize<int>>( BinaryTreeNodeWithSize<int>() );
	root->left->left->size = 1;
	root->left->left->data = 1;
	root->right = make_unique<BinaryTreeNodeWithSize<int>>( BinaryTreeNodeWithSize<int>() );
	root->right->size = 3;
	root->right->data = 5;
	root->right->left = make_unique<BinaryTreeNodeWithSize<int>>( BinaryTreeNodeWithSize<int>() );
	root->right->left->size = 1;
	root->right->left->data = 4;
	root->right->right = make_unique<BinaryTreeNodeWithSize<int>>( BinaryTreeNodeWithSize<int>() );
	root->right->right->size = 1;
	root->right->right->data = 6;
	// 0th node does not exist - leftmost node is node 1
	assert( nullptr == FindKthNodeBinaryTree( root, 0 ) );
	// should output 1
	assert( FindKthNodeBinaryTree( root, 1 )->data == 1 );
	cout << ( FindKthNodeBinaryTree( root, 1 ) )->data << endl;
	// should output 2
	assert( FindKthNodeBinaryTree( root, 2 )->data == 2 );
	cout << ( FindKthNodeBinaryTree( root, 2 ) )->data << endl;
	// should output 3
	assert( FindKthNodeBinaryTree( root, 3 )->data == 3 );
	cout << ( FindKthNodeBinaryTree( root, 3 ) )->data << endl;
	// should output 4
	assert( FindKthNodeBinaryTree( root, 4 )->data == 4 );
	cout << ( FindKthNodeBinaryTree( root, 4 ) )->data << endl;
	// should output 5
	assert( FindKthNodeBinaryTree( root, 5 )->data == 5 );
	cout << ( FindKthNodeBinaryTree( root, 5 ) )->data << endl;
	// should output 6
	assert( FindKthNodeBinaryTree( root, 6 )->data == 6 );
	cout << ( FindKthNodeBinaryTree( root, 6 ) )->data << endl;
	assert( nullptr == FindKthNodeBinaryTree( root, 7 ) );
#endif
}

#pragma endregion
