// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Generate all subsets whose intersection with inputSet[0], ...,
	// inputSet[toBeSelected - 1] is exactly selectedSoFar.
	void DirectedPowerSet(const vector<int>& inputSet, int toBeSelected, vector<int>& selectedSoFar, vector<vector<int>>& powerSet)
	{
		if (toBeSelected == inputSet.size())
		{
			powerSet.emplace_back(selectedSoFar);
			return;
		}
		// Generate all subsets that contain inputSet[toBeSelected].
		selectedSoFar.emplace_back(inputSet[toBeSelected]);
		DirectedPowerSet(inputSet, toBeSelected + 1, selectedSoFar, powerSet);
		// Generate all subsets that do not contain inputSet[toBeSelected].
		selectedSoFar.pop_back();
		DirectedPowerSet(inputSet, toBeSelected + 1, selectedSoFar, powerSet);
	}

	vector<vector<int>> GeneratePowerSet(const vector<int>& input_set)
	{
		vector<vector<int>> power_set;
		vector<int> selectedSoFar;
		DirectedPowerSet(input_set, 0, selectedSoFar, power_set);
		return power_set;
	}
}
