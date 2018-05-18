// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	void DeletionFromList(const shared_ptr<ListNode<int>>& node)
	{
		node->data = node->next->data;
		node->next = node->next->next;
	}
}