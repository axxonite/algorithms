// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start, int finish)
	{
		auto dummyHead = make_shared<ListNode<int>>(ListNode<int>{0, L});
		auto subListHead = dummyHead;
		int k = 1;
		while (k++ < start)
			subListHead = subListHead->next;

		// Reverses sublist.
		auto subListIter = subListHead->next;
		while (start++ < finish)
		{
			auto temp = subListIter->next;
			subListIter->next = temp->next;
			temp->next = subListHead->next;
			subListHead->next = temp;
		}
		return dummyHead->next;
	}
	
}