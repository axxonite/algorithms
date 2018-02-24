// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

#define TEST 0

int ReplaceAndRemove( int size, char s[] ) 
{
	return 0;
}

#pragma region Test

void CheckAns( const string &s, const string &ans ) {
	string temp;
	for ( int i = 0; i < s.size(); ++i ) 
	{
		if ( s[i] == 'a' )
			temp += 'd', temp += 'd';
		else if ( s[i] != 'b' )
			temp += s[i];
	}
	assert( ans == temp );
}

void ReplaceAndRemoveTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times )
	{
		string s;
		uniform_int_distribution<int> dis( 1, 1000 );
		s = RandString( dis( gen ) );
		cout << s << endl << endl;
		char *s_copy = new char[( s.size() << 1 ) + 1];
		strcpy( s_copy, s.c_str() );
		int final_size = ReplaceAndRemove( s.size(), s_copy );
		CheckAns( s, string( s_copy, final_size ) );
	}
#endif
}

#pragma endregion
