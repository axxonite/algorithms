// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "doubly_linked_list_prototype.h"

namespace Solutions
{
	// Builds a BST from the (start + 1)-th to the end-th node, inclusive, in l, and returns the root.
	// Note the use of a pointer to a shared pointer so we can update the shared pointer.
	shared_ptr<ListNodeDbl<int>> BuildBSTFromSortedDoublyListHelper(shared_ptr<ListNodeDbl<int>>* l, int start, int end) 
	{
		// if note is that end is actually one past the index of the last element.
		if (start >= end)
			return nullptr;

		// mid will be the index of the root node.
		int mid = start + ((end - start) / 2);
		auto left = BuildBSTFromSortedDoublyListHelper(l, start, mid); // Build the left tree from start to mid.
		auto root = *l; // now l has been advanced to the new root.
		// TRICKY: The last function call sets l to the successor of the maximum node in the tree rooted at left.
		*l = (*l)->next; // move iterator pointer to the first node on the right side.
		root->prev = left; // assign left side.
		// Don't forget the +1. The range is inclusive and we don't want to add mid twice.
		root->next = BuildBSTFromSortedDoublyListHelper(l, mid + 1, end);
		return root;
	}

	// Returns the root of the corresponding BST. The prev and next fields of the list nodes are used as the BST nodes left and right fields, respectively. The length of the list is given.
	shared_ptr<ListNodeDbl<int>> BuildBSTFromSortedDoublyList(shared_ptr<ListNodeDbl<int>> l, int length)
	{
		return BuildBSTFromSortedDoublyListHelper(&l, 0, length);
	}


	// Builds a BST from the (start + 1)-th to the end-th node, inclusive, in l, and returns the root.
	// Note the use of a pointer to a shared pointer so we can update the shared pointer.
	shared_ptr<BSTNodeShared<int>> BuildBSTFromSortedDoublyListHelper(shared_ptr<BSTNodeShared<int>>* l, int start, int end)
	{
		// if note is that end is actually one past the index of the last element.
		if (start >= end)
			return nullptr;

		// mid will be the index of the root node.
		int mid = start + ((end - start) / 2);
		auto left = BuildBSTFromSortedDoublyListHelper(l, start, mid); // Build the left tree from start to mid.
		auto root = *l; // now l has been advanced to the new root.
		// TRICKY: The last function call sets l to the successor of the maximum node in the tree rooted at left.
		*l = (*l)->right; // move iterator pointer to the first node on the right side.
		root->left = left; // assign left side.
		// Don't forget the +1. The range is inclusive and we don't want to add mid twice.
		root->right = BuildBSTFromSortedDoublyListHelper(l, mid + 1, end);
		return root;
	}

	// Returns the root of the corresponding BST. The prev and next fields of the list nodes are used as the BST nodes left and right fields, respectively. The length of the list is given.
	shared_ptr<BSTNodeShared<int>> BuildBSTFromSortedDoublyList(shared_ptr<BSTNodeShared<int>> l, int length)
	{
		return BuildBSTFromSortedDoublyListHelper(&l, 0, length);
	}
}