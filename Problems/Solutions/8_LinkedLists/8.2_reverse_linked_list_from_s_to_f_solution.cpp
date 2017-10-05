// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> l, int start, int end)
	{
		// add a dummy head so we can handle the case properly where start or end is zero.
		auto dummyHead = make_shared<ListNode<int>>(ListNode<int>{0, l});
		// find sublist head (get to the nth node based on start, with 1 being the first node).
		// The sublist head is actually the node right before the first node that will be reversed. The sublist head does not move.
		auto subListHead = dummyHead;
		for (int k = 1; k < start; ++k)
			subListHead = subListHead->next;

		// Reverses sublist.
		auto it = subListHead->next; // first node to be reversed is this. If k = 1 then this is l.
		while (start++ < end)
		{
			auto newFirst = it->next; // temp is the node we will move around.
			it->next = newFirst->next;  // detach temp node from chain, and ensure temp->next is the next node we will process.
			// place newFirst(old it->next) before subListHead->next
			newFirst->next = subListHead->next; // Link the first node in the sublist to the temp node.
			subListHead->next = newFirst; // make temp the first sublist node.
		}
		return dummyHead->next;
	}
	
}