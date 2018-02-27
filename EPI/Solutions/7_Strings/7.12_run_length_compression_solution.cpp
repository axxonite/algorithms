// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	string Decoding( const string &s )
	{
		string result;
		int count = 0;
		// A much more elegant form of this is to just iterate over every character and keep a count throughout. Beautiful.
		for ( auto c : s )
		{
			// Note that isdigit is actually part of the c++ spec
			if ( isdigit( c ) )
				count = count * 10 + c - '0';
			else
			{
				result.append( count, c );
				count = 0;
			}
		}
		return result;
	}

	string Encoding( const string &s )
	{
		string result;
		for ( int i = 0; i < s.size(); ++i )
		{
			int count = 1;
			while ( i + 1 < s.size() && s[i + 1] == s[i] )
				++i, ++count;
			result += to_string( count ) + s[i];
		}
		return result;
	}
}