// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindFirstMissingPositive( vector<int> a )
	{
		// The catch here is that zero is NOT a positive value.
		for ( int i = 0; i < a.size(); ++i )
		{
			int value = a[i];
			while ( value > 0 && value < a.size() && a[value - 1] != value )
			{
				int temp = a[value - 1];
				a[value - 1] = value;
				value = temp;
			}
		}
		for ( int i = 0; i < a.size(); ++i )
		{
			if ( a[i] != i + 1 )
				return i + 1;
		}
		return a.size();
	}
}