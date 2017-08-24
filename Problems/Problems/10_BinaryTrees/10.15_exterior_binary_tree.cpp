// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "../../binary_tree_prototype.h"
#include "10.13_reconstruct_preorder_with_null.h"

#define TEST 0

list<const unique_ptr<BinaryTreeNode<int>>*> ExteriorBinaryTree(const unique_ptr<BinaryTreeNode<int>>& tree)
{
	list<const unique_ptr<BinaryTreeNode<int>>*> exterior;
	return exterior;
}

#pragma region Test

list<int> CreateOutputList(const list<const unique_ptr<BinaryTreeNode<int>>*>& L)
{
	list<int> output;
	for (const auto* l : L)
		output.push_back((*l)->data);
	return output;
}

void ExteriorBinaryTreeSimpleTest()
{
	// The example in the book.
	vector<int> A = {314, 6, 271, 28, 0, 561, 3, 17,
		6, 2, 1, 401, 641, 257, 271, 28};
	unique_ptr<BinaryTreeNode<int>> tree = ReconstructPreorder(
		{&A[0], &A[1], &A[2], &A[3], nullptr, nullptr, &A[4],
			nullptr, nullptr, &A[5], nullptr, &A[6], &A[7], nullptr,
			nullptr, nullptr, &A[8], &A[9], nullptr, &A[10], &A[11],
			nullptr, &A[12], nullptr, nullptr, &A[13], nullptr, nullptr,
			&A[14], nullptr, &A[15], nullptr, nullptr});

	list<int> res = CreateOutputList(ExteriorBinaryTree(tree));
	list<int> golden = {314, 6, 271, 28, 0, 17, 641, 257, 28, 271, 6};
	assert(equal(begin(res), end(res), begin(golden), end(golden)));

	tree->left->left = nullptr;
	res = CreateOutputList(ExteriorBinaryTree(tree));
	golden = {314, 6, 561, 3, 17, 641, 257, 28, 271, 6};
	assert(equal(begin(res), end(res), begin(golden), end(golden)));

	tree->right->right = nullptr;
	res = CreateOutputList(ExteriorBinaryTree(tree));
	golden = {314, 6, 561, 3, 17, 641, 257, 1, 2, 6};
	assert(equal(begin(res), end(res), begin(golden), end(golden)));

	tree->right = nullptr;
	res = CreateOutputList(ExteriorBinaryTree(tree));
	golden = {314, 6, 561, 3, 17};
	assert(equal(begin(res), end(res), begin(golden), end(golden)));
}

void ExteriorBinaryTreeTest()
{
#if TEST
	ExteriorBinaryTreeSimpleTest();
	//        3
	//    2      5
	//  1  0    4 6
	//   -1 -2
	unique_ptr<BinaryTreeNode<int>> tree = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{3, nullptr, nullptr});
	auto L = ExteriorBinaryTree(tree);
	list<int> result = CreateOutputList(L);
	list<int> golden_result = {3};
	assert(equal(result.begin(), result.end(), golden_result.begin(),
		golden_result.end()));

	tree->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{2, nullptr, nullptr});
	L = ExteriorBinaryTree(tree);
	result = CreateOutputList(L);
	golden_result = {3, 2};
	assert(equal(result.begin(), result.end(), golden_result.begin(),
		golden_result.end()));

	tree->left->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{0, nullptr, nullptr});
	tree->left->right->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{-1, nullptr, nullptr});
	tree->left->right->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{-2, nullptr, nullptr});
	tree->left->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{1, nullptr, nullptr});
	tree->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{5, nullptr, nullptr});
	tree->right->left = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{4, nullptr, nullptr});
	tree->right->right = make_unique<BinaryTreeNode<int>>(
		BinaryTreeNode<int>{6, nullptr, nullptr});
	L = ExteriorBinaryTree(tree);
	result = CreateOutputList(L);
	golden_result = {3, 2, 1, -1, -2, 4, 6, 5};
	assert(equal(result.begin(), result.end(), golden_result.begin(),
		golden_result.end()));
#endif
}

#pragma endregion Test
