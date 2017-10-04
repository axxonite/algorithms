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
		auto subListHead = dummyHead;
		for (int k = 1; k < start; ++k)
			subListHead = subListHead->next;

		// Reverses sublist.
		auto it = subListHead->next;
		while (start++ < end)
		{
			auto temp = it->next;
			it->next = temp->next;
			temp->next = subListHead->next;
			subListHead->next = temp;
		}
		return dummyHead->next;
	}
	
}