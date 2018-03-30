// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> ZippingLinkedList( const shared_ptr<ListNode<int>>& l )
	{
		if ( !l || !l->next )
			return l;

		// find middle point.
		auto slow = l, fast = l;
		while ( fast && fast->next )
			slow = slow->next, fast = fast->next->next;

		// break list into two parts, reverse second part.
		// we can avoid needing a prevSlow if we just break the list at slow, and start the second list at slow->next.
		auto first = slow->next, head = slow->next;
		slow->next = nullptr;
		while ( first->next )
		{
			auto temp = first->next;
			first->next = temp->next;
			temp->next = head;
			head = temp;
		}

		// interleave both parts.
		auto firstHalf = l;
		auto secondHalf = head;
		while ( firstHalf )
		{
			auto temp = firstHalf->next;
			if ( secondHalf )
			{
				firstHalf->next = secondHalf;
				secondHalf = secondHalf->next;
				firstHalf->next->next = temp;
			}
			firstHalf = temp;
		}
		return l;
	}
}