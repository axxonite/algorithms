// Copyright (c) 2016 Elements of Programming Interviews. All rights reserved.

#pragma once
#include <memory>
#include <vector>
#include "./binary_tree_prototype.h"

using namespace std;

namespace Solutions
{
	// Reconstructs the subtree that is rooted at subtreeIdx.
	inline unique_ptr<BinaryTreeNode<int>> ReconstructPreorderHelper(const vector<int*>& preorder, int& index)
	{
		int* key = preorder[index++];
		if (!key)
			return nullptr; // empty child.

		// Note that ReconstructPreorderHelper updates index. So the order of following two calls are critical.
		return make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{*key, move(ReconstructPreorderHelper(preorder, index)), move(ReconstructPreorderHelper(preorder, index))});
	}

	inline unique_ptr<BinaryTreeNode<int>> ReconstructPreorder(const vector<int*>& preorder)
	{
		int index = 0;
		return ReconstructPreorderHelper(preorder, index);
	}
}
