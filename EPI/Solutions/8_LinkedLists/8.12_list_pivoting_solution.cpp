// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> ListPivoting( const shared_ptr<ListNode<int>>& L, int x )
	{
		// Don't forget to initialize the next ptr on each list node.
		shared_ptr<ListNode<int>> lesserDummyHead = make_shared<ListNode<int>>( ListNode<int> {0, nullptr} );
		shared_ptr<ListNode<int>> equalDummyHead = make_shared<ListNode<int>>( ListNode<int> { 0, nullptr } );
		shared_ptr<ListNode<int>> greaterDummyHead = make_shared<ListNode<int>>( ListNode<int> { 0, nullptr } );
		auto cur = L, less = lesserDummyHead, equal = equalDummyHead, greater = greaterDummyHead;
		while ( cur )
		{
			if ( cur->data < x )
				less->next = cur, less = cur;
			else if ( cur->data > x )
				greater->next = cur, greater = cur;
			else equal->next = cur, equal = cur;
			cur = cur->next;
		}
		// Linking the equal list first allows us to link it to the less list without worry that the equal list might be empty while the greater list might be non-empty.
		equal->next = greaterDummyHead->next;
		less->next = equalDummyHead->next;
		return lesserDummyHead->next;
	}
}