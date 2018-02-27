// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	string LookAndSay( string s )
	{
		string result;
		for ( int i = 0; i < s.size(); ++i )
		{
			int count = 1;
			// Note how we can compare with the next character to avoid having to store the last character seen.
			while ( i + 1 < s.size() && s[i + 1] == s[i] )
				++i, ++count;
			result += to_string( count ) + s[i];
		}
		return result;
	}

	string LookAndSay( int n )
	{
		// Note how we can call the same function iteratively n times - though recursion seems like a natural way to define the problem, we don't need to.
		string s = "1";
		for ( int i = 1; i < n; ++i )
			s = LookAndSay( s );
		return s;
	}
}