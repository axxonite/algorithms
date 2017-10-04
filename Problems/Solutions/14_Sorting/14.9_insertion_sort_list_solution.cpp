// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> InsertionSort(const shared_ptr<ListNode<int>>& l)
	{
		auto dummyHead = make_shared<ListNode<int>>(ListNode<int>{0, l});
		auto it = l;
		// The sublist consisting of nodes up to and including it is sorted in increasing order. We need to ensure that after we move to it->next
		// this property continues to hold. We do this by swapping it->next with its predecessors in the list till it's in the right place.
		while (it && it->next)
		{
			if (it->data > it->next->data)
			{
				auto target = it->next, pre = dummyHead;
				while (pre->next->data < target->data)
					pre = pre->next;
				auto temp = pre->next;
				pre->next = target;
				it->next = target->next;
				target->next = temp;
			}
			else
				it = it->next;
		}
		return dummyHead->next;
	}
}
