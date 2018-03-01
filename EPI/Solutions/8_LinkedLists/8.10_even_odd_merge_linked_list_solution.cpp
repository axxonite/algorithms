// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "LinkedListPrototype.h"

namespace Solutions
{
	shared_ptr<ListNode<int>> EvenOddMerge( const shared_ptr<ListNode<int>>& L )
	{
		if ( !L || !L->next )
			return L;
		auto oddFirst = L->next;
		// Note the use of an array so we can just index directly without specifically referring to even/odd.
		array<shared_ptr<ListNode<int>>, 2> tails = { L, L->next };
		auto cur = L->next->next;
		int index = 0;
		while ( cur )
		{
			tails[index % 2] = tails[index % 2]->next = cur;
			cur = cur->next, ++index;
		}
		tails[0]->next = oddFirst;
		tails[1]->next = nullptr; // don't forget to make sure the last odd note is not still linked to its next even node.
		return L;
	}
}