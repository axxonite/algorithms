// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	bool HasPathSum( const unique_ptr<BinaryTreeNode<int>>& tree, int parentWeight, int targetWeight )
	{
		if ( !tree )
			return false;
		int curWeight = parentWeight + tree->data;
		if ( !tree->left && !tree->right )
			return curWeight == targetWeight;
		if ( ( tree->left && HasPathSum( tree->left, curWeight, targetWeight ) ) ||
			( tree->right && HasPathSum( tree->right, curWeight, targetWeight ) ) )
			return true;
		return false;
	}

	bool HasPathSum( const unique_ptr<BinaryTreeNode<int>>& tree, int targetWeight )
	{
		return HasPathSum( tree, 0, targetWeight );
	}
}