// Copyright (c) 2016 Elements of Programming Interviews. All rights reserved.

#pragma once
#include <memory>
#include <vector>
#include "./Binary_tree_prototype.h"

using std::make_unique;
using std::unique_ptr;
using std::vector;

namespace Solutions
{
	// Reconstructs the subtree that is rooted at subtreeIdx.
	inline unique_ptr<BinaryTreeNode<int>> ReconstructPreorderHelper(const vector<int*>& preorder, int* subtree_idx_pointer)
	{
		int& subtree_idx = *subtree_idx_pointer;
		int* subtree_key = preorder[subtree_idx];
		++subtree_idx;
		if (subtree_key == nullptr)
			return nullptr;

		// Note that ReconstructPreorderHelper updates subtree_idx. So the order of
		// following two calls are critical.
		auto left_subtree = ReconstructPreorderHelper(preorder, subtree_idx_pointer);
		auto right_subtree = ReconstructPreorderHelper(preorder, subtree_idx_pointer);
		return make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{*subtree_key, move(left_subtree), move(right_subtree)});
	}

	inline unique_ptr<BinaryTreeNode<int>> ReconstructPreorder(const vector<int*>& preorder)
	{
		int subtree_idx_pointer = 0;
		return ReconstructPreorderHelper(preorder, &subtree_idx_pointer);
	}
}
