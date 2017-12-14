// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Generate all subsets whose intersection with input[0], ...,
	// input[index - 1] is exactly partial.
	void DirectedPowerSet(const vector<int>& input, int index, vector<int>& partial, vector<vector<int>>& result)
	{
		if (index == input.size())
		{
			result.emplace_back(partial);
			return;
		}
		// Generate all subsets that contain input[index].
		partial.emplace_back(input[index]);
		DirectedPowerSet(input, index + 1, partial, result);
		// Generate all subsets that do not contain input[index].
		partial.pop_back();
		DirectedPowerSet(input, index + 1, partial, result);
	}

	vector<vector<int>> GeneratePowerSet(const vector<int>& inputSet)
	{
		vector<vector<int>> result;
		vector<int> selectedSoFar;
		DirectedPowerSet(inputSet, 0, selectedSoFar, result);
		return result;
	}
}
