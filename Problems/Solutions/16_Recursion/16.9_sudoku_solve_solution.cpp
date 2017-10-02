// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	const int kEmptyEntry = 0;

	bool ValidToAddVal(const vector<vector<int>>& partialAssignment, int i, int j, int val)
	{
		// Check row constraints.
		for (int k = 0; k < partialAssignment.size(); ++k)
			if (val == partialAssignment[k][j])
				return false;

		// Check column constraints.
		if (any_of(begin(partialAssignment[i]), end(partialAssignment[i]), [val](int a) { return val == a; }))
			return false;

		// Check region constraints.
		int regionSize = sqrt(partialAssignment.size());
		int I = i / regionSize, J = j / regionSize;
		for (int a = 0; a < regionSize; ++a)
		{
			for (int b = 0; b < regionSize; ++b)
			{
				if (val == partialAssignment[regionSize * I + a][regionSize * J + b])
					return false;
			}
		}
		return true;
	}

	bool SolvePartialSudoku(int i, int j, vector<vector<int>>* partialAssignment)
	{
		if (i == partialAssignment->size())
		{
			i = 0; // Starts a new row.
			if (++j == (*partialAssignment)[i].size())
				return true; // Entire matrix has been filled without conflict.
		}

		// Skips nonempty entries.
		if ((*partialAssignment)[i][j] != kEmptyEntry)
			return SolvePartialSudoku(i + 1, j, partialAssignment);

		for (int val = 1; val <= partialAssignment->size(); ++val)
		{
			// It's substantially quicker to check if entry val conflicts with any of the constraints if we add it at (i,j) before adding it, rather than adding it and then checking all constraints.
			// The reason is that we know we are starting with a valid configuration and the only entry which can cause a problem is entry val at (i,j).
			if (ValidToAddVal(*partialAssignment, i, j, val))
			{
				(*partialAssignment)[i][j] = val;
				if (SolvePartialSudoku(i + 1, j, partialAssignment))
					return true;
			}
		}

		(*partialAssignment)[i][j] = kEmptyEntry; // Undo assignment.
		return false;
	}

	bool SolveSudoku(vector<vector<int>>* partial_assignment)
	{
		return SolvePartialSudoku(0, 0, partial_assignment);
	}
}
