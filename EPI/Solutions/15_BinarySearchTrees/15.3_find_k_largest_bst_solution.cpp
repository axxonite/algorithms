// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Use recursion to do a traversal - don't try to avoid recursion unless explicitly asked not to.
	void FindKLargestInBST( const unique_ptr<BSTNode<int>>& tree, int k, vector<int>& result )
	{
		if ( !tree || result.size() == k )
			return;
		FindKLargestInBST( tree->right, k, result );
		if ( result.size() < k )
		{
			result.emplace_back( tree->data );
			FindKLargestInBST( tree->left, k, result );
		}
	}

	vector<int> FindKLargestInBST( const unique_ptr<BSTNode<int>>& tree, int k )
	{
		vector<int> result;
		FindKLargestInBST( tree, k, result );
		return result;
	}
}