// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Subarray
	{
		int start, end;

		bool operator == ( const Subarray& a )
		{
			return start == a.start && end == a.end;
		}
	};

	// A clever solution.
	Subarray FindSmallestSubarrayCoveringSet( const vector<string>& paragraph, const unordered_set<string>& keywords )
	{
		unordered_map<string, list<int>::iterator> coveredKeywords; // For each keyword, track its corresponding element in the locations list.
		list<int> loc; // Keep a list that tracks the location of each keyword we've tagged. This is kept ordered by the order of the words in the paragraph.
		Subarray result{ 0, numeric_limits<int>::max() };
		for ( const string& s : keywords ) // Add all words so we don't have to do count() checks later.
			coveredKeywords.emplace( s, loc.end() );
		for ( int i = 0; i < paragraph.size(); ++i )
		{
			auto& word = paragraph[i];
			if ( keywords.count( word ) )
			{
				// Find the keyword, remove it from the list if it's in it, and add a new entry for our word that start at the current location.
				auto it = coveredKeywords.find( word );
				if ( it->second != loc.end() )
					loc.erase( it->second );
				loc.emplace_back( i );
				coveredKeywords[word] = --loc.end(); // Update the entry in the hash table
				if ( loc.size() == keywords.size() && ( i - loc.front() ) < ( result.end - result.start ) ) // look for a winning candidate.
					result = { loc.front(), i };
			}
		}
		return loc.size() == keywords.size() ? result : Subarray{ -1, -1 }; // return a default value if we never covered all the keywords.
	}
}