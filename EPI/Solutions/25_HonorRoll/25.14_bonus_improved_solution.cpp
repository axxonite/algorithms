// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> CalculateBonus(const vector<int>& productivity)
	{
		vector<int> result(productivity.size(), 1);
		for (int i = 1; i < productivity.size(); ++i)
			result[i] = productivity[i - 1] < productivity[i] ? result[i - 1] + 1 : 1;
		for (int i = productivity.size() - 2; i >= 0; --i)
			result[i] = max(result[i], productivity[i + 1] < productivity[i] ? result[i + 1] + 1 : 1);
		return result;
	}
}