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
		if ( 2 * k >= prices.size() ) // When we have enough transactions such that we can buy and sell every day, use a simpler strategy.
			return UnlimitedPairsProfits( prices );
		vector<double> bestProfitForSaleOnDayOrPrior_lastTransaction( prices.size(), 0 );
		vector<double> bestProfitForSaleOnDayOrPrior( prices.size(), 0 );
		for ( int transaction = 1; transaction <= k; ++transaction ) // for each transaction.
		{
			double maxTerm = -prices[0];
			bestProfitForSaleOnDayOrPrior[0] = 0; // don't forget to initialize this.
			for ( int saleDay = 1; saleDay < prices.size(); ++saleDay ) // for each sale day - note we cannot sell on first day.
			{
				// Note that this formulation repeats work, as compute the max for a range from 0..saleDay, thus finding a max from days from 0..0, 0..1, 0..2, and so forth.
				/*
				double bestProfitIfWeSellOnThisDay = 0.0;
				for ( int buyDay = 0; buyDay < saleDay; ++buyDay)
					bestProfitIfWeSellOnThisDay = max(bestProfitIfWeSellOnThisDay, buyDay > 0 ? bestProfitForSaleOnDayOrPrior_lastTransaction[buyDay - 1] : 0 - prices[buyDay] + prices[saleDay]);
				// Note the max function here, so we don't force a sale on this day if selling on a prior day was better.
				bestProfitForSaleOnDayOrPrior[saleDay] = max(bestProfitForSaleOnDayOrPrior[saleDay - 1], bestProfitIfWeSellOnThisDay);
				*/

				// We can save work by reformulating the equation above to keep a running maximum of the first two terms in the equation: bestProfitForSaleOnDayOrPrior_lastTransaction[buyDay - 1] - prices[buyDay].
				// Then we don't need to re-iterate over the prior elements. This running maximum is stored in maxTerm instead.
				// The offsets from the above equation are changed to correspond to the last day before the sale day, which is why we getting -1 and -2 offsets here.
				maxTerm = max( maxTerm, ( saleDay > 1 ? bestProfitForSaleOnDayOrPrior_lastTransaction[saleDay - 2] : 0 ) - prices[saleDay - 1] );
				bestProfitForSaleOnDayOrPrior[saleDay] = max( bestProfitForSaleOnDayOrPrior[saleDay - 1], prices[saleDay] + maxTerm );
			}
			bestProfitForSaleOnDayOrPrior_lastTransaction.swap( bestProfitForSaleOnDayOrPrior ); // Move on to next transaction, make this transaction our last one.
		}

		return bestProfitForSaleOnDayOrPrior_lastTransaction.back(); // result is the best profit we can make over the range including all days in the arrays, aka up to the last.
	}
}