// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

namespace Solutions
{
	BinaryTreeNodeP<int>* NextState(BinaryTreeNodeP<int>* cur, BinaryTreeNodeP<int>* prev, vector<int>& result)
	{
		if (prev == cur->parent)
		{
			if (cur->left)
				return cur->left.get();
		}
		if (prev == cur->left.get() || prev == cur->parent)
		{
			result.emplace_back(cur->data);
			if (cur->right)
				return cur = cur->right.get();
		}
		return cur->parent;
	}

	vector<int> InorderTraversal(const unique_ptr<BinaryTreeNodeP<int>>& tree)
	{
		// we can avoid extra storage by keeping track of where we came from.
		// If we come from the parent (or nullptr), we need go left.
		// If we come from the left child, we need to record the node, and go right.
		// If we come from the right child, we need to go to the parent;
		// Any of these paths may lead to a null child. In this case, continue to the next state.
		BinaryTreeNodeP<int>* cur = tree.get(), *prev = nullptr;
		vector<int> result;
		while (cur)
		{
			auto temp = cur;
			cur = NextState(cur, prev, result); // Beautiful.
			prev = temp;
		}
		return result;
	}
}