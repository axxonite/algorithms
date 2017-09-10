// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	double Power(double x, int y)
	{
		double result = 1.0;
		long long power = y;
		if (y < 0)
			power = -power, x = 1.0 / x;
		while (power)
		{
			if (power & 1)
				result *= x;
			x *= x, power >>= 1;
		}
		return result;
	}
}
