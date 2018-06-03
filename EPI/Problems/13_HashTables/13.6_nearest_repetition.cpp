// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

#define TEST 0

// if no repeats of a word are found, return numeric_limits<int>::max().
int FindNearestRepetition( const vector<string>& paragraph ) 
{
	return -1;
}

#pragma region Test

int FindNearestRepetitionCheckAnswer( const vector<string>& s ) 
{
	int nearest_repeated_distance = numeric_limits<int>::max();
	for ( int i = 0; i < s.size(); ++i ) 
	{
		for ( int j = i + 1; j < s.size(); ++j ) 
		{
			if ( s[i] == s[j] ) 
				nearest_repeated_distance = min( nearest_repeated_distance, j - i );
		}
}
	return nearest_repeated_distance;
}

void FindNearestRepetitionTest()
{
#if TEST
	vector<string> A = { "foo",    "bar",    "widget", "foo", "widget", "widget", "adnan" };
	assert( FindNearestRepetitionCheckAnswer( A ) == FindNearestRepetition( A ) );
	A = { "foo", "bar", "widget", "foo", "xyz", "widget", "bar", "adnan" };
	assert( FindNearestRepetitionCheckAnswer( A ) == FindNearestRepetition( A ) );
	A = { "foo", "bar", "widget", "adnan" };
	assert( FindNearestRepetitionCheckAnswer( A ) == FindNearestRepetition( A ) );
	A = {};
	assert( FindNearestRepetitionCheckAnswer( A ) == FindNearestRepetition( A ) );
	A = { "foo", "foo", "foo" };
	assert( FindNearestRepetitionCheckAnswer( A ) == FindNearestRepetition( A ) );
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 10; ++times ) 
	{
		int n;
		uniform_int_distribution<int> dis( 1, 1000 );
		n = dis( gen );
		vector<string> s;
		for ( int i = 0; i < n; ++i ) {
			uniform_int_distribution<int> dis( 1, 10 );
			s.emplace_back( RandString( dis( gen ) ) );
		}
		assert( FindNearestRepetitionCheckAnswer( s ) == FindNearestRepetition( s ) );
	}
#endif
}

#pragma endregion
