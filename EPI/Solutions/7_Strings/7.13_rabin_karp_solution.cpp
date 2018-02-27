// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

namespace Solutions
{
	int RabinKarp( const string& t, const string& s )
	{
		// An empty search string matches all strings.
		if ( s.empty() )
			return 0;
		// Make sure the target string is longer than the search string.
		if ( t.size() < s.size() )
			return -1;

		const int kBase = 26;
		// We maximize coverage of the hash by allocating 26 values for each letter position. Thus every string combination up to a certain length (6 letters) gets a unique hash.
		// powerS is the weight of the first letter we added.
		int hashS = 0, hashT = 0, powerS = 1;
		for ( int i = 0; i < s.size(); i++ )
		{
			powerS = i ? powerS * kBase : 1;
			hashS = hashS * kBase + s[i];
			hashT = hashT * kBase + t[i];
		}

		for ( int i = s.size(); i <= t.size(); ++i )
		{
			if ( hashS == hashT && strncmp( s.c_str(), t.c_str() + i - s.size(), s.size() ) == 0 )
				return i - s.size();
			hashT -= t[i - s.size()] * powerS; // remove first letter we added.
			hashT = hashT * kBase + t[i]; // Increase weight of all other letters, and add our new letter with the lowest weight.
		}

		return -1;
	}
}