// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	list<const unique_ptr<BinaryTreeNode<int>>*> CreateListOfLeaves(const unique_ptr<BinaryTreeNode<int>>& t)
	{
		list<const unique_ptr<BinaryTreeNode<int>>*> result;
		if (!t)
			return result;
		if (!t->left && !t->right)
			result.emplace_back(&t);
		else
		{
			result.splice(result.end(), CreateListOfLeaves(t->left));
			result.splice(result.end(), CreateListOfLeaves(t->right));
		}
		return result;
	}
}