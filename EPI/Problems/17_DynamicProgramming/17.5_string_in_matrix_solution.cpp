// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct HashTuple
	{
		size_t operator()(const tuple<int, int, int>& t) const
		{
			return hash<int>()(get<0>(t) ^ get<1>(t) * 1021 ^ get<2>(t) * 1048573);
		}
	};

	bool IsPatternSuffixContainedStartingAtXY(const vector<vector<int>>& grid, int x, int y, const vector<int>& pattern, int offset, unordered_set<tuple<int, int, int>, HashTuple>& previousAttempts)
	{
		if (pattern.size() == offset)
			return true; // Nothing left to complete.

		// Check if (x, y) lies outside the grid.
		if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || previousAttempts.find({ x, y, offset }) != previousAttempts.cend() || grid[x][y] != pattern[offset])
			return false;

		if (IsPatternSuffixContainedStartingAtXY(grid, x - 1, y, pattern, offset + 1, previousAttempts) ||
			IsPatternSuffixContainedStartingAtXY(grid, x + 1, y, pattern, offset + 1, previousAttempts) ||
			IsPatternSuffixContainedStartingAtXY(grid, x, y - 1, pattern, offset + 1, previousAttempts) ||
			IsPatternSuffixContainedStartingAtXY(grid, x, y + 1, pattern, offset + 1, previousAttempts))
			return true;
		previousAttempts.emplace(x, y, offset);
		return false;
	}

	bool IsPatternContainedInGrid(const vector<vector<int>>& grid, const vector<int>& pattern)
	{
		// Each entry in previousAttempts is a point in the grid and suffix of pattern (identified by its offset). Presence in previousAttempts indicates the suffix is not contained in the grid starting from that point.
		unordered_set<tuple<int, int, int>, HashTuple> previousAttempts;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[i].size(); ++j)
				if (IsPatternSuffixContainedStartingAtXY(grid, i, j, pattern, 0, previousAttempts))
					return true;
		return false;
	}
}