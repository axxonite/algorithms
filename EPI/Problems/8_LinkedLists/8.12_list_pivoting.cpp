// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

#define TEST 0

shared_ptr<ListNode<int>> ListPivoting( const shared_ptr<ListNode<int>>& L, int k ) 
{
	return nullptr;
}

#pragma region Test

void ListPivotingSimpleTest() {
	shared_ptr<ListNode<int>> L =
		make_shared<ListNode<int>>( ListNode<int>{0, nullptr} );
	auto result = ListPivoting( L, 0 );
	assert( result == L );
	result = ListPivoting( L, 1 );
	assert( result == L );
	result = ListPivoting( L, -1 );
	assert( result == L );

	L = make_shared<ListNode<int>>( ListNode<int>{
		2, make_shared<ListNode<int>>( ListNode<int>{0, nullptr} )} );
	result = ListPivoting( L, -1 );
	assert( result == L );

	L = make_shared<ListNode<int>>( ListNode<int>{
		2, make_shared<ListNode<int>>( ListNode<int>{0, nullptr} )} );
	result = ListPivoting( L, 1 );
	assert( result->data == 0 && result->next->data == 2 );

	L = make_shared<ListNode<int>>( ListNode<int>{
		2, make_shared<ListNode<int>>( ListNode<int>{
			0, make_shared<ListNode<int>>( ListNode<int>{-2, nullptr} )} )} );
	result = ListPivoting( L, 1 );
	assert( result->data == 0 && result->next->data == -2 &&
		result->next->next->data == 2 );
}

void ListPivotingTest()
{
#if TEST
	ListPivotingSimpleTest();
	shared_ptr<ListNode<int>> L;
	L = make_shared<ListNode<int>>( ListNode<int>{
		1, make_shared<ListNode<int>>( ListNode<int>{
			4, make_shared<ListNode<int>>( ListNode<int>{
				3, make_shared<ListNode<int>>( ListNode<int>{
					2, make_shared<ListNode<int>>(
						ListNode<int>{5, nullptr} )} )} )} )} );
	int x = 4;
	auto result = ListPivoting( L, x );
	cout << endl;
	bool before_x = true;
	while ( result ) {
		if ( result->data >= x ) 
			before_x = false;
		if ( before_x ) 
			assert( result->data < x );
		else 
			assert( result->data >= x );
		cout << result->data << endl;
		result = result->next;
	}
#endif
}

#pragma endregion
