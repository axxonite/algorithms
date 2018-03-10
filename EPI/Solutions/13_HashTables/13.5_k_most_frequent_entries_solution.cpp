// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

namespace Solutions
{
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
}