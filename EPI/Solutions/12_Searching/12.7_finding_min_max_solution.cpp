// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct MinMax
	{
		int smallest, largest;
	};

	// Note the use of the minmax function to keep everything really short.
	MinMax FindMinMax( const vector<int>& A )
	{
		if (A.empty())
			return { -1, -1 };
		pair<int, int> result = { numeric_limits<int>::max(), numeric_limits<int>::min() };
		if (A.size() % 2)
			result = { A[0], A[1] };
		for (int i = A.size() % 2 ? 1 : 0; i < A.size(); i += 2)
		{
			auto local = minmax(A[i], A[i + 1]);
			result = { min(local.first, result.first), max(local.second, result.second) };
		}
		return { result.first, result.second};

	}
}