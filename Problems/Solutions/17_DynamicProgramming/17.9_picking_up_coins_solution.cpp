// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int ComputeMaximumRevenueForRange(const vector<int>& coins, int a, int b, vector<vector<int>>* maximum_revenue_for_range_ptr)
	{
		if (a > b)
			return 0; // No coins left.

		vector<vector<int>>& maximum_revenue_for_range = *maximum_revenue_for_range_ptr;
		// Compute result if it hasn't been cached yet.
		if (maximum_revenue_for_range[a][b] == 0)
		{
			// We assume, given whichever coin we pick, the opponent will work to minimize our revenue.
			// Fist case: pick coin a, then assume we make the minimal revenue, with the opponent either taking another a, or taking b.
			int max_revenue_a = coins[a] + min(ComputeMaximumRevenueForRange(coins, a + 2, b, maximum_revenue_for_range_ptr), ComputeMaximumRevenueForRange(coins, a + 1, b - 1, maximum_revenue_for_range_ptr));
			// Second case: pick coin b, then assume we make the minimal revenue, with the opponent either taking a, or another b.
			int max_revenue_b = coins[b] + min(ComputeMaximumRevenueForRange(coins, a + 1, b - 1, maximum_revenue_for_range_ptr), ComputeMaximumRevenueForRange(coins, a, b - 2, maximum_revenue_for_range_ptr));
			// Play the best of these two cases.
			maximum_revenue_for_range[a][b] = max(max_revenue_a, max_revenue_b);
		}
		return maximum_revenue_for_range[a][b];
	}

	int MaximumRevenue(const vector<int>& coins)
	{
		// How much revenue we can make from the first move depends on how much revenue we will make from the second move and beyond, which depends on how much revenue we will make from the third move and beyond, and so forth.
		// Subidivide into smaller subproblems and use the solutions to these subproblems to answer the larger problem, the essence of dynamic programming.
		// Keep track of the maximum revenue for all possible ranges starting at some a and ending at some b. As a gets closer to b, the problem is eventually trivialized to a base case.
		vector<vector<int>> maximum_revenue_for_range(coins.size(), vector<int>(coins.size(), 0));
		return ComputeMaximumRevenueForRange(coins, 0, int(coins.size()) - 1, &maximum_revenue_for_range);
	}
}
