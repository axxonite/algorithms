// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> InsertionSort(const shared_ptr<ListNode<int>>& l)
	{
		auto dummyHead = make_shared<ListNode<int>>(ListNode<int>{0, l});
		auto iter = l;
		// The sublist consisting of nodes up to and including iter is sorted  increasing order. We need to ensure that after we move to iter->next
		// this property continues to hold. We do this by swapping iter->next with its predecessors in the list till it's in the right place.
		while (iter && iter->next)
		{
			if (iter->data > iter->next->data)
			{
				auto target = iter->next, pre = dummyHead;
				while (pre->next->data < target->data)
					pre = pre->next;
				auto temp = pre->next;
				pre->next = target;
				iter->next = target->next;
				target->next = temp;
			}
			else
				iter = iter->next;
		}
		return dummyHead->next;
	}
}
