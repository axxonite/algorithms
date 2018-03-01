// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> RemoveDuplicates( const shared_ptr<ListNode<int>>& L )
	{
		if ( !L || !L->next )
			return L;
		auto last = L;
		auto cur = L->next;
		while ( cur )
		{
			if ( last->data == cur->data )
				last->next = cur->next;
			else last = cur;
			cur = cur->next;
		}
		return L;
	}
}