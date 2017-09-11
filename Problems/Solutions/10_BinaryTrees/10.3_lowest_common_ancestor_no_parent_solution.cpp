// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	struct Status
	{
		int targetNodeCount;
		BinaryTreeNode<int>* ancestor;
	};

	// Returns an object consisting of an int and a node. The int field is
	// 0, 1, or 2 depending on how many of {node0, node1} are present in
	// the tree. If both are present in the tree, when ancestor is
	// assigned to a non-null value, it is the LCA.
	Status LCAHelper(const unique_ptr<BinaryTreeNode<int>>& tree, const unique_ptr<BinaryTreeNode<int>>& node0, const unique_ptr<BinaryTreeNode<int>>& node1)
	{
		if (tree == nullptr)
			return { 0, nullptr };

		auto leftResult = LCAHelper(tree->left, node0, node1);
		if (leftResult.targetNodeCount == 2)
			return leftResult; // Found both nodes in the left subtree.

		auto rightResult = LCAHelper(tree->right, node0, node1);
		if (rightResult.targetNodeCount == 2)
			return rightResult; // Found both nodes in the right subtree.

		int targetNodeCount = leftResult.targetNodeCount + rightResult.targetNodeCount + (tree == node0) + (tree == node1);
		return { targetNodeCount, targetNodeCount == 2 ? tree.get() : nullptr };
	}

	BinaryTreeNode<int>* LCA(const unique_ptr<BinaryTreeNode<int>>& tree, const unique_ptr<BinaryTreeNode<int>>& node0, const unique_ptr<BinaryTreeNode<int>>& node1)
	{
		return LCAHelper(tree, node0, node1).ancestor;
	}
}
