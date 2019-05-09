// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "../../Shared.h"

// #define TEST

int ReplaceAndRemove( int size, char s[] ) 
{
	return 0;
}

#pragma region Test

void CheckAns( const string &s, const string &ans ) {
	string temp;
	for (char i : s)
	{
		if (i == 'a' )
			temp += 'd', temp += 'd';
		else if (i != 'b' )
			temp += i;
	}
	assert( ans == temp );
}

void ReplaceAndRemoveTest()
{
#ifdef TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 100; ++times )
	{
		string s;
		uniform_int_distribution<int> dis( 1, 1000 );
		s = RandString( dis( gen ) );
		cout << s << endl << endl;
		const auto size = (s.size() << 1) + 1;
		const auto s_copy = new char[size];
		strcpy_s( s_copy, size, s.c_str() );
		const int final_size = ReplaceAndRemove( s.size(), s_copy );
		CheckAns( s, string( s_copy, final_size ) );
	}
#endif
}

#pragma endregion
