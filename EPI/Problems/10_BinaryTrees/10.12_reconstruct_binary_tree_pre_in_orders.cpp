// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"
#include "../../binary_tree_utils.h"

#define TEST 0

unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder(const vector<int>& preorder, const vector<int>& inorder)
{
	return nullptr;
}

#pragma region Test

void BinaryTreeFromPreorderInorderSimpleTest()
{
	auto res = BinaryTreeFromPreorderInorder({1}, {1});
	assert(res->data == 1);

	res = BinaryTreeFromPreorderInorder({2, 1}, {1, 2});
	assert(res->data == 2 && res->left->data == 1 && res->right == nullptr);

	int N = 100;
	vector<int> inorder, preorder;
	for (int i = 0; i < N; ++i)
	{
		inorder.emplace_back(i);
		preorder.emplace_back((N - 1) - i);
	}

	res = BinaryTreeFromPreorderInorder(preorder, inorder);
	assert(res->data == N - 1 && res->left->data == N - 2 &&
		res->right == nullptr);
}

void BinaryTreeFromPreorderInorderTest()
{
#if TEST
	BinaryTreeFromPreorderInorderSimpleTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 20; ++times)
	{
		cout << times << endl;
		uniform_int_distribution<int> dis(1, 100);
		int n = dis(gen);
		unique_ptr<BinaryTreeNode<int>> root =
			GenerateRandBinaryTree<int>(n, true);
		vector<int> pre = GeneratePreorder(root);
		vector<int> in = GenerateInorder(root);
		auto res = BinaryTreeFromPreorderInorder(pre, in);
		assert(IsTwoBinaryTreesEqual<int>(root, res));
		DeleteBinaryTree(&root);
		DeleteBinaryTree(&res);
	}
#endif
}

#pragma endregion Test