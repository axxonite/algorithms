// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

#define TEST 0

bool IsLetterConstructibleFromMagazine( const string& letter, const string& magazine ) 
{
	return false;
}

#pragma region Test

void IsLetterConstructibleFromMagazineSimpleTest() {
	assert( !IsLetterConstructibleFromMagazine( "123", "456" ) );
	assert( !IsLetterConstructibleFromMagazine( "123", "12222222" ) );
	assert( IsLetterConstructibleFromMagazine( "123", "1123" ) );
	assert( IsLetterConstructibleFromMagazine( "123", "123" ) );
	assert( !IsLetterConstructibleFromMagazine( "12323", "123" ) );
	assert(
		IsLetterConstructibleFromMagazine( "GATTACA", "A AD FS GA T ACA TTT" ) );
	assert( !IsLetterConstructibleFromMagazine( "a", "" ) );
	assert( IsLetterConstructibleFromMagazine( "aa", "aa" ) );
	assert( IsLetterConstructibleFromMagazine( "aa", "aaa" ) );
	assert( IsLetterConstructibleFromMagazine( "", "123" ) );
	assert( IsLetterConstructibleFromMagazine( "", "" ) );
}

void IsLetterConstructibleFromMagazineTest()
{
#if TEST
	IsLetterConstructibleFromMagazineSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	string L, M;
	uniform_int_distribution<int> L_dis( 1, 1000 );
	uniform_int_distribution<int> M_dis( 1, 100000 );
	L = RandString( L_dis( gen ) ), M = RandString( M_dis( gen ) );
	//cout << L << endl;
	//cout << M << endl;
	cout << boolalpha << IsLetterConstructibleFromMagazine( L, M ) << endl;
#endif
}

#pragma endregion
