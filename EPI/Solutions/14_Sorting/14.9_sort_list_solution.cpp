// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"
#include "Solutions/8_LinkedLists/8.1_merge_sorted_lists_solution.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> StableSortList(shared_ptr<ListNode<int>> l)
	{
		// Base cases: l is empty or a single node, nothing to do.
		if (l == nullptr || l->next == nullptr)
			return l;

		// Find the midpoint of l using a slow and a fast pointer. Keep track of the node before the slow pointer so we can split the list starting at that point.
		shared_ptr<ListNode<int>> slowPrev = nullptr, slow = l, fast = l;
		while (fast && fast->next)
		{
			slowPrev = slow;
			fast = fast->next->next, slow = slow->next;
		}

		slowPrev->next = nullptr; // Split the list into two equal-sized lists.

		return MergeTwoSortedLists(StableSortList(l), StableSortList(slow));
	}
}
