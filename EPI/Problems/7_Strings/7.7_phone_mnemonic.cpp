// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

#define TEST 0

unordered_map<char, string> mappings = { { '2', "abc" },{ '3', "def" },{ '4', "ghi" },{ '5', "jkl" },{ '6', "mno" },{ '7', "pqrs" },{ '8', "tuv" },{ '9', "wxyz" } };

vector<string> PhoneMnemonic( const string& n ) 
{
	vector<string> results;
	return results;
}

#pragma region Test

// Not a real test.

void PhoneMnemonicTest()
{
#if TEST
	string num;
	num = RandIntString( 10 );
	auto result = PhoneMnemonic( num );
#endif
}

#pragma endregion
