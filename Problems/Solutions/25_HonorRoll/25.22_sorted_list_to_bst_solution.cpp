// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "doubly_linked_list_prototype.h"

namespace Solutions
{
	// Builds a BST from the (start + 1)-th to the end-th node, inclusive, in l, and returns the root.
	shared_ptr<ListNode<int>> BuildBSTFromSortedDoublyListHelper(shared_ptr<ListNode<int>>* l, int start, int end) 
	{
		if (start >= end)
			return nullptr;

		// mid will be the index of the root node.
		int mid = start + ((end - start) / 2);
		auto left = BuildBSTFromSortedDoublyListHelper(l, start, mid);
		auto root = *l;
		// TRICKY: The last function call sets l to the successor of the maximum node in the tree rooted at left.
		*l = (*l)->next; // move iterator pointer to the first node on the right side.
		root->prev = left;
		// Don't forget the +1.
		root->next = BuildBSTFromSortedDoublyListHelper(l, mid + 1, end);
		return root;
	}

	// Returns the root of the corresponding BST. The prev and next fields of the list nodes are used as the BST nodes left and right fields, respectively. The length of the list is given.
	shared_ptr<ListNode<int>> BuildBSTFromSortedDoublyList(shared_ptr<ListNode<int>> l, int length)
	{
		return BuildBSTFromSortedDoublyListHelper(&l, 0, length);
	}
}
