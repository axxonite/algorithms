// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct Interval 
{
	int left, right;
};

vector<Interval> AddInterval( const vector<Interval>& disjoint_intervals, Interval new_interval ) 
{
	return {};
}

#pragma region Test

void AddIntervalCheckIntervals( const vector<Interval>& result )
{
	// Only check the intervals do not overlap with each other.
	for ( size_t i = 1; i < result.size(); ++i )
		assert( result[i - 1].right < result[i].left );
}

void AddIntervalSmallTest() 
{
	vector<Interval> A = { { 1, 5 } };
	Interval new_one = { 0, 3 };
	auto result = AddInterval( A, new_one );
	assert( result.size() == 1 && result.front().left == 0 && result.front().right == 5 );
	new_one = { 0, 0 };
	result = AddInterval( A, new_one );
	assert( result.size() == 2 && result.front().left == 0 && result.front().right == 0 && result.back().left == 1 && result.back().right == 5 );
}

void AddIntervalTest()
{
#if TEST
	AddIntervalSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times )
	{
		size_t n;
		uniform_int_distribution<size_t> dis( 1, 10000 );
		n = dis( gen );
		vector<Interval> A;
		int pre = 0;
		uniform_int_distribution<int> dis2( 1, 10 );
		for ( size_t i = 0; i < n; ++i )
		{
			Interval temp;
			temp.left = pre + dis( gen );
			temp.right = temp.left + dis( gen );
			pre = temp.right;
			A.emplace_back( temp );
		}
		uniform_int_distribution<int> tar_dis( 0, 100 );
		Interval target;
		target.left = tar_dis( gen );
		target.right = target.left + tar_dis( gen );
		auto result = AddInterval( A, target );
		AddIntervalCheckIntervals( result );
	}
#endif
}

#pragma endregion
