// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <limits>
#include <random>
#include <vector>

namespace Problems
{
	using namespace std;

	double BuyAndSellStockTwice(const vector<double>& prices)
	{
		return 0;
	}

#pragma region Test

	double BuyAndSellStockTwiceConstantSpace(const vector<double>& prices) {
		array<double, 2> min_prices = { numeric_limits<double>::max(), numeric_limits<double>::max() }, max_profits = { 0.0, 0.0 };
		for (const double& price : prices)
		{
			for (int i = 1; i >= 0; --i)
			{
				max_profits[i] = max(max_profits[i], price - min_prices[i]);
				min_prices[i] =
					min(min_prices[i], price - (i - 1 >= 0 ? max_profits[i - 1] : 0.0));
			}
		}
		return max_profits[1];
	}

	void BuyAndSellStockTwiceTest()
	{
		default_random_engine gen((random_device())());
		for (int times = 0; times < 1000; ++times) {
			int n;
			uniform_int_distribution<int> dis(1, 100);
			n = dis(gen);
			vector<double> A;
			uniform_real_distribution<double> dis2(0.0, 10000.0);
			for (int i = 0; i < n; ++i)
			{
				A.emplace_back(dis2(gen));
			}
			assert(fabs(BuyAndSellStockTwiceConstantSpace(A) -
				BuyAndSellStockTwice(A)) < 1.0e-8);
		}
	}

#pragma endregion
}