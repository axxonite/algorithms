// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

#define TEST 1

vector<string> KMostFrequentEntries( const vector<string>& s, int k )
{
	unordered_map<string, int> entries;
	for ( auto cur : s )
		entries[cur]++;
	// Tricky declaration here.
	priority_queue<pair<string, int>, vector<pair<string, int>>, function<bool( pair<string, int>, pair<string, int> )>> heap( []( pair<string, int> a, pair<string, int> b ) { return a.second > b.second; } );
	for ( auto it = entries.begin(); it != entries.end(); ++it )
	{
		if ( heap.size() < k || heap.top().second < it->second )
		{
			heap.emplace( pair<string, int>{ it->first, it->second } );
			if ( heap.size() > k )
				heap.pop();
		}
	}
	// The book claims O(m+n) is possible by using a pivot search for the kth element (12.8). Not quite sure why that is true, however.
	vector<string> result;
	while ( !heap.empty() )
	{
		result.emplace_back( heap.top().first );
		heap.pop();
	}
	return result;
}

// The book has no code solution for this one. This is my own.

#pragma region Test

void KMostFrequentEntriesTest()
{
#if TEST
	vector<string> input;
	default_random_engine gen( ( random_device() )( ) );
	vector<string> uniqueStrings;
	for ( int i = 0; i < 25; ++i )
		uniqueStrings.emplace_back( RandString( 20 ) );
	uniform_int_distribution<int> dis( 0, 24 );
	for ( int i = 0; i < 1000; ++i )
		input.emplace_back( uniqueStrings[dis( gen )] );
	auto result = KMostFrequentEntries( input, 5 );
	unordered_map<string, int> counts;
	for ( auto s : input )
		counts[s]++;
	for ( int i = 0; i < 5; ++i )
	{
		int count = counts[result[i]];
		int higherCounts = 0;
		for ( auto it = counts.begin(); it != counts.end(); ++it )
		{
			if ( it->second > count )
				higherCounts++;
		}
		assert( higherCounts < 5 );
	}
#endif
}

#pragma endregion