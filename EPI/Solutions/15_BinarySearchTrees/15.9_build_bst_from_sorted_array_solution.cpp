// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	unique_ptr<BSTNode<int>> BuildMinHeightBSTFromSortedArray( const vector<int>& a, int start, int end )
	{
		if ( start >= end )
			return nullptr;
		int mid = ( start + end ) / 2;
		auto tree = make_unique<BSTNode<int>>( BSTNode<int>{a[mid]} );
		tree->left = BuildMinHeightBSTFromSortedArray( a, start, mid );
		tree->right = BuildMinHeightBSTFromSortedArray( a, mid + 1, end );
		return tree;
	}

	unique_ptr<BSTNode<int>> BuildMinHeightBSTFromSortedArray( const vector<int>& a )
	{
		return BuildMinHeightBSTFromSortedArray( a, 0, a.size() );
	}
}