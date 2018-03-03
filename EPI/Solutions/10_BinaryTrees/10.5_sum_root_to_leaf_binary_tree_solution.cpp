// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	int SumRootToLeafHelper( const unique_ptr<BinaryTreeNode<int>>& tree, int parentValue, int sum )
	{
		if ( !tree )
			return sum;
		int value = parentValue << 1 | tree->data;
		if ( !tree->left && !tree->right )
			return sum + value;
		return SumRootToLeafHelper( tree->left, value, sum ) + SumRootToLeafHelper( tree->right, value, sum );
	}

	int SumRootToLeaf( const unique_ptr<BinaryTreeNode<int>>& tree )
	{
		return SumRootToLeafHelper( tree, 0, 0 );
	}
}