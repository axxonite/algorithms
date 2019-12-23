// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

// #define TEST

string SnakeString( const string& s )
{
	string result;
	return result;
}

#pragma region Test

void SnakeStringSmallTest() { assert( SnakeString( "Hello World!" ) == "e lHloWrdlo!" ); }

void SnakeStringTest()
{
#ifdef TEST
	SnakeStringSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	string s;
	uniform_int_distribution<size_t> dis_s( 1, 100 );
	s = RandString( dis_s( gen ) );
	cout << SnakeString( s ) << endl; 
#endif
}

#pragma endregion
