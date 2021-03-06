// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

// #define TEST

void DeletionFromList( const shared_ptr<ListNode<int>>& node ) 
{
}

#pragma region Test

void DeletionFromListTest()
{
#ifdef TEST
	shared_ptr<ListNode<int>> L;
	L = make_shared<ListNode<int>>( ListNode<int>{
		1, make_shared<ListNode<int>>( ListNode<int>{
			2, make_shared<ListNode<int>>( ListNode<int>{3, nullptr} )} )} );
	DeletionFromList( L );
	assert( L->data == 2 && L->next->data == 3 );
#endif
}

#pragma endregion