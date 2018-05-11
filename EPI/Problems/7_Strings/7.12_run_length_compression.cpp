// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

string Decoding( const string &s ) 
{
	string result;
	return result;
}

string Encoding( const string &s ) 
{
	string result;
	return result;
}

#pragma region Test

void RLEEncodingTest()
{
#if TEST
	assert( "4a1b3c2a" == Encoding( "aaaabcccaa" ) );
	assert( "eeeffffee" == Decoding( "3e4f2e" ) );
	assert( "aaaaaaaaaaffffee" == Decoding( "10a4f2e" ) );
#endif
}

#pragma endregion
