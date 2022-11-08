// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

vector<int> SortKIncreasingDecreasingArray( const vector<int>& a ) 
{
	return {};
}

#pragma region Test

void SortKIncreasingDecreasingArraySimpleTest() 
{
	vector<int> A = { 1, 2, 3, 2, 1, 4, 5, 10, 9, 4, 4, 1, -1 };
	auto ans = SortKIncreasingDecreasingArray( A );
	assert( ans.size() == A.size() && is_sorted( ans.cbegin(), ans.cend() ) );

	A = { numeric_limits<int>::min(), -1, 0, 1, 2, 4, 8,
		numeric_limits<int>::max() };
	ans = SortKIncreasingDecreasingArray( A );
	assert( ans.size() == A.size() && is_sorted( ans.cbegin(), ans.cend() ) );

	reverse( A.begin(), A.end() );
	ans = SortKIncreasingDecreasingArray( A );
	assert( ans.size() == A.size() && is_sorted( ans.cbegin(), ans.cend() ) );
}

void SortKIncreasingDecreasingArrayTest()
{
#ifdef TEST
	SortKIncreasingDecreasingArraySimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 20; ++times )
	{
		int n;
		uniform_int_distribution<int> dis( 1, 10000 );
		n = dis( gen );
		vector<int> A;
		cout << "n = " << n << endl;
		uniform_int_distribution<int> dis2( -999999, 999999 );
		generate_n( back_inserter( A ), n, [&] { return dis2( gen ); } );
		vector<int> ans = SortKIncreasingDecreasingArray( A );
		/*
		copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
		copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
		*/
		assert( ans.size() == A.size() );
		assert( is_sorted( ans.cbegin(), ans.cend() ) );
	}
#endif
}

#pragma endregion