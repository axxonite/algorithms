// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	template <typename T>
	struct BinaryTreeNodeWithSize
	{
		T data;
		unique_ptr<BinaryTreeNodeWithSize<T>> left, right;
		int size;
	};

	const BinaryTreeNodeWithSize<int>* FindKthNodeBinaryTree( const unique_ptr<BinaryTreeNodeWithSize<int>>& tree, int k )
	{
		// looking for k nodes means we want k - 1 nodes in the left tree. So if k is 1, the left tree is empty.
		if ( !tree )
			return nullptr;
		int leftNodes = tree->left ? tree->left->size : 0;
		if ( leftNodes == k - 1 )
			return tree.get();
		if ( leftNodes > k - 1 )
			return FindKthNodeBinaryTree( tree->left, k );
		return FindKthNodeBinaryTree( tree->right, k - leftNodes - 1 );
	}
}