// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "shared.h"

#define TEST 0

int TransformString(unordered_set<string> d, const string& s, const string& t)
{
	return -1; // Cannot find a possible transformations.
}

#pragma region Test

void TransformStringTest()
{
#if TEST
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> dis(1, 10);
	int len = dis(gen);
	string s(RandString(len)), t(RandString(len));
	unordered_set<string> D;
	D.emplace(s) , D.emplace(t);
	uniform_int_distribution<int> dis2(1, 10000);
	int n = dis2(gen);
	for (size_t i = 0; i < n; ++i)
	{
		D.emplace(RandString(len));
	}
	/*
	for (const string &s : D) {
	cout << s << endl;
	}
	*/
	cout << s << ' ' << t << ' ' << D.size() << endl;
	cout << TransformString(D, s, t) << endl;
#endif
}

#pragma endregion Test
