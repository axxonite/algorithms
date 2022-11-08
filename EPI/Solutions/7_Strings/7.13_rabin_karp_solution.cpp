// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Shared.h"

namespace Solutions
{
	int RabinKarp( const string& t, const string& s )
	{
		// 1. Pre-conditions:
		// An empty search string matches all strings.
		if ( s.empty() )
			return 0;
		// Make sure the target string is longer than the search string.
		if ( t.size() < s.size() )
			return -1;

		// 2. Setup hash for both source and destination. Note the user of powerS to compute the base to a power.
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

		// 3. Compare hashes to find a match and roll the hash window over by substracting and adding.
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

int RabinKarp2(const string& t, const string& s)
{
	if (s.size() > t.size())
		return -1;
	if (s.empty())
		return 0;
	int hashS = 0, hashT = 0, weight = 1, prevWeight = 0;
	for (int i = 0; i < s.size(); ++i, weight *= 26)
		hashS = hashS * 26 + s[i], hashT = hashT * 26 + t[i], prevWeight = weight;

	for (int i = 0; i <= t.size() - s.size(); ++i)
	{
		if (hashS == hashT && strncmp(s.c_str(), t.c_str() + i, s.size()) == 0)
			return i;
		hashT = (hashT - t[i] * prevWeight) * 26 + t[i + s.size()];
	}
	return -1;
}