// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

namespace Solutions
{
	using namespace std;

	double BuyAndSellStockTwice(const vector<double>& prices) 
	{
		double max_total_profit = 0;
		// first_buy_sell_profits is the maximum amount of profit we can make if we buy and sell using the subarray of prices from 0 to i.
		vector<double> first_buy_sell_profits(prices.size(), 0);
		double min_price_so_far = numeric_limits<double>::max();

		// Forward phase. For each day, we record maximum profit if we sell on that day.
		for (int i = 0; i < prices.size(); ++i) 
		{
			min_price_so_far = min(min_price_so_far, prices[i]); // Keep track of lowest price, which caps the max profit we can make on the first sale.
			max_total_profit = max(max_total_profit, prices[i] - min_price_so_far); // Keep track of the best possible profit we have made so far.
			first_buy_sell_profits[i] = max_total_profit; // Keep track of the best possible profit using the subarray of prices from 0 to i.
		}

		// Backward phase. For each day, find the maximum profit if we make the second buy on that day.
		double max_price_so_far = numeric_limits<double>::min();
		for (int i = (int)prices.size() - 1; i > 0; --i) 
		{
			max_price_so_far = max(max_price_so_far, prices[i]); // Keep track of the highest price, which caps the max profit we can make on the second sale.
			// Update the max profit to include the sum of our best possible second sale, along with the best possible profit we could have made on the first sale
			// at that point.
			max_total_profit = max(max_total_profit, max_price_so_far - prices[i] + first_buy_sell_profits[i - 1]);
		}
		return max_total_profit;
	}
}