// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

// #define TEST

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> l, int start, int end)
{
  return nullptr;
}

#pragma region Test

void ReverseSublistSimpleTest()
{
	shared_ptr<ListNode<int>> L = nullptr;
	auto result = ReverseSublist(L, 0, 0);
	assert(result == nullptr);

	L = make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
	result = ReverseSublist(L, 0, 0);
	assert(result == L && result->next == nullptr);

	L = make_shared<ListNode<int>>(ListNode<int>{
		1, make_shared<ListNode<int>>(ListNode<int>{
			2, make_shared<ListNode<int>>(ListNode<int>{3, nullptr})})});
	result = ReverseSublist(L, 0, 1);
	assert(result->data == 2 && result->next->data == 1 &&
		result->next->next->data == 3 &&
		result->next->next->next == nullptr);

	L = make_shared<ListNode<int>>(ListNode<int>{
		1, make_shared<ListNode<int>>(ListNode<int>{
			2, make_shared<ListNode<int>>(ListNode<int>{3, nullptr})})});
	result = ReverseSublist(L, 0, 2);
	assert(result->data == 3 && result->next->data == 2 &&
		result->next->next->data == 1 &&
		result->next->next->next == nullptr);
}

void ReverseSublistTest()
{
#ifdef TEST
	ReverseSublistSimpleTest();
	shared_ptr<ListNode<int>> L = make_shared<ListNode<int>>(ListNode<int>{
		1, make_shared<ListNode<int>>(ListNode<int>{
			2, make_shared<ListNode<int>>(ListNode<int>{3, nullptr})})});
	auto result = ReverseSublist(L, 3, 3);
	assert(result->data == 1 && result->next->data == 2 &&
		result->next->next->data == 3 && !result->next->next->next);
	while (result)
	{
		cout << result->data << endl;
		result = result->next;
	}

	result = ReverseSublist(L, 2, 3);
	assert(result->data == 1 && result->next->data == 3 &&
		result->next->next->data == 2 && !result->next->next->next);
	while (result)
	{
		cout << result->data << endl;
		result = result->next;
	}

	L = make_shared<ListNode<int>>(ListNode<int>{
		3, make_shared<ListNode<int>>(ListNode<int>{5, nullptr})});
	result = ReverseSublist(L, 1, 2);
	assert(result->data == 5 && result->next->data == 3 && !result->next->next);
	while (result)
	{
		cout << result->data << endl;
		result = result->next;
	}
#endif
}

#pragma endregion Test
