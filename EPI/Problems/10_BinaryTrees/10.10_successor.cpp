// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

// #define TEST

BinaryTreeNodeP<int>* FindSuccessor( const unique_ptr<BinaryTreeNodeP<int>>& node)
{
	return nullptr;
}

#pragma region Test

void FindSuccessorTest()
{
#ifdef TEST
	//      3
	//    2   5
	//  1    4  6
	auto root = make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{3});
	root->parent = nullptr;
	assert(FindSuccessor(root) == nullptr);
	root->left = make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{2});
	root->left->parent = root.get();
	assert(FindSuccessor(root->left)->data == 3);

	root->left->left = make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{1});
	root->left->left->parent = root->left.get();
	assert(FindSuccessor(root->left)->data == 3);
	assert(FindSuccessor(root->left->left)->data == 2);

	root->right = make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{5});
	root->right->parent = root.get();
	root->right->left =
		make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{4});
	root->right->left->parent = root->right.get();
	root->right->right =
		make_unique<BinaryTreeNodeP<int>>(BinaryTreeNodeP<int>{6});
	root->right->right->parent = root->right.get();
	// should output 6
	auto* node = FindSuccessor(root->right);
	assert(6 == node->data);
	if (node)
	{
		cout << node->data << endl;
	}
	else
	{
		cout << "null" << endl;
	}
	// should output "null"
	node = FindSuccessor(root->right->right);
	assert(!node);
	if (node)
	{
		cout << node->data << endl;
	}
	else
	{
		cout << "null" << endl;
	}
#endif
}

#pragma endregion Test
