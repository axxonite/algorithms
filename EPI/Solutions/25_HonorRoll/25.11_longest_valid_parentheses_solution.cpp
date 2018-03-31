// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

namespace Solutions
{
	int LongestValidParentheses( const string& s )
	{
		// origin refers to the floor - that is the index that is one level below the first open parens in the current run.
		// I was struggling with this concept of origin - a fall back that needs to be used when the stack has been emptied.
		// It's also tricky that I didn't realize I had to offset this origin with a -1.
		int best = 0, origin = -1;
		stack<int> st;
		for ( int i = 0; i < s.size(); ++i )
		{
			if ( s[i] == '(' )
				st.push( i );
			else if ( st.empty() )
				origin = i; // we have more closing parens than open parens, so we will be starting a new run on the next index if it contains an open parens.
			else
			{
				st.pop(); // close this open parens.
						  // the length of the run is the closed parens to the open parens before, or to the origin if there are no open parens.
				best = max( best, i - ( st.empty() ? origin : st.top() ) );
			}
		}
		return best;
	}
}