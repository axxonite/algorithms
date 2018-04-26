// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#pragma once

#include <memory>
#include "LinkedListPrototype.h"

namespace Solutions
{
	inline shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>>& head)
	{
		shared_ptr<ListNode<int>> fast = head, slow = head;

		while (fast && fast->next)
		{
			// fast iterator moves twice as fast as slow iterator.
			slow = slow->next , fast = fast->next->next;
			if (slow == fast)
			{
				// There is a cycle, so now let's calculate the cycle length.
				int cycle_len = 1;
				fast = fast->next;
				while (slow != fast)
					++cycle_len, fast = fast->next;

				// Setup a cycle iterator set to forward by the length of the cycle, from the head.
				auto cycleIter = head;
				while (cycle_len--)
					cycleIter = cycleIter->next;

				auto iter = head;
				// Advance both iterators in tandem. Once they match, we have found the cycle start.
				while (iter != cycleIter)
					iter = iter->next , cycleIter = cycleIter->next;
				return iter;
			}
		}
		return nullptr; // No cycle.
	}
}
