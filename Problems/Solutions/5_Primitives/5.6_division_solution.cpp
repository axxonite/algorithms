// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	unsigned Divide(unsigned x, unsigned y)
	{
		unsigned result = 0;
		int power = 32;
		// Note the use of a 64 bit value for the power.
		unsigned long long ypow = unsigned long long(y) << power;
		while (x >= y)
		{
			while (ypow > x)
			{
				ypow >>= 1;
				--power;
			}
			result += 1U << power;
			x -= ypow;
		}
		return result;
	}
}
