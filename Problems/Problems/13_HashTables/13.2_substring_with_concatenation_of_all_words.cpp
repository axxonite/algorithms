// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<int> FindAllSubstrings(const string& s, const vector<string>& words)
{
	vector<int> result;
	return result;
}

#pragma region Test

void FindAllSubstringsSmallTest()
{
	string s = "barfoothefoobarman";
	auto result = FindAllSubstrings(s, {"foo", "bar"});
	assert(result.size() == 2 && result[0] == 0 && result[1] == 9);
	s = "dcacdabcd";
	result = FindAllSubstrings(s, {"cd", "ab"});
	assert(result.size() == 2 && result[0] == 3 && result[1] == 5);
}

void FindAllSubstringsTest()
{
#if TEST
	FindAllSubstringsSmallTest();
#endif
}

#pragma endregion Test
