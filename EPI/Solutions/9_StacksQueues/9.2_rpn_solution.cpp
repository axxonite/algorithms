// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int EvalRPN( const string& expr )
	{
		string token;
		stringstream ss( expr );
		stack<int> s;
		while ( getline( ss, token, ',' ) )
		{
			if ( token == "+" || token == "-" || token == "*" || token == "/" )
			{
				// watch the order here, with the top value being the last - this matters for division.
				int value2 = s.top();
				s.pop();
				int value1 = s.top();
				s.pop();
				if ( token == "+" )
					s.emplace( value1 + value2 );
				else if ( token == "-" )
					s.emplace( value1 - value2 );
				else if ( token == "*" )
					s.emplace( value1 * value2 );
				else if ( token == "/" )
					s.emplace( value1 / value2 );
			}
			else s.emplace( stoi( token ) );
		}
		return s.top();
	}
}