// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

#define TEST 0

shared_ptr<ListNode<int>> AddTwoNumbers( shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2 ) 
{
	return nullptr;
}

#pragma region Test

void AddTwoNumbersSimpleTest() {
	shared_ptr<ListNode<int>> L;
	L = make_shared<ListNode<int>>( ListNode<int>{
		2, make_shared<ListNode<int>>( ListNode<int>{
			4, make_shared<ListNode<int>>( ListNode<int>{3, nullptr} )} )} );
	shared_ptr<ListNode<int>> R;
	R = make_shared<ListNode<int>>( ListNode<int>{0, nullptr} );
	auto S = AddTwoNumbers( L, R );
	assert( S->data == 2 && S->next->data == 4 && S->next->next->data == 3 );

	L = make_shared<ListNode<int>>( ListNode<int>{
		3, make_shared<ListNode<int>>( ListNode<int>{
			4, make_shared<ListNode<int>>( ListNode<int>{2, nullptr} )} )} );
	R = make_shared<ListNode<int>>( ListNode<int>{
		7, make_shared<ListNode<int>>( ListNode<int>{
			5, make_shared<ListNode<int>>( ListNode<int>{7, nullptr} )} )} );
	S = AddTwoNumbers( L, R );
	assert( S->data == 0 && S->next->data == 0 && S->next->next->data == 0 &&
		S->next->next->next->data == 1 );

	L = make_shared<ListNode<int>>( ListNode<int>{1, nullptr} );
	R = make_shared<ListNode<int>>( ListNode<int>{1, nullptr} );
	S = AddTwoNumbers( L, R );
	assert( S->data == 2 && S->next == nullptr );

	L = make_shared<ListNode<int>>( ListNode<int>{5, nullptr} );
	R = make_shared<ListNode<int>>( ListNode<int>{5, nullptr} );
	S = AddTwoNumbers( L, R );
	assert( S->data == 0 && S->next->data == 1 && S->next->next == nullptr );

	L = make_shared<ListNode<int>>( ListNode<int>{
		2, make_shared<ListNode<int>>( ListNode<int>{
			4, make_shared<ListNode<int>>( ListNode<int>{3, nullptr} )} )} );
	R = make_shared<ListNode<int>>( ListNode<int>{
		5, make_shared<ListNode<int>>( ListNode<int>{
			6, make_shared<ListNode<int>>( ListNode<int>{7, nullptr} )} )} );
	S = AddTwoNumbers( L, R );
	assert( S->data == 7 && S->next->data == 0 && S->next->next->data == 1 &&
		S->next->next->next->data == 1 );
	L = make_shared<ListNode<int>>( ListNode<int>{
		9, make_shared<ListNode<int>>( ListNode<int>{9, nullptr} )} );
	R = make_shared<ListNode<int>>( ListNode<int>{9, nullptr} );
	S = AddTwoNumbers( L, R );
	assert( S->data == 8 && S->next->data == 0 && S->next->next->data == 1 );
}

void AddTwoNumbersTest()
{
#if TEST
	AddTwoNumbersSimpleTest();
#endif
}

#pragma endregion