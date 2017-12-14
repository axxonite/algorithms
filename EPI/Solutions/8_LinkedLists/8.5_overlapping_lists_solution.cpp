// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"
#include "Solutions/8_LinkedLists/8.4_overlapping_lists_no_cycle_solution.h"
#include "Solutions/8_LinkedLists/8.3_checking_cycle_solution.h"

namespace Solutions
{
	// Calculates the distance between a and b.
	int Distance(shared_ptr<ListNode<int>> a, shared_ptr<ListNode<int>> b)
	{
		int dis = 0;
		while (a != b)
			a = a->next, ++dis;
		return dis;
	}

	shared_ptr<ListNode<int>> OverlappingLists(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2)
	{
		// Store the start of cycles, if any.
		auto cycle1 = Solutions::HasCycle(l1), cycle2 = Solutions::HasCycle(l2);
		if (!cycle1 && !cycle2)
			return Solutions::OverlappingNoCycleLists(l1, l2); // Both lists don't have cycles.
		if ((cycle1 && !cycle2) || (!cycle1 && cycle2))
			return nullptr; // Only one of the two lists has a cycle, so they don't overlap.

		// Both lists have cycles. Check if, running through one cycle, we encounter the other.
		auto temp = cycle2;
		do
		{
			temp = temp->next;
		} while (temp != cycle1 && temp != cycle2);

		if (temp != cycle1)
			return nullptr; // We didn't, so cycles are disjoint.

		// l1 and l2 end in the same cycle, locate the overlapping node if they first overlap before cycle starts.
		int stem1Length = Distance(l1, cycle1), stem2Length = Distance(l2, cycle2); // Find out how far from each head the start of each cycle is.
		Solutions::AdvanceListByK(abs(stem1Length - stem2Length), stem1Length > stem2Length ? &l1 : &l2); // Advance by the difference in length between the start of each cycle.
		while (l1 != l2 && l1 != cycle1 && l2 != cycle2) // Continue until we've either reached the overlap, or the start or either cycle.
			l1 = l1->next, l2 = l2->next;

		// If l1 == l2 before reaching either cycle, it means the overlap first occurs before the cycle starts; otherwise, the first overlapping node is not unique, so we can return any node on the cycle.
		return l1 == l2 ? l1 : cycle1;
	}
}
