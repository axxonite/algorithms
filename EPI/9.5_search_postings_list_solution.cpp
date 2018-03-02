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

	void SetJumpOrderRecursive( const shared_ptr<PostingListNode>& L, int& index )
	{
		// Don't forget to check for a null pointer.
		if ( L && L->order == -1 )
		{
			L->order = index++;
			SetJumpOrderRecursive( L->jump, index );
			SetJumpOrderRecursive( L->next, index );
		}
	}

	void SetJumpOrderRecursive( const shared_ptr<PostingListNode>& L )
	{
		int index = 0;
		SetJumpOrderRecursive( L, index );
	}

	void SetJumpOrderIterative( const shared_ptr<PostingListNode>&L )
	{
		stack<shared_ptr<PostingListNode>> s;
		s.emplace( L );
		int index = 0;
		while ( !s.empty() )
		{
			auto cur = s.top();
			s.pop();
			// Don't forget to check for a null pointer.
			if ( cur && cur->order == -1 )
			{
				cur->order = index++;
				s.emplace( cur->next );
				s.emplace( cur->jump );
			}
		}
	}
}