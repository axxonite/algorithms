// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct PageVisits
	{
		string page;
		int visits;
	};

	struct PageVisitsCompare
	{
		bool operator () ( const shared_ptr<PageVisits>& a, const shared_ptr<PageVisits>& b ) const
		{
			return a->visits < b->visits;
		}
	};

	set<shared_ptr<PageVisits>, PageVisitsCompare> pageVisits;
	unordered_map<string, shared_ptr<PageVisits>> pages;

	void ReadFileLine( const string& line )
	{
		int count = 1;
		auto it = pages.find( line );
		if ( it != pages.end() )
		{
			count = it->second->visits + 1;
			// Although this solutions works it's not really optimal. An optimal solution requires a BST where we can actually keep a pointer to a node in a BST.
			// A set, although implemented as a BST, does not allow us to do that; the iterator that the set gives us when we emplace into the BST actually
			// becomes invalid as soon as we add or remove other elements in the set. This forces us to search for the value in the set, adding an extra O(lg n)
			// into the run time cost of the function.
			//
			// It's not quite clear what the right solution would be in the context of an interview. Implementing a BST is an option that would make this solution
			// optimal, but implementing a full on BST on its own is quite a time consuming thing to do in an interview setting, on top of implementing the algorithm 
			// seen here. Check with the interviewer if that is what is required in the context of this question.
			pageVisits.erase( it->second );
		}
		auto newPageVisits = make_shared<PageVisits>( PageVisits{ line, count } );
		pages[line] = newPageVisits;
		pageVisits.emplace( newPageVisits );

	}

	vector<string> FindKMostVisited( int k )
	{
		vector<string> result;
		for ( auto it = pageVisits.rbegin(); it != pageVisits.rend() && k > 0; ++it, --k )
			result.emplace_back( ( *it )->page );
		return result;
	}
}