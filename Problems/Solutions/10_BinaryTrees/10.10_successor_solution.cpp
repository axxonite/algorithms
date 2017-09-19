// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

namespace Solutions
{
	BinaryTreeNodeP<int>* FindSuccessor(const unique_ptr<BinaryTreeNodeP<int>>& node)
	{
		auto* iter = node.get();
		if (iter->right != nullptr)
		{
			// Successor is the leftmost element in node's right subtree.
			iter = iter->right.get();
			while (iter->left)
				iter = iter->left.get();
			return iter;
		}

		// Find the closest ancestor whose left subtree contains node.
		while (iter->parent != nullptr && iter->parent->right.get() == iter)
			iter = iter->parent;
		// A return value of nullptr means node does not have successor, i.e., it is
		// the rightmost node in the tree.
		return iter->parent;
	}
}
