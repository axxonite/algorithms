// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> PlusOne( vector<int> A )
	{
		++A.back();
		for ( int i = A.size() - 1; i > 0 && A[i] == 10; i-- )
			A[i] = 0, ++A[i - 1];
		if ( A.front() == 10 )
			A.front() = 0, A.insert( A.begin(), 1 );
		return A;
	}
}