// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> ExamineBuildingsWithSunset(istringstream* sin)
	{
		int index = 0, height;
		struct BuildingWithHeight
		{
			int id, height;
		};
		stack<BuildingWithHeight> candidates;
		while (*sin >> height)
		{
			// remove any candidates with a height < than the new building, as they are blocked by the new building.
			while (!candidates.empty() && height >= candidates.top().height)
				candidates.pop();
			candidates.emplace(BuildingWithHeight{ index++, height });
		}

		vector<int> buildingsWithView;
		while (!candidates.empty())
		{
			buildingsWithView.emplace_back(candidates.top().id);
			candidates.pop();
		}
		return buildingsWithView;
	}
}