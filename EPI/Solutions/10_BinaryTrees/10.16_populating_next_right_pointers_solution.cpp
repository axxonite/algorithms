// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	template <typename T>
	struct BinaryTreeNodeNext
	{
		T data;
		unique_ptr<BinaryTreeNodeNext<T>> left, right;
		BinaryTreeNodeNext<T>* next;  // Populates this field.
	};

	// Tricky.
	void ConstructRightSibling(BinaryTreeNodeNext<int>* tree)
	{
		// Much of the simplicity here is predicated on the fact is a COMPLETE binary tree. This is essential.
		BinaryTreeNodeNext<int>* leftmostNode = tree;
		while (leftmostNode && leftmostNode->left)
		{
			auto iter = leftmostNode;
			while (iter)
			{
				iter->left->next = iter->right.get();
				iter->right->next = iter->next ? iter->next->left.get() : nullptr;
				iter = iter->next;
			}
			leftmostNode = leftmostNode->left.get(); // Process next level.
		}
	}
}