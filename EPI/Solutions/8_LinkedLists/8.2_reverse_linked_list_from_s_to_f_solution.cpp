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
		// IMPORTANT: sublist head is node start - 1. It is before the first node to be reversed. suvblist head does not move.
		auto subListHead = dummyHead;
		for (int k = 1; k < start; ++k)
			subListHead = subListHead->next;

		// Reverses sublist.
		auto it = subListHead->next; // first node to be reversed is this. If k = 1 then this is l.
		while (start++ < end)
		{
			auto newFirst = it->next; // newFirst is the node we will move around. it will end up after newFirst
			it->next = newFirst->next;  // detach newFirst from chain, and ensure newFirst->next is the next node we will process.
			// place newFirst(old it->next) before subListHead->next
			newFirst->next = subListHead->next; // Link the first node in the sublist to the newFirst node.
			subListHead->next = newFirst; // make newFirst the first sublist node.
		}
		return dummyHead->next;
	}
	
}