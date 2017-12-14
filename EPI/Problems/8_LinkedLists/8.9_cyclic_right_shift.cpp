// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

#define TEST 0

shared_ptr<ListNode<int>> CyclicallyRightShiftList(shared_ptr<ListNode<int>> l, int k)
{
	return nullptr;
}

#pragma region Test

void CyclicallyRightShiftListSimpleTest()
{
	shared_ptr<ListNode<int>> L;
	L = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
	auto result = CyclicallyRightShiftList(L, 2);
	assert(result == L);
	L->next = make_shared<ListNode<int>>(ListNode<int>{2, nullptr});
	result = CyclicallyRightShiftList(L, 2);
	assert(result == L);
	result = CyclicallyRightShiftList(L, 3);
	assert(result->next == L);
}

void CyclicallyRightShiftListTest()
{
#if TEST
	CyclicallyRightShiftListSimpleTest();
	shared_ptr<ListNode<int>> L;
	L = make_shared<ListNode<int>>(ListNode<int>{
		1, make_shared<ListNode<int>>(ListNode<int>{
			2, make_shared<ListNode<int>>(ListNode<int>{3, nullptr})})});
	auto result = CyclicallyRightShiftList(L, 2);
	assert(result->data == 2 && result->next->data == 3 &&
		result->next->next->data == 1 && !result->next->next->next);
#endif
}

#pragma endregion Test
