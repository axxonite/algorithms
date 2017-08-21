// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#pragma once

#include "stdafx.h"
#include "LinkedListPrototype.h"
#include "Solutions/8_LinkedLists/8.4_overlapping_lists_no_cycle_solution.h"

inline shared_ptr<ListNode<int>> OverlappingNoCycleLists(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2)
{
	return Solutions::OverlappingNoCycleLists(l1, l2);
}
