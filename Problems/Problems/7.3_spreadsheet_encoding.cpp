// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

int SSDecodeColID(const string& col) 
{
	return 0;
}

#pragma region Test

string RandString(int len)
{
	default_random_engine gen((random_device())());
	string result;
	uniform_int_distribution<int> dis('A', 'Z');
	while (len--) {
		result.push_back(dis(gen));
	}
	return result;
}

void SimpleTest() {
	assert(1 == SSDecodeColID("A"));
	assert(2 == SSDecodeColID("B"));
	assert(26 == SSDecodeColID("Z"));
	assert(27 == SSDecodeColID("AA"));
}

void SpreadsheetEncodingTest() 
{
	SimpleTest();
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> len_dis(1, 5);
	string s(RandString(len_dis(gen)));
	cout << s << " " << SSDecodeColID(s) << endl;
}

#pragma endregion