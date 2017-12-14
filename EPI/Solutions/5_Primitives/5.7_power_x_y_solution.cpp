// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	double Power(double x, int y)
	{
		double result = 1.0;
		long long power = y;
		// Handle negative power, use reciprocal.
		if (y < 0)
			power = -power, x = 1.0 / x;
		// Decompose the power
		while (power)
		{
			// If set, multiply by x
			if (power & 1)
				result *= x;
			// square the power on each iteration.
			x *= x, power >>= 1;
		}
		return result;
	}
}
