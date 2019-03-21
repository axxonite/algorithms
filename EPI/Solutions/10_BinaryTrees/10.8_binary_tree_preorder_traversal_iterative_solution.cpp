// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	vector<int> PreorderTraversal( const unique_ptr<BinaryTreeNode<int>>& tree )
	{
		// got it on the first try... but how would I have made sure this works 100%?
		if ( !tree )
			return {};
		vector<int> result;
		stack<BinaryTreeNode<int>*> s;
		s.emplace( tree.get() );
		while ( !s.empty() )
		{
			auto c = s.top();
			s.pop();
			if ( c )
			{
				result.emplace_back( c->data );
				s.emplace( c->right.get() );
				s.emplace( c->left.get() );
			}
		}
		return result;
	}
}