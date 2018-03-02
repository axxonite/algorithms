// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool IsWellFormed( const string& s )
	{
		unordered_map<char, char> pairings = { { ')', '(' },{ ']', '[' },{ '}', '{' } };
		stack<char> opening;
		for ( auto c : s )
		{
			auto it = pairings.find( c );
			if ( it != pairings.end() )
			{
				if ( opening.empty() || opening.top() != it->second )
					return false;
				opening.pop();
			}
			else opening.emplace( c );
		}
		return opening.empty();
	}
}