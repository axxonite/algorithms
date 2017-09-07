// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"
#include "Solutions/8_LinkedLists/8.4_overlapping_lists_no_cycle_solution.h"
#include "Solutions/8_LinkedLists/8.3_checking_cycle_solution.h"

#define TEST 0

shared_ptr<ListNode<int>> OverlappingLists(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2)
{
	return nullptr;
}

#pragma region Test

void OverlappingListsSmallTest()
{
	shared_ptr<ListNode<int>> L1, L2;
	// l1: 1->2->3->4->5->6-
	//              ^  ^    |
	//              |  |____|
	// l2: 7->8-----
	L1 = make_shared<ListNode<int>>(ListNode<int>{
		1, make_shared<ListNode<int>>(ListNode<int>{
			2, make_shared<ListNode<int>>(ListNode<int>{
				3, make_shared<ListNode<int>>(ListNode<int>{
					4, make_shared<ListNode<int>>(ListNode<int>{
						5, make_shared<ListNode<int>>(
							ListNode<int>{6, nullptr})})})})})});
	L1->next->next->next->next->next->next = L1->next->next->next->next;

	L2 = make_shared<ListNode<int>>(ListNode<int>{
		7, make_shared<ListNode<int>>(ListNode<int>{8, nullptr})});
	L2->next->next = L1->next->next->next;
	assert(OverlappingLists(L1, L2)->data == 4);

	// l1: 1->2->3->4->5->6-
	//           ^     ^    |
	//           |     |____|
	// l2: 7->8---
	L2->next->next = L1->next->next;
	assert(OverlappingLists(L1, L2)->data == 3);
}

void OverlappingListsTest()
{
#if TEST
	OverlappingListsSmallTest();
	shared_ptr<ListNode<int>> L1, L2;
	// l1: 1->2->3->null
	L1 = make_shared<ListNode<int>>(ListNode<int>{
		1, make_shared<ListNode<int>>(ListNode<int>{
			2, make_shared<ListNode<int>>(ListNode<int>{3, nullptr})})});
	L2 = L1->next->next;
	assert(OverlappingLists(L1, L2)->data == 3);
	// l2: 4->5->null
	L2 = make_shared<ListNode<int>>(ListNode<int>{
		4, make_shared<ListNode<int>>(ListNode<int>{5, nullptr})});
	assert(!OverlappingLists(L1, L2));
	L1->next->next->next = L1;
	assert(!OverlappingLists(L1, L2));
	L2->next->next = L2;
	assert(!OverlappingLists(L1, L2));
	L2->next->next = L1;
	assert(OverlappingLists(L1, L2));
#endif
}

#pragma endregion Test
