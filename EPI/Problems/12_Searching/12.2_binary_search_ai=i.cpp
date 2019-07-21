// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int SearchEntryEqualToItsIndex( const vector<int>& a ) 
{
	return -1;
}

#pragma region Test

int SearchEntryEqualToItsIndexTestCheckAns( const vector<int>& A )
{
	for ( size_t i = 0; i < A.size(); ++i ) 
	{
		if ( A[i] == static_cast<int>( i ) ) 
			return static_cast<int>( i );
	}
	return -1;
}

static void SearchEntryEqualToItsIndexSimpleTest() 
{
	vector<int> A = { 0, 1, 2, 3 };
	assert( -1 != SearchEntryEqualToItsIndex( A ) );
	assert( 0 <= SearchEntryEqualToItsIndex( A ) &&
		SearchEntryEqualToItsIndex( A ) <= 3 );
	A[0] = -1;
	A[2] = 4;
	A[3] = 5;
	assert( 1 == SearchEntryEqualToItsIndex( A ) );
	A = { 0 };
	assert( -1 != SearchEntryEqualToItsIndex( A ) );
	A[0] = -1;
	assert( -1 == SearchEntryEqualToItsIndex( A ) );
}

void SearchEntryEqualToItsIndexTest()
{
#ifdef TEST
	SearchEntryEqualToItsIndexSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 50; ++times ) {
		int n;
		vector<int> A;
		unordered_set<int> table;
		uniform_int_distribution<int> dis( 1, 1000 );
		n = dis( gen );
		for ( int i = 0; i < n; ++i ) 
		{
			int x;
			unordered_set<int>::iterator iter;
			do 
			{
				uniform_int_distribution<int> dis( -999, 999 );
				x = dis( gen );
				iter = table.find( x );
			} 
			while ( iter != table.cend() );
			table.emplace_hint( iter, x );
			A.emplace_back( x );
		}
		sort( A.begin(), A.end() );
		int ans = SearchEntryEqualToItsIndex( A );
		if ( ans != -1 ) {
			cout << "A[" << ans << "] = " << A[ans] << endl;
			assert( ans == A[ans] );
		}
		else 
		{
			cout << "no entry where A[k] = k" << endl;
			assert( ans == SearchEntryEqualToItsIndexTestCheckAns( A ) );
		}
	}
#endif
}

#pragma endregion
