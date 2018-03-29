// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

double MaxKPairsProfits(const vector<double>& prices, int k)
{
	vector<double> profitsBySellDateLast( prices.size(), 0 );
	vector<double> profitsBySellDate( prices.size(), 0 );
	for ( int i = 1; i <= k; ++i )
	{
		double maxTerm = -prices[0];
		profitsBySellDate[0] = 0;
		for ( int j = 1; j < prices.size(); ++j ) // for each sale date - note we cannot sell on first day.
		{
			// max term computes the cost of the buy price and the max profit for the period ending the day before, for all days prior to day j.
			// max term is max(profitsBySellDateLast[x - 1] - prices[x]) over all values x less than j.
			// Note we cannot have previous profits on first or second day.
			// j is sale date, j - 1 is last possible date for a buy for that sale, j - 2 is last possible date for prior profits from the other trades.
			maxTerm = max( maxTerm, ( j > 1 ? profitsBySellDateLast[j - 2] : 0 ) - prices[j - 1] );
			// Note that we need to take the max with the best profits from the previous data. Aka, don't force a sale on this day if selling on a prior day was better.
			profitsBySellDate[j] = max( profitsBySellDate[j-1], prices[j] + maxTerm); // sales price plus the max term.
		}
		profitsBySellDateLast.swap(profitsBySellDate);
	}

	return profitsBySellDateLast.back();
}

#pragma region Test

// O(n^k) checking answer.
void CheckAnsHelper(const vector<double>& A, int l, int k, int pre,
                    double ans, double* max_ans)
{
	if (l == k)
		*max_ans = max(*max_ans, ans);
	else
	{
		for (int i = pre; i < A.size(); ++i)
			CheckAnsHelper(A, l + 1, k, i + 1, ans + ((l & 1) ? A[i] : -A[i]), max_ans);
	}
}

double MaxKPairsProfitsCheckAns(const vector<double>& A, int k)
{
	double ans = 0, max_ans = numeric_limits<double>::lowest();
	CheckAnsHelper(A, 0, 2 * k, 0, ans, &max_ans);
	cout << "max_ans = " << max_ans << endl;
	return max_ans;
}

void MaxKPairsProfitsTest()
{
#if TEST
	default_random_engine gen((random_device())());
	int n = 30, k = 4;
	// random tests for n = 30, k = 4 for 100 times/
	for (int times = 0; times < 5; ++times)
	{
		vector<double> A;
		uniform_real_distribution<double> dis(0, 99);
		for (int i = 0; i < n; ++i)
			A.emplace_back(dis(gen));
		cout << "n = " << n << ", k = " << k << endl;
		double a = MaxKPairsProfits( A, k );
		double b = MaxKPairsProfitsCheckAns( A, k );
		cout << a << endl;
		assert(a == b);
	}

	uniform_int_distribution<int> n_dis(1, 60);
	n = n_dis(gen);
	uniform_int_distribution<int> k_dis(1, n / 10);
	k = (k_dis(gen));
	vector<double> A;
	uniform_real_distribution<double> dis(0, 99);
	for (int i = 0; i < n; ++i)
		A.emplace_back(dis(gen));
	cout << "n = " << n << ", k = " << k << endl;
	cout << MaxKPairsProfitsCheckAns(A, k) << ", " << MaxKPairsProfits(A, k) << endl;
	assert(MaxKPairsProfitsCheckAns(A, k) == MaxKPairsProfits(A, k));
#endif
}

#pragma endregion Test
