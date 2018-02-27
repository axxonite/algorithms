// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<string> GetValidIPAddress( const string& s )
{
	return {};
}

#pragma region Test

void GetValidIPAddressTest()
{
#if TEST
	auto res1 = GetValidIPAddress( "255255255255" );
	assert( res1.size() == 1 );
	assert( res1.front() == "255.255.255.255" );
	auto res2 = GetValidIPAddress( "19216811" );
	assert( res2.size() == 9 );
	auto res3 = GetValidIPAddress( "1111" );
	assert( res3.size() == 1 );
	assert( res3.front().compare( "1.1.1.1" ) == 0 );
	auto res4 = GetValidIPAddress( "11000" );
	assert( res4.size() == 2 );
	sort( res4.begin(), res4.end() );
	assert( res4[0].compare( "1.10.0.0" ) == 0 );
	assert( res4[1].compare( "11.0.0.0" ) == 0 );
#endif
}

#pragma endregion
