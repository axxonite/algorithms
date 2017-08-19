// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> BSTInSortedOrder(const unique_ptr<BSTNode<int>>& tree)
	{
		// This stack keeps track of all the nodes we've visited on the left side thus far.
		stack<const BSTNode<int>*> s;
		const auto* curr = tree.get();
		vector<int> result;
		while (!s.empty() || curr)
		{
			if (curr)
			{
				s.push(curr);
				// Going left.
				curr = curr->left.get();
			}
			else
			{
				// Going up.
				curr = s.top();
				s.pop();
				result.emplace_back(curr->data);
				// Going right.
				curr = curr->right.get();
			}
		}
		return result;
	}
}
