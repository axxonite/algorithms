// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions 
{
	bool IsValidPart( const string& s )
	{
		if ( s.size() > 1 && s[0] == '0' )
			return false;
		int value = stoi( s );
		if ( value > 255 )
			return false;
		return true;
	}

	vector<string> GetValidIPAddress( const string& s )
	{
		// There's a few ways to do this. The official solution doesn't take advantage of the fact that, if we start with a 0, we could break out of the loop.
		// Breaking out of the loop is faster, however it is more error-prone since the *last* condition that checks the size of the 4th part must be a continue,
		// not a break, since that part is *decreasing* in size, not increasing, as we iterate through the dot positions.
		//
		// In an interview setting, it's essential to use a helper function, or you may run out of time.
		vector<string> result;
		for ( int i = 1; i < 4 && i < s.size(); ++i )
		{
			string part1 = s.substr( 0, i ).c_str();
			if ( IsValidPart( part1 ) )
			{
				for ( int j = i + 1; j < i + 4 && j < s.size(); ++j )
				{
					string part2 = s.substr( i, j - i );
					if ( IsValidPart( part2 ) )
					{
						for ( int k = j + 1; k < j + 4 && k < s.size(); ++k )
						{
							string part3 = s.substr( j, k - j );
							if ( IsValidPart( part3 ) )
							{
								string part4 = s.substr( k, s.size() - k );
								if ( IsValidPart( part4 ) )
									result.emplace_back( part1 + '.' + part2 + '.' + part3 + '.' + part4 );
							}
						}
					}
				}
			}
		}
		return result;
	}
}