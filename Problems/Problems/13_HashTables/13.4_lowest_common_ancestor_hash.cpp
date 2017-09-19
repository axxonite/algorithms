// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

#define TEST 1

BinaryTreeNodeP<int>* LCA2(const unique_ptr<BinaryTreeNodeP<int>>& node_0, const unique_ptr<BinaryTreeNodeP<int>>& node_1)
{
	auto *it0 = node_0.get(), *it1 = node_1.get();
	unordered_set<const BinaryTreeNodeP<int>*> nodes_on_path_to_root;
	while (it0 || it1)
	{
		// Ascend tree in tandem for these two nodes.
		if (it0)
		{
			if (nodes_on_path_to_root.emplace(it0).second == false)
				return it0;
			it0 = it0->parent;
		}
		if (it1)
		{
			if (nodes_on_path_to_root.emplace(it1).second == false)
				return it1;
			it1 = it1->parent;
		}
	}
	throw invalid_argument("node_0 and node_1 are not in the same tree");
}

#pragma region Test

void LCA2Test()
{
#if TEST
	//      3
	//    2   5
	//  1    4 6
	unique_ptr<BinaryTreeNodeP<int>> root = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{3, nullptr, nullptr});
	root->parent = nullptr;
	root->left = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{2, nullptr, nullptr});
	root->left->parent = root.get();
	root->left->left = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{1, nullptr, nullptr});
	root->left->left->parent = root->left.get();
	root->right = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{5, nullptr, nullptr});
	root->right->parent = root.get();
	root->right->left = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{4, nullptr, nullptr});
	root->right->left->parent = root->right.get();
	root->right->right = make_unique<BinaryTreeNodeP<int>>(
		BinaryTreeNodeP<int>{6, nullptr, nullptr});
	root->right->right->parent = root->right.get();

	// should output 3
	assert(LCA2(root->left, root->right)->data == 3);
	cout << (LCA2(root->left, root->right))->data << endl;
	// should output 5
	assert(LCA2(root->right->left, root->right->right)->data == 5);
	cout << (LCA2(root->right->left, root->right->right)->data) << endl;
#endif
}

#pragma endregion Test
