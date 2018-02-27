// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

namespace Solutions
{
	string SnakeString( const string& s )
	{
		string result;
		for ( int i = 1; i < s.size(); i += 4 )
			result += s[i];
		for ( int i = 0; i < s.size(); i += 2 )
			result += s[i];
		for ( int i = 3; i < s.size(); i += 4 )
			result += s[i];
		return result;
	}
}