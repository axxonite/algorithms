// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"
#include "binary_tree_utils.h"

namespace Solutions
{
	bool IsBinaryTreeBST( const unique_ptr<BinaryTreeNode<int>>& tree, int low, int high )
	{
		if ( !tree )
			return true;
		if ( tree->data < low || tree->data > high )
			return false;
		return IsBinaryTreeBST( tree->left, low, tree->data ) && IsBinaryTreeBST( tree->right, tree->data, high );
	}

	bool IsBinaryTreeBST( const unique_ptr<BinaryTreeNode<int>>& tree )
	{
		return IsBinaryTreeBST( tree, numeric_limits<int>::min(), numeric_limits<int>::max() );
	}
}