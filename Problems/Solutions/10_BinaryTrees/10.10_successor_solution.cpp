// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

namespace Solutions
{
	BinaryTreeNodeP<int>* FindSuccessor(const unique_ptr<BinaryTreeNodeP<int>>& node)
	{
		auto* iter = node.get();
		// If there is a right subtree, then the successor is the leftmost element in the node's right subtree.
		if (iter->right != nullptr)
		{
			iter = iter->right.get();
			while (iter->left)
				iter = iter->left.get();
			return iter;
		}

		// Otherwise, the successor is the closest ancestor where we came back up from the left side.
		while (iter->parent != nullptr && iter->parent->right.get() == iter)
			iter = iter->parent;
		// A return value of nullptr means node does not have successor, i.e., it  the rightmost node in the tree.
		return iter->parent;
	}
}
