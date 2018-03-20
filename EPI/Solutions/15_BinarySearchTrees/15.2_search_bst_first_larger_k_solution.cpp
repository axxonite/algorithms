// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	BSTNode<int>* FindFirstGreaterThanK( const unique_ptr<BSTNode<int>>& tree, int k )
	{
		BSTNode<int>* cur = tree.get(), *result = nullptr;
		// Note how it's simpler, in this case, to avoid recursion for the BST search.
		while ( cur )
		{
			if ( cur->data > k )
			{
				result = cur;
				cur = cur->left.get();
			}
			else cur = cur->right.get();
		}
		return result;
	}
}