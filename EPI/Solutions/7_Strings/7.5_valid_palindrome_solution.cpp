// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool IsPalindrome2( const string& s )
	{
		// ** Don't forget to increment and decrement j - just because we skip them when we are skipping non-alphanumeric characters doesn't mean we don't have to inc/dec once the characters are processed.
		for ( int i = 0, j = s.size() - 1; i < j; ++i, --j )
		{
			// Trick: notice that simply checking if i and j cross each other means we don't have to check i and j separately to see if they are out of bounds. Clever.
			while ( i < j && !isalnum( s[i] ) )
				++i;
			while ( i < j && !isalnum( s[j] ) )
				--j;
			if ( tolower( s[i] ) != tolower( s[j] ) )
				return false;
		}
		return true;
	}
}