// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	unique_ptr<BinaryTreeNode<int>> Clone(const unique_ptr<BinaryTreeNode<int>>& tree)
	{
		return tree ? make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0, Clone(tree->left), Clone(tree->right)}) : nullptr;
	}

	vector<unique_ptr<BinaryTreeNode<int>>> GenerateAllBinaryTrees(int nodeCount)
	{
		vector<unique_ptr<BinaryTreeNode<int>>> result;
		// Don't forget to check for a node count of zero.
		if (nodeCount == 0)
			result.emplace_back(nullptr); // Empty tree, add as an nullptr.

		for (int leftTreeNodes = 0; leftTreeNodes < nodeCount; ++leftTreeNodes)
		{
			int rightTreeNodes = nodeCount - 1 - leftTreeNodes;
			auto left_subtrees = GenerateAllBinaryTrees(leftTreeNodes);
			auto right_subtrees = GenerateAllBinaryTrees(rightTreeNodes);
			// Generates all combinations of left_subtrees and right_subtrees. Pair up all possible left trees with all possible right trees.
			for (auto& left : left_subtrees)
				for (auto& right : right_subtrees)
					result.emplace_back(make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{0, Clone(left), Clone(right)}));
		}
		return result;
	}
}
