// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	struct Status
	{
		bool balanced;
		int height;
	};

	Status IsBalancedHelper( const unique_ptr<BinaryTreeNode<int>>& tree )
	{
		auto left = tree->left ? IsBalancedHelper( tree->left ) : Status{ true, 0 };
		auto right = tree->right ? IsBalancedHelper( tree->right ) : Status{ true, 0 };
		return { left.balanced && right.balanced && abs( left.height - right.height ) <= 1, max( left.height, right.height ) + 1 };
	}

	bool IsBalanced( const unique_ptr<BinaryTreeNode<int>>& tree )
	{
		return IsBalancedHelper( tree ).balanced;
	}
}