// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	unsigned Divide(unsigned x, unsigned y)
	{
		unsigned result = 0;
		// Start with the highest power available based on the number of bits.
		int power = 32;
		// Note the use of a 64 bit value for the power.
		unsigned long long ypow = unsigned long long(y) << power;
		while (x >= y)
		{
			// Skip powers until we get one that is smaller than x;
			while (ypow > x)
			{
				ypow >>= 1;
				--power;
			}
			// Note the use of 1U to get a 64-bit value.
			result += 1U << power;
			x -= ypow;
		}
		return result;
	}
}
