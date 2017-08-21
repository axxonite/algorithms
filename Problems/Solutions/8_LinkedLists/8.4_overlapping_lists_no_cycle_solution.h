// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#pragma once

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	inline int Length(shared_ptr<ListNode<int>> l)
	{
		int length = 0;
		while (l)
			++length, l = l->next;
		return length;
	}

	// Advances l by k steps.
	inline void AdvanceListByK(int k, shared_ptr<ListNode<int>>* l)
	{
		while (k--)
			*l = (*l)->next;
	}

	inline shared_ptr<ListNode<int>> OverlappingNoCycleLists(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2)
	{
		int l1Length = Length(l1), l2Length = Length(l2);
		// Advances the longer list to get equal length lists.
		AdvanceListByK(abs(l1Length - l2Length), l1Length > l2Length ? &l1 : &l2);
		// Note that lists overlap only if they have the same tail node; once the lists converge at a node, they cannot diverge at a later node.
		while (l1 && l2 && l1 != l2)
			l1 = l1->next, l2 = l2->next;
		return l1; // nullptr implies there is no overlap between l1 and l2.
	}
}
