// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct Name 
{
	bool operator==( const Name& that ) const 
	{
		return false;
	}

	string firstName, lastName;
};

void EliminateDuplicate( vector<Name>& a ) 
{
}

#pragma region Test

void EliminateDuplicateCheckAns( const vector<Name>& A ) 
{
	for ( size_t i = 1; i < A.size(); ++i ) 
		assert( !( A[i] == A[i - 1] ) );
}

void EliminateDuplicateSmallTest()
{
	vector<Name> A = { { "Foo", "Bar" },{ "ABC", "XYZ" },{ "Foo", "Widget" } };
	EliminateDuplicate( A );
	assert( A.size() == 2 );
}

void EliminateDuplicateTest()
{
#if TEST
	EliminateDuplicateSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 50; ++times ) 
	{
		int n;
		vector<Name> A;
		uniform_int_distribution<int> dis( 0, 1000 );
		n = dis( gen );
		for ( int i = 0; i < n; ++i ) 
		{
			uniform_int_distribution<int> dis( 0, n - 1 );
			A.emplace_back( Name{ to_string( dis( gen ) ), to_string( dis( gen ) ) } );
		}
		EliminateDuplicate( A );
		EliminateDuplicateCheckAns( A );
	}
#endif
}

#pragma endregion
