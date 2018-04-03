// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	// A few key things to be able to write this in the most compact and elegant way:
	// There's no need for a "current" pointer. Just push the current at the top of the stack, with the stack describing the path down the tree.
	// There is a bit of repetition in the algorith, but it's only a couple of lines.
	vector<int> PostorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree)
	{
		stack<BinaryTreeNode<int>*> s;
		BinaryTreeNode<int>* last = nullptr;
		s.push(tree.get());
		vector<int> result;
		while (!s.empty())
		{
			auto cur = s.top();
			if (!last || last->left.get() == cur || last->right.get() == cur) // Coming from the parent.
			{
				// Traverse left if there is a left child, otherwise traverse right.
				if (cur->left)
					s.push(cur->left.get());
				else if (cur->right)
					s.push(cur->right.get());
				else
				{
					result.emplace_back(cur->data);
					s.pop();
				}
			}
			else if (cur->left.get() == last && cur->right) // Coming from the left child.
				s.push(cur->right.get());
			else
			{
				result.emplace_back(cur->data);
				s.pop();
			}
			last = cur;
		}
		return result;
	}
}
