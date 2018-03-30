// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	class PostingListNode
	{
	public:
		int order;
		shared_ptr<PostingListNode> next, jump;
	};

	shared_ptr<PostingListNode> CopyPostingsList( const shared_ptr<PostingListNode>& L )
	{
		auto cur = L;
		while ( cur )
		{
			cur->next = make_shared<PostingListNode>( PostingListNode{ cur->order, cur->next, cur->jump } );
			cur = cur->next->next;
		}

		cur = L->next;
		while ( cur )
		{
			cur->jump = cur->jump ? cur->jump->next : nullptr;
			cur = cur->next ? cur->next->next : nullptr;
		}

		auto result = make_shared<PostingListNode>( PostingListNode{ 0, nullptr, nullptr } );
		cur = L;
		auto curCopy = result;
		while ( cur )
		{
			curCopy->next = cur->next; // add copy to list
			cur->next = cur->next->next; // remove copy from interleaved list.
			cur = cur->next; // move to next block.
			curCopy = curCopy->next; // move to next copy block.
		}
		curCopy->next = nullptr;
		return result->next;
	}
}