// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> CyclicallyRightShiftList(shared_ptr<ListNode<int>> l, int k)
	{
		if (l == nullptr)
			return l;

		// Computes the length of l and the tail.
		auto tail = l;
		int n = 1;
		while (tail->next)
			++n, tail = tail->next;
		k %= n;
		if (k == 0)
			return l; // A shift of k elements on n nodes will yield the same list.

		tail->next = l; // Makes a cycle by connecting the tail to the head.
		int stepsToNewHead = n - k;
		auto newTail = tail;
		while (stepsToNewHead--)
			newTail = newTail->next;
		auto newHead = newTail->next;
		newTail->next = nullptr;
		return newHead;
	}
}