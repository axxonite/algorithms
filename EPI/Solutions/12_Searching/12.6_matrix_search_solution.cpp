// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool MatrixSearch( const vector<vector<int>>& a, int x )
	{
		int row = 0, col = a[0].size() - 1;
		while ( col >= 0 && row < a.size() )
		{
			if ( a[row][col] < x )
				++row;
			else if ( a[row][col] > x )
				--col;
			else return true;
		}
		return false;
	}
}