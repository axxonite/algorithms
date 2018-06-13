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

	shared_ptr<ListNode<int>> ReverseList2(shared_ptr<ListNode<int>> l)
	{
		shared_ptr<ListNode<int>> last = nullptr;
		while (l)
		{
			auto next = l->next;
			l->next = last;
			last = l;
			l = next;
		}
		return last;
	}

	shared_ptr<ListNode<int>> ZippingLinkedList2(const shared_ptr<ListNode<int>>& l)
	{
		// find the midpoint of the list with a slow and a fast iterator.
		auto slow = l, fast = l;
		while (fast && fast->next)
			slow = slow->next, fast = fast->next->next;

		// Reverse the second half of the list.
		auto reversed = ReverseList2(slow);

		shared_ptr<ListNode<int>> dummyHead = make_shared<ListNode<int>>(ListNode<int>{ 0, nullptr });
		// Iterator on the left and right halves simultaneously.
		auto cur = l, cur2 = reversed, dst = dummyHead;
		while (cur || cur2)
		{
			// Add the ith node, followed by the (n - i) node.
			dst->next = cur;
			cur = cur->next;
			if (cur2)
			{
				dst->next = cur2;
				cur2 = cur2->next;
			}
		}
		return dummyHead->next;
	}
}