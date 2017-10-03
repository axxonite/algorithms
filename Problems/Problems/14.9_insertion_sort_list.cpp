// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

#define TEST 0

shared_ptr<ListNode<int>> InsertionSort(const shared_ptr<ListNode<int>>& l)
{
	return nullptr;
}

#pragma region Test

void InsertionSortTest()
{
#if TEST
	shared_ptr<ListNode<int>> L;
	L = make_shared<ListNode<int>>(ListNode<int>{
		1, make_shared<ListNode<int>>(ListNode<int>{
			4, make_shared<ListNode<int>>(ListNode<int>{
				3, make_shared<ListNode<int>>(ListNode<int>{
					2, make_shared<ListNode<int>>(
						ListNode<int>{5, nullptr})})})})});
	auto result = InsertionSort(L);
	shared_ptr<ListNode<int>> pre = nullptr;
	while (result)
	{
		assert(!pre || pre->data <= result->data);
		pre = result;
		cout << result->data << endl;
		result = result->next;
	}
#endif
}

#pragma endregion Test