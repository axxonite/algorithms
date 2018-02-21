// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	double BuyAndSellStockOnce( const vector<double>& prices )
	{
		double minThusFar = numeric_limits<double>::max(), bestProfit = 0;
		for ( auto p : prices )
			minThusFar = min( minThusFar, p ), bestProfit = max( bestProfit, p - minThusFar );
		return bestProfit;
	}
}