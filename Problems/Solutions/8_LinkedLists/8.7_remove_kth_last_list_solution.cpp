// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	// Assumes L has at least k nodes, deletes the k-th last node in L.
	shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>>& L, int k)
	{
		auto dummyHead = make_shared<ListNode<int>>(ListNode<int>{0, L});
		auto first = dummyHead->next;
		while (k--)
			first = first->next;

		auto second = dummyHead;
		while (first)
			second = second->next, first = first->next;

		// second points to the (k + 1)-th last node, deletes its successor.
		second->next = second->next->next;
		return dummyHead->next;
	}
}
