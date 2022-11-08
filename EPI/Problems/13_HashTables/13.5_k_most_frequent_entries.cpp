// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Shared.h"

#define TEST 0

vector<string> KMostFrequentEntries( const vector<string>& s, int k )
{
	vector<string> result;
	return result;
}

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