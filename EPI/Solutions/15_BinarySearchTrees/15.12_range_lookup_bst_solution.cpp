// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Interval
	{
		int left, right;
	};

	void RangeLookupInBST( const unique_ptr<BSTNode<int>>& tree, const Interval& interval, vector<int>& result )
	{
		if ( !tree )
			return;
		if ( tree->data >= interval.left && tree->data <= interval.right )
			result.emplace_back( tree->data );
		if ( tree->data >= interval.left )
			RangeLookupInBST( tree->left, interval, result );
		if ( tree->data <= interval.right )
			RangeLookupInBST( tree->right, interval, result );
	}
}