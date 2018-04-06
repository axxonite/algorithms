// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void BSTToDoublyLinkedListHelper( const shared_ptr<BSTNodeShared<int>>& tree, BSTNodeShared<int>*& last )
	{
		if ( !tree )
			return;
		BSTToDoublyLinkedListHelper( tree->left, last );
		tree->left = make_shared<BSTNodeShared<int>>( *last );
		last->right = tree;
		// Here we have a proper link between tree and last. If there is no last, tree->left is null.
		last = tree.get();
		// Last is now our current node, tree.
		auto right = tree->right;
		tree->right = nullptr;
		BSTToDoublyLinkedListHelper( right, last );
		// After this point, tree->right would be assigned to whatever was on the right of that subtree.
	}

	shared_ptr<BSTNodeShared<int>> BSTToDoublyLinkedList( const shared_ptr<BSTNodeShared<int>>& tree )
	{
		BSTNodeShared<int> dummyNode{ 0, nullptr, nullptr };
		BSTNodeShared<int>* last = &dummyNode;
		BSTToDoublyLinkedListHelper( tree, last );
		return dummyNode.right;
	}


	// Book solution. Possibly more elegant.
	struct HeadAndTail 
	{
		shared_ptr<BSTNodeShared<int>> head, tail;
	};

	HeadAndTail BSTToDoublyLinkedListHelper2(const shared_ptr<BSTNodeShared<int>>& tree ) 
	{
		if ( !tree )
			return { nullptr, nullptr };

		HeadAndTail left = BSTToDoublyLinkedListHelper2( tree->left );
		HeadAndTail right = BSTToDoublyLinkedListHelper2( tree->right );

		// Returning a whole list as a result does make it easy to link said list with the node we currently have.
		if ( left.tail )
			left.tail->right = tree; // Appends tree to the list from left subtree.
		tree->left = left.tail;
		tree->right = right.head;
		if ( right.head )
			right.head->left = tree; // Appends the list from right subtree to tree.

		return { left.head ? left.head : tree, right.tail ? right.tail : tree }; // Make sure to deal with all the edge cases where there is no head and tail.
	}

	shared_ptr<BSTNodeShared<int>> BSTToDoublyLinkedList2(const shared_ptr<BSTNodeShared<int>>& tree )
	{
		return BSTToDoublyLinkedListHelper2( tree ).head;
	}
}