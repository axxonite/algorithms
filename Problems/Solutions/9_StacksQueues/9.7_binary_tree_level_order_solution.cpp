// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	vector<vector<int>> BinaryTreeDepthOrder(const unique_ptr<BinaryTreeNode<int>>& tree)
	{
		queue<BinaryTreeNode<int>*> currDepthNodes({ tree.get() });
		vector<vector<int>> result;

		while (!currDepthNodes.empty())
		{
			queue<BinaryTreeNode<int>*> nextDepthNodes;
			vector<int> thisLevel;
			while (!currDepthNodes.empty())
			{
				auto curr = currDepthNodes.front();
				currDepthNodes.pop();
				if (curr)
				{
					thisLevel.emplace_back(curr->data);

					// Defer the null checks to the null test above.
					nextDepthNodes.emplace(curr->left.get());
					nextDepthNodes.emplace(curr->right.get());
				}
			}

			if (!thisLevel.empty())
				result.emplace_back(thisLevel);
			currDepthNodes = nextDepthNodes;
		}
		return result;
	}
}
