// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#pragma once

#include "stdafx.h"
#include "LinkedListPrototype.h"
#include "Solutions/8_LinkedLists/8.4_overlapping_lists_no_cycle_solution.h"

int Length(shared_ptr<ListNode<int>> l)
{
	int n = 1;
	while (l->next)
		n++, l = l->next;
	return n;
}

int AdvanceList(int k, shared_ptr<ListNode<int>>* l)
{
	while (k--)
		(*l) = (*l)->next;
}

inline shared_ptr<ListNode<int>> OverlappingNoCycleLists(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2)
{
	int l1Length = Length(l1), l2Length = Length(l2);
	AdvanceList(abs(l1Length - l2Length), l1Length > l2Length ? &l1: &l2);
	while (l1 && l2 && l1 != l2)
		l1 = l1->next, l2 = l2->next;
	return l1;
	return Solutions::OverlappingNoCycleLists(l1, l2);
}
