// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "../../binary_tree_prototype.h"

namespace Solutions
{
	bool IsLeaf(const unique_ptr<BinaryTreeNode<int>>& node)
	{
		return node->left == nullptr && node->right == nullptr;
	}

	// Computes the nodes from the root to the leftmost leaf followed by all the leaves in subtree.
	list<const unique_ptr<BinaryTreeNode<int>>*> LeftBoundaryAndLeaves(const unique_ptr<BinaryTreeNode<int>>& subtree, bool boundary)
	{
		list<const unique_ptr<BinaryTreeNode<int>>*> result;
		if (subtree != nullptr)
		{
			if (boundary || IsLeaf(subtree))
				result.emplace_back(&subtree);
			result.splice(result.end(), LeftBoundaryAndLeaves(subtree->left, boundary));
			result.splice(result.end(), LeftBoundaryAndLeaves(subtree->right, boundary && subtree->left == nullptr));
		}
		return result;
	}

	// Computes the leaves in left-to-right order followed by the rightmost leaf to the root path in subtree.
	list<const unique_ptr<BinaryTreeNode<int>>*> RightBoundaryAndLeaves(const unique_ptr<BinaryTreeNode<int>>& subtree, bool boundary)
	{
		list<const unique_ptr<BinaryTreeNode<int>>*> result;
		if (subtree != nullptr)
		{
			result.splice(result.end(), RightBoundaryAndLeaves(subtree->left, boundary && subtree->right == nullptr));
			result.splice(result.end(), RightBoundaryAndLeaves(subtree->right, boundary));
			if (boundary || IsLeaf(subtree))
				result.emplace_back(&subtree);
		}
		return result;
	}

	list<const unique_ptr<BinaryTreeNode<int>>*> ExteriorBinaryTree(const unique_ptr<BinaryTreeNode<int>>& tree)
	{
		list<const unique_ptr<BinaryTreeNode<int>>*> exterior;
		if (tree != nullptr)
		{
			exterior.emplace_back(&tree);
			exterior.splice(exterior.end(), LeftBoundaryAndLeaves(tree->left, true));
			exterior.splice(exterior.end(), RightBoundaryAndLeaves(tree->right, true));
		}
		return exterior;
	}
}
