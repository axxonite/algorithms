// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

vector<int> CalculateBonus( const vector<int>& productivity )
{
  vector<int> result;
  return result;
}

#pragma region Test

using std::vector;

void CalculateBonusCheckAns( const vector<int>& productivity, const vector<int>& C )
{
	for ( size_t i = 0; i < productivity.size(); ++i ) {
		if ( i > 0 ) {
			assert( ( productivity[i] > productivity[i - 1] && C[i] > C[i - 1] ) ||
				( productivity[i] < productivity[i - 1] && C[i] < C[i - 1] ) ||
				productivity[i] == productivity[i - 1] );
		}
		if ( i + 1 < productivity.size() ) {
			assert( ( productivity[i] > productivity[i + 1] && C[i] > C[i + 1] ) ||
				( productivity[i] < productivity[i + 1] && C[i] < C[i + 1] ) ||
				productivity[i] == productivity[i + 1] );
		}
	}
}

template <typename T>
bool EqualVector( const vector<T>& A, const vector<T>& B ) {
	return equal( A.begin(), A.end(), B.begin(), B.end() );
}

void CalculateBonusSmallTest() {
	vector<int> A = { 1, 2, 2 };
	vector<int> golden_A = { 1, 2, 1 };
	assert( EqualVector( CalculateBonus( A ), golden_A ) );
	A = { 1, 2, 3, 2, 1 };
	golden_A = { 1, 2, 3, 2, 1 };
	assert( EqualVector( CalculateBonus( A ), golden_A ) );
	A = { 300, 400, 500, 200 };
	golden_A = { 1, 2, 3, 1 };
	assert( EqualVector( CalculateBonus( A ), golden_A ) );
}

void CalculateBonusTest()
{
#ifdef TEST
	CalculateBonusSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times ) {
		int n;
		uniform_int_distribution<int> dis( 1, 1000 );
		n = dis( gen );
		vector<int> ratings;
		uniform_int_distribution<int> dis2( 1, 10000 );
		for ( int i = 0; i < n; ++i ) {
			ratings.emplace_back( dis2( gen ) );
		}
		auto T = CalculateBonus( ratings );
		CalculateBonusCheckAns( ratings, T );
	}
#endif
}

#pragma endregion
