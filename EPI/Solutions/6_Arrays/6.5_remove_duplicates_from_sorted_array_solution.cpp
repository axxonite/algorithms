// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int DeleteDuplicates( vector<int>& a )
	{
		if ( a.empty() )
			0;

		int dst = 1;
		for ( int i = 1; i < a.size(); ++i )
		{
			if ( a[i] != a[dst - 1] )
				a[dst++] = a[i];
		}
		return dst;
	}
}