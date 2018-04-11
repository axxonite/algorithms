// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	double UnlimitedPairsProfits( const vector<double>& prices )
	{
		double profit = 0.0;
		// buy for all days to go up, abstain on all days that go down. The max profit is essentially the sum of all the increases in prices from one day to the next.
		for ( int i = 1; i < prices.size(); ++i )
			profit += max( 0.0, prices[i] - prices[i - 1] );
		return profit;
	}

	double MaxKPairsProfits( const vector<double>& prices, int k )
	{
		if ( k == 0 )
			return 0;
		else if ( 2 * k >= prices.size() ) // When we have enough transactions such that we can buy and sell every day, use a simpler strategy.
			return UnlimitedPairsProfits( prices );
		vector<double> bestProfitBySellDate_LastTransaction( prices.size(), 0 );
		vector<double> bestProfitBySellDate( prices.size(), 0 );
		for ( int i = 1; i <= k; ++i ) // for each transaction.
		{
			double maxTerm = -prices[0];
			bestProfitBySellDate[0] = 0;
			for ( int j = 1; j < prices.size(); ++j ) // for each sale date - note we cannot sell on first day.
			{
				// The computation entails iterating over some index m from day 0.. j to find the maximum of value of profitsFromPriorSales[m-2] - prices[m-1] (buy) + prices[j] (sale).
				// Note that this formulation repeats work, as compute the max for a range from 0..j, thus finding a max from days from 0..0, 0..1, 0..2, and so forth.
				// We can save work by reformulating the equation to keep a running maximum of the first two terms in the equation: profitsFromPriorSales[m-2] - prices[m-1] (buy).
				// Then we don't need to re-iterate over the prior elements. This running maximum is stored into maxTerm below.
				maxTerm = max( maxTerm, ( j > 1 ? bestProfitBySellDate_LastTransaction[j - 2] : 0 ) - prices[j - 1] );


				// j is sell date, j - 1 is last possible date for a buy for that sale, j - 2 is last possible date for prior profits from the other trades. Hence, take profits from first j - 2 days.
				// Note we cannot have previous profits on first or second day.
				// Note also the max function here, so we don't force a sale on this day if selling on a prior day was better.
				bestProfitBySellDate[j] = max( bestProfitBySellDate[j - 1], prices[j] + maxTerm ); // sales price plus the max term.
			}
			bestProfitBySellDate_LastTransaction.swap( bestProfitBySellDate ); // Move on to next transaction, make this transaction our last one.
		}

		return bestProfitBySellDate_LastTransaction.back(); // result is the best profit we can make over the range including all days in the arrays, aka up to the last.
	}
}