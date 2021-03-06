// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

bool IsMatch(const string& r, const string& s)
{
	return false;
}

#pragma region Test

void IsMatchTest()
{
#ifdef TEST
	assert(IsMatch(".", "a"));
	assert(IsMatch("a", "a"));
	assert(!IsMatch("a", "b"));
	assert(IsMatch("a.9", "aW9"));
	assert(!IsMatch("a.9", "aW19"));
	assert(IsMatch("^a.9", "aW9"));
	assert(!IsMatch("^a.9", "baW19"));
	assert(IsMatch(".*", "a"));
	assert(IsMatch(".*", ""));
	assert(IsMatch("c*", "c"));
	assert(!IsMatch("aa*", "c"));
	assert(IsMatch("aa*$", "caaaa"));
	assert(IsMatch("ca*$", "caaaa"));
	assert(!IsMatch("aa*$", "caaaab"));
	assert(IsMatch("ca*", "c"));
	assert(IsMatch(".*", "asdsdsa"));
	assert(IsMatch("9$", "xxxxW19"));

	assert(IsMatch(".*a", "ba"));

	assert(IsMatch(".*a", "ba"));
	assert(IsMatch("^a.*9$", "axxxxW19"));

	assert(IsMatch("^a.*W19$", "axxxxW19"));
	assert(IsMatch(".*a.*W19", "axxxxW19123"));
	assert(!IsMatch(".*b.*W19", "axxxxW19123"));
	assert(IsMatch("n.*", "n"));
	assert(IsMatch("a*n.*", "an"));
	assert(IsMatch("a*n.*", "ana"));
	assert(IsMatch("a*n.*W19", "anaxxxxW19123"));
	assert(IsMatch(".*a*n.*W19", "asdaaadnanaxxxxW19123"));
	assert(IsMatch(".*.*.a*n.*W19", "asdaaadnanaxxxxW19123"));
#endif
}

#pragma endregion