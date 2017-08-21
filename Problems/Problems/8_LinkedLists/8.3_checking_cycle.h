// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#pragma once

#include <memory>
#include "LinkedListPrototype.h"
#include "Solutions/8.3_checking_cycle_solution.h"

shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>>& head)
{
	return Solutions::HasCycle(head);
}