// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "doubly_linked_list_prototype.h"

namespace Solutions
{
	// Builds a BST from the (start + 1)-th to the end-th node, inclusive, in L, and returns the root.
	shared_ptr<ListNode<int>> BuildBSTFromSortedDoublyListHelper(shared_ptr<ListNode<int>>* L_ref, int start, int end) 
	{
		if (start >= end)
			return nullptr;

		int mid = start + ((end - start) / 2);
		auto left = BuildBSTFromSortedDoublyListHelper(L_ref, start, mid);
		// The last function call sets L_ref to the successor of the maximum node in the tree rooted at left.
		auto curr = *L_ref;
		*L_ref = (*L_ref)->next;
		curr->prev = left;
		curr->next = BuildBSTFromSortedDoublyListHelper(L_ref, mid + 1, end);
		return curr;
	}

	// Returns the root of the corresponding BST. The prev and next fields of the list nodes are used as the BST nodes left and right fields, respectively. The length of the list is given.
	shared_ptr<ListNode<int>> BuildBSTFromSortedDoublyList(shared_ptr<ListNode<int>> L, int length)
	{
		return BuildBSTFromSortedDoublyListHelper(&L, 0, length);
	}
}
