// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct Subarray
{
	int start, end;

	bool operator == ( const Subarray& a )
	{
		return start == a.start && end == a.end;
	}
};

// A clever solution.
Subarray FindSmallestSubarrayCoveringSet( const vector<string>& paragraph, const unordered_set<string>& keywords )
{
	return { -1, -1 };
}

#pragma region Test

void FindSmallestSubarrayCoveringSetTest()
{
#if TEST
	vector<string> words = { "my", "paramount", "object", "is", "to", "save", "the", "union", "and", "is", "not", "to", "save", "or", "deny", "slavery",
		"if", "i", "could", "save", "the", "union", "without", "freeing", "any", "slave", "i", "would", "do", "it" };
	bool result = FindSmallestSubarrayCoveringSet( words, { "save", "union" } ) == Subarray{ 5, 7 };
	assert( result );
	result = FindSmallestSubarrayCoveringSet( words, { "union", "slavery" } ) == Subarray{ 15, 21 };
	assert( result );
	result = FindSmallestSubarrayCoveringSet( words, { "my", "it" } ) == Subarray{ 0, 29 };
	assert( result );
	result = FindSmallestSubarrayCoveringSet( words, { "i", "union", "slave" } ) == Subarray{ 21, 26 };
	assert( result );
#endif
}

#pragma endregion
