// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

#define TEST 0

bool IsLinkedListAPalindrome( shared_ptr<ListNode<int>> l ) 
{
	return true;
}

#pragma region Test

void IsLinkedListAPalindromeTest()
{
#if TEST
	assert( IsLinkedListAPalindrome( nullptr ) == true );
	assert( IsLinkedListAPalindrome(
		make_shared<ListNode<int>>( ListNode<int>{1, nullptr} ) ) == true );
	assert( IsLinkedListAPalindrome( make_shared<ListNode<int>>( ListNode<int>{
		1, make_shared<ListNode<int>>( ListNode<int>{1, nullptr} )} ) ) ==
		true );
	assert( IsLinkedListAPalindrome( make_shared<ListNode<int>>( ListNode<int>{
		1, make_shared<ListNode<int>>( ListNode<int>{2, nullptr} )} ) ) ==
		false );
	assert( IsLinkedListAPalindrome( make_shared<ListNode<int>>( ListNode<int>{
		1, make_shared<ListNode<int>>( ListNode<int>{
			3, make_shared<ListNode<int>>( ListNode<int>{
				2, make_shared<ListNode<int>>(
					ListNode<int>{1, nullptr} )} )} )} ) ) == false );

	shared_ptr<ListNode<int>> head = nullptr;
	// A link list is a palindrome.
	for ( int i = 6; i >= 1; --i ) 
	{
		shared_ptr<ListNode<int>> curr = make_shared<ListNode<int>>( ListNode<int>{1, head} );
		head = curr;
	}
	assert( IsLinkedListAPalindrome( head ) == true );

	// Still a palindrome linked list.
	head = shared_ptr<ListNode<int>>( nullptr );
	for ( int i = 5; i >= 1; --i ) 
	{
		shared_ptr<ListNode<int>> curr = make_shared<ListNode<int>>( ListNode<int>{1, head} );
		head = curr;
	}
	head->next->next->data = 3;
	assert( IsLinkedListAPalindrome( head ) == true );

	// Not a palindrome linked list.
	head = nullptr;
	for ( int i = 5; i >= 1; --i ) 
	{
		shared_ptr<ListNode<int>> curr = make_shared<ListNode<int>>( ListNode<int>{i, head} );
		head = curr;
	}
	assert( IsLinkedListAPalindrome( head ) == false );
#endif
}

#pragma endregion
