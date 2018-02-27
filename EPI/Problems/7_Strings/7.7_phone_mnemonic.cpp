// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

#define TEST 0

vector<string> PhoneMnemonic( const string& n ) 
{
	return {};
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
