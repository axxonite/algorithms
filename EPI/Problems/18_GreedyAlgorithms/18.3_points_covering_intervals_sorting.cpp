// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct Interval 
{
	int left, right;
};

vector<int> FindMinimumVisits( vector<Interval> intervals ) 
{
	return {};
}

#pragma region Test

void FindMinimumVisitsCheckAns( const vector<Interval>& intervals, const vector<int>& ans ) 
{
	deque<bool> is_visited( intervals.size(), false );
	for ( int a : ans ) 
	{
		for ( size_t i = 0; i < intervals.size(); ++i ) 
		{
			if ( a >= intervals[i].left && a <= intervals[i].right ) 
				is_visited[i] = true;
		}
	}

	for ( bool b : is_visited )
		assert( b == true );
}

void FindMinimumVisitsSimpleTest()
{
	vector<Interval> intervals = { Interval{ 1, 4 },  Interval{ 2, 8 }, Interval{ 3, 6 },  Interval{ 3, 5 }, Interval{ 7, 10 }, Interval{ 9, 11 } };
	vector<int> ans = FindMinimumVisits( intervals );
	vector<int> golden = { 4, 10 };
	assert( equal( ans.begin(), ans.end(), golden.begin(), golden.end() ) );

	intervals = { Interval{ 1, 2 }, Interval{ 2, 3 }, Interval{ 3, 4 }, Interval{ 4, 5 }, Interval{ 5, 6 }, Interval{ 6, 7 } };
	ans = FindMinimumVisits( intervals );
	golden = { 2, 4, 6 };
	assert( equal( ans.begin(), ans.end(), golden.begin(), golden.end() ) );

	intervals = { Interval{ 1, 5 }, Interval{ 2, 3 }, Interval{ 3, 4 } };
	ans = FindMinimumVisits( intervals );
	golden = { 3 };
	assert( equal( ans.begin(), ans.end(), golden.begin(), golden.end() ) );
}

void FindMinimumVisitsTest()
{
#if TEST
	FindMinimumVisitsSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times )
	{
		cout << "Test " << times << endl;
		int n;
		uniform_int_distribution<int> dis( 1, 10000 );
		n = dis( gen );
		vector<Interval> A;
		for ( int i = 0; i < n; ++i ) {
			uniform_int_distribution<int> left_dis( 0, 9999 );
			int left = left_dis( gen );
			uniform_int_distribution<int> right_dis( left, left + 100 );
			int right = right_dis( gen );
			A.emplace_back( Interval{ left, right } );
		}
		vector<int> ans( FindMinimumVisits( A ) );
		FindMinimumVisitsCheckAns( A, ans );
	}
#endif
}

#pragma endregion
