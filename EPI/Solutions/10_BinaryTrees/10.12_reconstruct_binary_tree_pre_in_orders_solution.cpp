// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	// Builds the subtree with preorder[preorderStart, preorderEnd - 1] and inorder[inorderStart, inorderEnd - 1].
	unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorderHelper(const vector<int>& preorder, size_t preorderStart, size_t preorderEnd, size_t inorderStart, size_t inorderEnd, const unordered_map<int, size_t>& node_to_inorder_idx)
	{
		if (preorderEnd <= preorderStart || inorderEnd <= inorderStart)
			return nullptr;
		size_t rootInorderIndex = node_to_inorder_idx.at(preorder[preorderStart]); // Index of the root in the in the inorder array, queried from the hash table.
		size_t leftSubtreeSize = rootInorderIndex - inorderStart; // From this we know how many nodes are on the left of this root. Note that we offset from inorderStart, which is where the current subtree starts.
		return make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{preorder[preorderStart],
			// Left sub tree is [preStart+1..+leftSubTreeSize], [inorderStart..rootInOrderIndex]
			BinaryTreeFromPreorderInorderHelper(preorder, preorderStart + 1, preorderStart + 1 + leftSubtreeSize, inorderStart, rootInorderIndex, node_to_inorder_idx), // Recursively builds the left subtree.
			// Right subtree is [preStart+1+leftSubTreeSize, preOrderEnd], [rootInOrderIndex+1, inOrderEnd] - note the +1 on rootInOrderIndex, because we are skipping over the current root - tricky.
			BinaryTreeFromPreorderInorderHelper(preorder, preorderStart + 1 + leftSubtreeSize, preorderEnd, rootInorderIndex + 1, inorderEnd, node_to_inorder_idx) // Recursively builds the right subtree.
		});
	}

	unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder(const vector<int>& preorder, const vector<int>& inorder)
	{
		unordered_map<int, size_t> node_to_inorder_idx; // Hash table for which, given a node's unique key, we can retrieve the index of the node in the in-order array.
		for (size_t i = 0; i < inorder.size(); ++i)
			node_to_inorder_idx.emplace(inorder[i], i);
		return BinaryTreeFromPreorderInorderHelper(preorder, 0, preorder.size(), 0, inorder.size(), node_to_inorder_idx);
	}
}