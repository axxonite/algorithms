// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

class PostingListNode 
{
public:
	int order;
	shared_ptr<PostingListNode> next, jump;
};

void SetJumpOrderRecursive( const shared_ptr<PostingListNode>& L ) 
{
}

void SetJumpOrderIterative( const shared_ptr<PostingListNode>&L )
{
}

#pragma region Test

shared_ptr<PostingListNode> BuildList()
{
	shared_ptr<PostingListNode> L = nullptr, curr;
	curr = L;
	// Build a linked list L->1->2->3->4->5->nullptr.
	for ( size_t i = 0; i < 5; ++i )
	{
		shared_ptr<PostingListNode> temp = make_shared<PostingListNode>( PostingListNode{ -1, nullptr, nullptr } );
		if ( curr )
		{
			curr->next = temp;
			curr = temp;
		}
		else
			curr = L = temp;
	}
	L->jump = nullptr;  // no jump from 1
	L->next->jump = L->next->next->next;  // 2's jump points to 4
	L->next->next->jump = L;  // 3's jump points to 1
	L->next->next->next->jump = nullptr;  // no jump from 4
	L->next->next->next->next->jump =
		L->next->next->next->next;  // 5's jump points to 5
	return L;
}

void SetJumpOrderTest()
{
#ifdef TEST
	auto L = BuildList();
	shared_ptr<PostingListNode> temp = L;
	SetJumpOrderRecursive( L );
	// output the jump-first order, it should be 0, 1, 4, 2, 3
	assert( temp->order == 0 );
	temp = temp->next;
	assert( temp->order == 1 );
	temp = temp->next;
	assert( temp->order == 4 );
	temp = temp->next;
	assert( temp->order == 2 );
	temp = temp->next;
	assert( temp->order == 3 );
	L = BuildList();
	temp = L;
	SetJumpOrderIterative( L );
	// output the jump-first order, it should be 0, 1, 4, 2, 3
	assert( temp->order == 0 );
	temp = temp->next;
	assert( temp->order == 1 );
	temp = temp->next;
	assert( temp->order == 4 );
	temp = temp->next;
	assert( temp->order == 2 );
	temp = temp->next;
	assert( temp->order == 3 );
#endif
}

#pragma endregion