// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	vector<vector<int>> BinaryTreeDepthOrder(const unique_ptr<BinaryTreeNode<int>>& tree)
	{
		// All nodes from the current level go here.
		queue<BinaryTreeNode<int>*> currDepthNodes({ tree.get() });
		vector<vector<int>> result;

		// Outer loop checks if we've processed the last level.
		while (!currDepthNodes.empty())
		{
			// Start a new level.
			queue<BinaryTreeNode<int>*> nextDepthNodes;
			vector<int> keysThisLevel;
			// Inner loops iterates over nodes.
			while (!currDepthNodes.empty())
			{
				auto curr = currDepthNodes.front();
				currDepthNodes.pop();
				if (curr) // Check that its null as we may be adding nulls in the queue.
				{
					keysThisLevel.emplace_back(curr->data); // add to current level.

					// Defer the null checks to the null test above.
					nextDepthNodes.emplace(curr->left.get());
					nextDepthNodes.emplace(curr->right.get());
				}
			}

			// This level is finished.
			if (!keysThisLevel.empty())
				result.emplace_back(keysThisLevel);

			// Move to the next level.
			currDepthNodes = nextDepthNodes;
		}
		return result;
	}
}
