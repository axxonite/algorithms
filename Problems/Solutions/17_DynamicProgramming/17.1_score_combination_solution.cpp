// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int NumCombinationsForFinalScore(int finalScore, const vector<int>& scores)
	{
		vector<vector<int>> combinationsForScore(scores.size(), vector<int>(finalScore + 1, 0));
		for (int i = 0; i < scores.size(); ++i)
		{
			combinationsForScore[i][0] = 1; // Only one way to reach 0.
			for (int j = 1; j <= finalScore; ++j)
			{
				int withoutThisPlay = i > 0 ? combinationsForScore[i - 1][j] : 0; // number of combinations that lead to j using the last i - 1 score combinations.
				// Number of combinations that lead to j using scores[i] * 1, scores[i] * 2, etc. As it so happens every entry at a multiple of scores[i] will already have an added 1 coming from the base case in the outer loop, so we can just add that instead of 
				// computing multiples explicitly. Another way to see this: the formula is A[i][j - w * scores[i]] for all w * scores[i] <= j, and prior entries in the array already contain all terms for all w's except the last one.
				int withThisPlay = j >= scores[i] ? combinationsForScore[i][j - scores[i]] : 0;
				combinationsForScore[i][j] = withoutThisPlay + withThisPlay;
			}
		}
		return combinationsForScore.back().back();
	}
}