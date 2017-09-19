// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

namespace Solutions
{
	BinaryTreeNodeP<int>* LCA2(const unique_ptr<BinaryTreeNodeP<int>>& node_0, const unique_ptr<BinaryTreeNodeP<int>>& node_1)
	{
		auto *it0 = node_0.get(), *it1 = node_1.get();
		unordered_set<const BinaryTreeNodeP<int>*> nodes_on_path_to_root;
		while (it0 || it1)
		{
			// Ascend tree in tandem for these two nodes.
			if (it0)
			{
				if (nodes_on_path_to_root.emplace(it0).second == false)
					return it0;
				it0 = it0->parent;
			}
			if (it1)
			{
				if (nodes_on_path_to_root.emplace(it1).second == false)
					return it1;
				it1 = it1->parent;
			}
		}
		throw invalid_argument("node_0 and node_1 are not in the same tree");
	}
}
