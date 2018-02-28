// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

#define TEST 0

shared_ptr<ListNode<int>> RemoveDuplicates(const shared_ptr<ListNode<int>>& L ) 
{
	return nullptr;
}

#pragma region Test

void RemoveDuplicatesSimpleTest() {
	shared_ptr<ListNode<int>> L = nullptr;
	auto result = RemoveDuplicates( L );
	assert( result == nullptr );
	L = make_shared<ListNode<int>>( ListNode<int>{123, nullptr} );
	result = RemoveDuplicates( L );
	assert( result == L );
	L->next = make_shared<ListNode<int>>( ListNode<int>{123, nullptr} );
	result = RemoveDuplicates( L );
	assert( result->next == nullptr );

	// Creating an invalid input, 123 -> 124 -> 123, algo will not detect dups!
	L->next = make_shared<ListNode<int>>( ListNode<int>{124, nullptr} );
	L->next->next = make_shared<ListNode<int>>( ListNode<int>{123, nullptr} );
	result = RemoveDuplicates( L );
	assert( result->data == 123 && result->next->data == 124 &&
		result->next->next->data == 123 );
}

void RemoveDuplicatesTest()
{
#if TEST
	RemoveDuplicatesSimpleTest();
	shared_ptr<ListNode<int>> L = make_shared<ListNode<int>>( ListNode<int>{
		2, make_shared<ListNode<int>>( ListNode<int>{
			2, make_shared<ListNode<int>>( ListNode<int>{
				2, make_shared<ListNode<int>>( ListNode<int>{
					2, make_shared<ListNode<int>>(
						ListNode<int>{2, nullptr} )} )} )} )} );
	shared_ptr<ListNode<int>> pre = nullptr;
	auto result = RemoveDuplicates( L );
	int count = 0;
	while ( result ) 
	{
		++count;
		if ( pre )
			assert( pre->data != result->data );
		cout << result->data << endl;
		pre = result;
		result = result->next;
	}
	assert( count == 1 );
#endif
}

#pragma endregion
