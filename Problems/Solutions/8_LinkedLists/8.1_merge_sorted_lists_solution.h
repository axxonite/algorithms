#pragma once

#include "LinkedListPrototype.h"

using namespace std;

namespace Solutions
{
	// don't think this should be a function.
	inline void AppendNode(shared_ptr<ListNode<int>>* node, shared_ptr<ListNode<int>>* tail)
	{
		(*tail)->next = *node; // attach node to tail
		*tail = *node; // node is new tail
		*node = (*node)->next; // node is next node.
	}

	inline shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2)
	{
		// Creates a placeholder for the result.
		shared_ptr<ListNode<int>> dummyHead(new ListNode<int>);
		auto tail = dummyHead;

		while (l1 && l2)
			AppendNode(l1->data <= l2->data ? &l1 : &l2, &tail);

		// Appends the remaining nodes of l1 or l2.
		tail->next = l1 ? l1 : l2;
		return dummyHead->next;
	}
}
