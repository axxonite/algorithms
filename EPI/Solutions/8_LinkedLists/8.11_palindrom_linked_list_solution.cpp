// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	// When we are reversing an entire list instead of a sublist, the logic is much simpler.
	// We cannot get the list back to its original form with this method however.
	shared_ptr<ListNode<int>> ReverseLinkedList( shared_ptr<ListNode<int>> cur )
	{
		shared_ptr<ListNode<int>> prev = nullptr;
		while ( cur )
		{
			auto next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}

	bool IsLinkedListAPalindrome( shared_ptr<ListNode<int>> L )
	{
		if ( !L || !L->next )
			return true;
		shared_ptr<ListNode<int>> slow = L, fast = L;
		// The following line is CRITICAL - really hard to get this right.
		while ( fast && fast->next )
			slow = slow->next, fast = fast->next->next;

		auto firstRev = slow;
		auto rev = ReverseLinkedList( slow );
		auto cur1 = L, cur2 = rev;
		while ( cur1 && cur2 )
		{
			if ( cur1->data != cur2->data )
				return false;
			cur1 = cur1->next, cur2 = cur2->next;
		}
		return true;
	}
}