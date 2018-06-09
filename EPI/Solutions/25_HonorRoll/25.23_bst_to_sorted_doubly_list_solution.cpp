// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Book solution. Possibly more elegant.
	struct HeadAndTail 
	{
		shared_ptr<BSTNodeShared<int>> head, tail;
	};

	HeadAndTail BSTToDoublyLinkedListHelper(const shared_ptr<BSTNodeShared<int>>& tree ) 
	{
		if ( !tree )
			return { nullptr, nullptr };

		// Note how BOTH sides of the tree are computed before modifying the current node.
		HeadAndTail left = BSTToDoublyLinkedListHelper( tree->left );
		HeadAndTail right = BSTToDoublyLinkedListHelper( tree->right );

		// Returning a whole list as a result does make it easy to link said list with the node we currently have.
		if ( left.tail )
			left.tail->right = tree; // Appends current node to the list from left subtree.
		// Link the current node on both sides.
		tree->left = left.tail;
		tree->right = right.head;
		if ( right.head )
			right.head->left = tree; // Appends the list from right subtree to the current node.

		return { left.head ? left.head : tree, right.tail ? right.tail : tree }; // Make sure to deal with all the edge cases where there is no head and tail.
	}

	shared_ptr<BSTNodeShared<int>> BSTToDoublyLinkedList(const shared_ptr<BSTNodeShared<int>>& tree )
	{
		return BSTToDoublyLinkedListHelper( tree ).head;
	}
}