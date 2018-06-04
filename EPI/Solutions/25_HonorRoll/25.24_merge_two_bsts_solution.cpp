// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "doubly_linked_list_prototype.h"

namespace Solutions
{
	shared_ptr<BSTNodeShared<int>> BSTToDoublyLinkedList( const shared_ptr<BSTNodeShared<int>>& tree );
	shared_ptr<BSTNodeShared<int>> MergeTwoSortedLists(shared_ptr<BSTNodeShared<int>> l1, shared_ptr<BSTNodeShared<int>> l2, int& length);
	shared_ptr<BSTNodeShared<int>> BuildBSTFromSortedDoublyList(shared_ptr<BSTNodeShared<int>> l, int length);

	/*
	// Adapted from 8.1
	void AppendNode(shared_ptr<BSTNodeShared<int>>* node, shared_ptr<BSTNodeShared<int>>* tail);
	{
		( *tail )->right = *node; // attach node to tail
		( *node )->left = *tail;
		*tail = ( *tail )->right; // node is new tail
		*node = ( *node )->right; // node is next node.
	}

	inline shared_ptr<BSTNodeShared<int>> MergeTwoSortedLists( shared_ptr<BSTNodeShared<int>> l1, shared_ptr<BSTNodeShared<int>> l2 )
	{
		// Creates a placeholder for the result.
		shared_ptr<BSTNodeShared<int>> dummyHead( new BSTNodeShared<int> );
		auto tail = dummyHead;

		while ( l1 && l2 )
			AppendNode( l1->data <= l2->data ? &l1 : &l2, &tail );

		// Appends the remaining nodes of l1 or l2.
		tail->right = l1 ? l1 : l2;
		return dummyHead->right;
	}

	// ------------------------------------------------------------------------------------------------
	// Adapted from 25.22.
	shared_ptr<BSTNodeShared<int>> BuildBSTFromSortedDoublyListHelper( shared_ptr<BSTNodeShared<int>>* l, int start, int end )
	{
		// of note is that end is actually one past the index of the last element.
		if ( start >= end )
			return nullptr;

		// mid will be the index of the root node.
		int mid = start + ( ( end - start ) / 2 );
		auto left = BuildBSTFromSortedDoublyListHelper( l, start, mid ); // Build the left tree from start to mid.
		auto root = *l; // now l has been advanced to the new root.
						// TRICKY: The last function call sets l to the successor of the maximum node in the tree rooted at left.
		*l = ( *l )->right; // move iterator pointer to the first node on the right side.
		root->left = left; // assign left side.
						   // Don't forget the +1. The range is inclusive and we don't want to add mid twice.
		root->right = BuildBSTFromSortedDoublyListHelper( l, mid + 1, end );
		return root;
	}

	// Returns the root of the corresponding BST. The prev and next fields of the list nodes are used as the BST nodes left and right fields, respectively. The length of the list is given.
	shared_ptr<BSTNodeShared<int>> BuildBSTFromSortedDoublyList( shared_ptr<BSTNodeShared<int>> l, int length )
	{
		return BuildBSTFromSortedDoublyListHelper( &l, 0, length );
	}

	*/

	int Length(shared_ptr<BSTNodeShared<int>> l)
	{
		int length = 0;
		while (l)
			length++, l = l->right;
		return length;
	}

	shared_ptr<BSTNodeShared<int>> MergeTwoBSTs( shared_ptr<BSTNodeShared<int>> A, shared_ptr<BSTNodeShared<int>> B )
	{
		auto a = BSTToDoublyLinkedList( A );
		auto b = BSTToDoublyLinkedList( B );
		int length;
		auto combined = MergeTwoSortedLists( a, b, length );
		return BuildBSTFromSortedDoublyList( combined, length );
	}
}