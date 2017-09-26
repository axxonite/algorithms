// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

namespace Solutions
{
	BinaryTreeNodeP<int>* LCA2(const unique_ptr<BinaryTreeNodeP<int>>& node0, const unique_ptr<BinaryTreeNodeP<int>>& node1)
	{
		auto* it0 = node0.get(), *it1 = node1.get();
		unordered_set<const BinaryTreeNodeP<int>*> nodesOnPathToRoot;
		while (it0 || it1)
		{
			// Ascend tree in tandem for these two nodes.
			if (it0)
			{
				if (nodesOnPathToRoot.emplace(it0).second == false)
					return it0;
				it0 = it0->parent;
			}
			if (it1)
			{
				if (nodesOnPathToRoot.emplace(it1).second == false)
					return it1;
				it1 = it1->parent;
			}
		}
		throw invalid_argument("node0 and node1 are not in the same tree");
	}
}
