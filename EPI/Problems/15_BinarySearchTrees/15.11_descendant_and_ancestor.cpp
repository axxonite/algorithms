// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

bool PairIncludesAncestorAndDescendantOfM(const unique_ptr<BSTNode<int>>& a, const unique_ptr<BSTNode<int>>& b, const unique_ptr<BSTNode<int>>& middle)
{
	return false;
}

#pragma region Test

void PairIncludesAncestorAndDescendantOfMSmallTest()
{
	auto root = make_unique<BSTNode<int>>(BSTNode<int>{5});
	assert(!PairIncludesAncestorAndDescendantOfM(root, root, root));
	root->left = make_unique<BSTNode<int>>(BSTNode<int>{2});
	root->left->right = make_unique<BSTNode<int>>(BSTNode<int>{4});
	assert(!PairIncludesAncestorAndDescendantOfM(root, root->left, root->left->right));
	assert(PairIncludesAncestorAndDescendantOfM(root, root->left->right, root->left));

	// Example of the first figure of BST chapter.
	root = make_unique<BSTNode<int>>(BSTNode<int>{19});
	root->left = make_unique<BSTNode<int>>(BSTNode<int>{7});
	root->left->left = make_unique<BSTNode<int>>(BSTNode<int>{3});
	root->left->left->left = make_unique<BSTNode<int>>(BSTNode<int>{2});
	root->left->left->right = make_unique<BSTNode<int>>(BSTNode<int>{5});
	root->left->right = make_unique<BSTNode<int>>(BSTNode<int>{11});
	root->left->right->right = make_unique<BSTNode<int>>(BSTNode<int>{17});
	root->left->right->right->left = make_unique<BSTNode<int>>(BSTNode<int>{13});
	root->right = make_unique<BSTNode<int>>(BSTNode<int>{43});
	root->right->left = make_unique<BSTNode<int>>(BSTNode<int>{23});
	root->right->left->right = make_unique<BSTNode<int>>(BSTNode<int>{37});
	root->right->left->right->left = make_unique<BSTNode<int>>(BSTNode<int>{29});
	root->right->left->right->left->right = make_unique<BSTNode<int>>(BSTNode<int>{31});
	root->right->left->right->right = make_unique<BSTNode<int>>(BSTNode<int>{41});
	root->right->right = make_unique<BSTNode<int>>(BSTNode<int>{47});
	root->right->right->right = make_unique<BSTNode<int>>(BSTNode<int>{53});

	assert(!PairIncludesAncestorAndDescendantOfM(root->right, root->left, root->right->left));
	assert(PairIncludesAncestorAndDescendantOfM( root, root->right->left->right->left->right, root->right->left));
}

void PairIncludesAncestorAndDescendantOfMTest()
{
#ifdef TEST
	PairIncludesAncestorAndDescendantOfMSmallTest();
	//      3
	//    2   5
	//  1    4 6
	auto root = make_unique<BSTNode<int>>(BSTNode<int>{3});
	root->left = make_unique<BSTNode<int>>(BSTNode<int>{2});
	root->left->left = make_unique<BSTNode<int>>(BSTNode<int>{1});
	root->right = make_unique<BSTNode<int>>(BSTNode<int>{5});
	root->right->left = make_unique<BSTNode<int>>(BSTNode<int>{4});
	root->right->right = make_unique<BSTNode<int>>(BSTNode<int>{6});
	assert(PairIncludesAncestorAndDescendantOfM(root, root->right->right,
		root->right));
	assert(PairIncludesAncestorAndDescendantOfM(root->right->right, root,
		root->right));
	assert(!PairIncludesAncestorAndDescendantOfM(root, root->right,
		root->right->right));
	assert(!PairIncludesAncestorAndDescendantOfM(root->right, root,
		root->right->right));
	assert(!PairIncludesAncestorAndDescendantOfM(
		root->right->left, root->right->right, root->right));
	assert(!PairIncludesAncestorAndDescendantOfM(
		root->right->left, root->left->left, root->right));
#endif
}

#pragma endregion Test
