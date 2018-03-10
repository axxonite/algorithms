// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

namespace Solutions
{
	bool IsLetterConstructibleFromMagazine( const string& letter, const string& magazine )
	{
		unordered_map<char, int> counts;
		for ( auto c : letter )
			counts[c]++;
		for ( auto c : magazine )
		{
			auto it = counts.find( c );
			if ( it != counts.end() )
			{
				--it->second;
				if ( it->second == 0 )
				{
					counts.erase( it );
					if ( counts.empty() )
						return true;
				}
			}
		}
		return letter.empty();
	}
}