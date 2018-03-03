// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	bool IsSymmetric( const unique_ptr<BinaryTreeNode<int>>& left, const unique_ptr<BinaryTreeNode<int>>& right )
	{
		if ( !left && !right )
			return true;
		if ( !left || !right || left->data != right->data || !IsSymmetric( left->left, right->left ) || !IsSymmetric( left->right, right->right ) )
			return false;
		return true;
	}

	bool IsSymmetric( const unique_ptr<BinaryTreeNode<int>>& tree )
	{
		return !tree || IsSymmetric( tree->left, tree->right );
	}
}