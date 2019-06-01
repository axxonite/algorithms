// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

// #define TEST

shared_ptr<ListNode<int>> ZippingLinkedList(const shared_ptr<ListNode<int>>& l)
{
	return nullptr;
}

#pragma region Test

void ZippingLinkedListTest()
{
#ifdef TEST
	default_random_engine gen((random_device())());
	shared_ptr<ListNode<int>> head = nullptr;
	int n;
	uniform_int_distribution<int> dis(1, 250);
	n = dis(gen);
	for (int i = n; i >= 0; --i)
	{
		auto curr = make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
		curr->next = head;
		head = curr;
	}
	shared_ptr<ListNode<int>> curr = ZippingLinkedList(head);
	int idx = 0, pre;
	while (curr)
	{
		if (idx % 2)
			assert(pre + curr->data == n);
		++idx;
		cout << curr->data << endl;
		pre = curr->data;
		curr = curr->next;
	}
#endif
}

#pragma endregion Test
