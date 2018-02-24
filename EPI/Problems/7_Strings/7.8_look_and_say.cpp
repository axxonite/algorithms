// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

string LookAndSay( int n )
{
	return "";
}

#pragma region Test

void LookAndSayTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	int n;
	uniform_int_distribution<int> dis( 1, 50 );
	n = dis( gen );
	assert( !LookAndSay( 1 ).compare( "1" ) );
	assert( !LookAndSay( 2 ).compare( "11" ) );
	assert( !LookAndSay( 3 ).compare( "21" ) );
	assert( !LookAndSay( 4 ).compare( "1211" ) );
	assert( !LookAndSay( 5 ).compare( "111221" ) );
	assert( !LookAndSay( 6 ).compare( "312211" ) );
	assert( !LookAndSay( 7 ).compare( "13112221" ) );
	assert( !LookAndSay( 8 ).compare( "1113213211" ) );

	cout << "n = " << n << endl;
	cout << LookAndSay( n ) << endl; 
#endif
}

#pragma endregion
