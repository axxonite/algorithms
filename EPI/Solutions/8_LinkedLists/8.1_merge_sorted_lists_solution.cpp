#include "stdafx.h"
#include "LinkedListPrototype.h"
#include "BSTPrototype.h"

using namespace std;

namespace Solutions
{
	// don't think this should be a function.
	void AppendNode(shared_ptr<ListNode<int>>* node, shared_ptr<ListNode<int>>* tail)
	{
		(*tail)->next = *node; // attach node to tail
		*tail = (*tail)->next; // node is new tail
		*node = (*node)->next; // node is next node.
	}

	shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2)
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

	void AppendNode(shared_ptr<BSTNodeShared<int>>* node, shared_ptr<BSTNodeShared<int>>* tail)
	{
		(*tail)->right = *node; // attach node to tail
		(*node)->left = *tail;
		*tail = (*tail)->right; // node is new tail
		*node = (*node)->right; // node is next node.
	}

	shared_ptr<BSTNodeShared<int>> MergeTwoSortedLists(shared_ptr<BSTNodeShared<int>> l1, shared_ptr<BSTNodeShared<int>> l2, int& length)
	{
		// Creates a placeholder for the result.
		shared_ptr<BSTNodeShared<int>> dummyHead(new BSTNodeShared<int>);
		auto tail = dummyHead;

		length = 0;
		while (l1 && l2)
			AppendNode(l1->data <= l2->data ? &l1 : &l2, &tail), ++length;

		// Appends the remaining nodes of l1 or l2.
		tail->right = l1 ? l1 : l2;
		return dummyHead->right;
	}
}
