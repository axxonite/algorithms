// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	// Assumes l has at least k nodes, deletes the k-th last node in l.
	shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>>& l, int k)
	{
		// create a dummy head and attach the list to the front of it.
		auto dummyHead = make_shared<ListNode<int>>(ListNode<int>{0, l});
		auto first = dummyHead->next;
		while (k--)
			first = first->next; // advance iterator by k steps

		// now advance both until we reach the end of the list on the first iterator, and the second iterator will be k steps behind.
		// we we want the second iterator to be at k-1, so that we can unlink the kth node from it.
		auto second = dummyHead;
		while (first)
			second = second->next, first = first->next;

		// second points to the (k + 1)-th last node, deletes its successor.
		second->next = second->next->next;
		return dummyHead->next;
	}
}
