// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"
#include "Solutions/8_LinkedLists/8.1_merge_sorted_lists_solution.h"

#define TEST 0

shared_ptr<ListNode<int>> StableSortList(shared_ptr<ListNode<int>> l)
{
	return nullptr;
}

#pragma region Test

void StableSortListTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 100; ++times)
	{
		shared_ptr<ListNode<int>> L = nullptr;
		int n;
		uniform_int_distribution<int> dis(0, 99);
		n = dis(gen);
		for (int i = n; i > 0; --i)
		{
			shared_ptr<ListNode<int>> temp =
				make_shared<ListNode<int>>(ListNode<int>{dis(gen), nullptr});
			temp->next = L;
			L = temp;
		}

		auto sorted_head = StableSortList(L);
		int count = 0;
		int pre = numeric_limits<int>::min();
		while (sorted_head)
		{
			assert(pre <= sorted_head->data);
			pre = sorted_head->data;
			sorted_head = sorted_head->next;
			++count;
		}
		assert(count == n);
	}
#endif
}

#pragma endregion Test
