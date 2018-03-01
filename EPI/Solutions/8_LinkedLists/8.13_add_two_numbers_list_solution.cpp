// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> AddTwoNumbers( shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2 )
	{
		auto dummyHead = make_shared<ListNode<int>>( ListNode<int> {0, nullptr} );
		auto resultIter = dummyHead;
		int carry = 0;
		while ( L1 || L2 || carry > 0 )
		{
			int value = carry + ( L1 ? L1->data : 0 ) + ( L2 ? L2->data : 0 );
			resultIter->next = make_shared <ListNode<int>>( ListNode<int> {value % 10, nullptr} );
			L1 = L1 ? L1->next : L1;
			L2 = L2 ? L2->next : L2;
			resultIter = resultIter->next;
			carry = value / 10;
		}
		return dummyHead->next;
	}
}