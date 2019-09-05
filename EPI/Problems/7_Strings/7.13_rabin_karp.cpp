// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

// #define TEST

int RabinKarp( const string& t, const string& s )
{
	return -1;
}

#pragma region Test

int CheckAnswer( const string& t, const string& s ) 
{
	for ( int i = 0; i + s.size() - 1 < t.size(); ++i ) 
	{
		bool find = true;
		for ( int j = 0; j < s.size(); ++j ) 
		{
			if ( t[i + j] != s[j] ) 
			{
				find = false;
				break;
			}
		}
		if ( find == true )
			return i;
	}
	return -1;  // No matching.
}

void RabinKarpSimpleTest() {
	assert( RabinKarp( "GACGCCA", "CGC" ) == 2 );
	assert( RabinKarp( "GATACCCATCGAGTCGGATCGAGT", "GAG" ) == 10 );
	assert( RabinKarp( "FOOBARWIDGET", "WIDGETS" ) == -1 );
	assert( RabinKarp( "A", "A" ) == 0 );
	assert( RabinKarp( "A", "B" ) == -1 );
	assert( RabinKarp( "A", "" ) == 0 );
	assert( RabinKarp( "ADSADA", "" ) == 0 );
	assert( RabinKarp( "", "A" ) == -1 );
	assert( RabinKarp( "", "AAA" ) == -1 );
	assert( RabinKarp( "A", "AAA" ) == -1 );
	assert( RabinKarp( "AA", "AAA" ) == -1 );
	assert( RabinKarp( "AAA", "AAA" ) == 0 );
	assert( RabinKarp( "BAAAA", "AAA" ) == 1 );
	assert( RabinKarp( "BAAABAAAA", "AAA" ) == 1 );
	assert( RabinKarp( "BAABBAABAAABS", "AAA" ) == 8 );
	assert( RabinKarp( "BAABBAABAAABS", "AAAA" ) == -1 );
	assert( RabinKarp( "FOOBAR", "BAR" ) > 0 );
}

void RabinKarpTest()
{
#ifdef TEST
	RabinKarpSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times ) {
		uniform_int_distribution<int> t_dis( 1, 1000 );
		uniform_int_distribution<int> s_dis( 1, 20 );
		string t = RandString( t_dis( gen ) );
		string s = RandString( s_dis( gen ) );
		//cout << "t = " << t << endl;
		//cout << "s = " << s << endl;
		assert( RabinKarp( t, s ) == CheckAnswer( t, s ) );
	}
#endif
}

#pragma endregion
