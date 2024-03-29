// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Shared.h"

#define TEST 0

struct Subarray 
{
	int start, end;
};

Subarray FindSmallestSequentiallyCoveringSubset(const vector<string>& paragraph, const vector<string>& keywords ) 
{
	Subarray result = { -1, -1 };
	return result;
}

#pragma region Test

void FindSmallestSequentiallyCoveringSubsetSmallTest() 
{
	vector<string> A3 = { "0", "1", "2", "3",  "4",  "5",  "6", "7", "8", "9",
		"2", "4", "6", "10", "10", "10", "3", "2", "1", "0" };
	vector<string> subseq4 = { "0", "2", "9", "4", "6" };
	Subarray rr = FindSmallestSequentiallyCoveringSubset( A3, subseq4 );
	assert( rr.start == 0 && rr.end == 12 );
	}

void FindSmallestSequentiallyCoveringSubsetTest()
{
#if TEST
	FindSmallestSequentiallyCoveringSubsetSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 10; ++times ) 
	{
		int n;
		vector<string> A;
		uniform_int_distribution<int> dis( 1, 10000 );
		n = dis( gen );
		uniform_int_distribution<int> dis2( 1, 5 );
		generate_n( back_inserter( A ), n, [&] { return RandString( dis2( gen ) ); } );
		unordered_set<string> dict;
		copy( A.begin(), A.end(), inserter( dict, dict.end() ) );
		cout << "A = ";
		copy( A.begin(), A.end(), ostream_iterator<string>( cout, "," ) );
		cout << endl;
		uniform_int_distribution<int> m_dis(
			1, min( static_cast<int>( dict.size() ), 10 ) );
		int m = m_dis( gen );
		vector<string> Q;
		auto it = dict.begin();
		generate_n( back_inserter( Q ), m, [&] { return *it++; } );
		cout << "Q = ";
		copy( Q.begin(), Q.end(), ostream_iterator<string>( cout, "," ) );
		cout << endl;

		Subarray res( FindSmallestSequentiallyCoveringSubset( A, Q ) );
		cout << res.start << ", " << res.end << endl;
		if ( res.start != -1 && res.end != Q.size() ) 
		{
			if ( res.start != res.end ) {
				cout << res.start << ", " << res.end << endl;
			}
			dict.clear();
			copy( Q.begin(), Q.end(), inserter( dict, dict.end() ) );
			for ( int i = res.start; i <= res.end; ++i ) 
			{
				if ( dict.find( A[i] ) != dict.end() ) 
					dict.erase( A[i] );
			}
			assert( dict.empty() );
		}
	}
#endif
}

#pragma endregion
