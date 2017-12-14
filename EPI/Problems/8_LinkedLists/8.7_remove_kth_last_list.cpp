// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

#define TEST 0

// Assumes L has at least k nodes, deletes the k-th last node in l. k starts at 1.
shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>>& l, int k)
{
	return nullptr;
}

#pragma region Test

void RemoveKthLastTest()
{
#if TEST
	shared_ptr<ListNode<int>> L;
	L = make_shared<ListNode<int>>(ListNode<int>{
		1, make_shared<ListNode<int>>(ListNode<int>{
			2, make_shared<ListNode<int>>(ListNode<int>{3, nullptr})})});
	L = RemoveKthLast(L, 2);
	assert(L->data == 1 && L->next->data == 3);
	L = RemoveKthLast(L, 2);
	assert(L->data == 3 && L->next == nullptr);
	L = RemoveKthLast(L, 1);
	assert(L == nullptr);
#endif
}

#pragma endregion Test
