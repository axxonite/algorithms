// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	unsigned Divide(unsigned x, unsigned y)
	{
		unsigned result = 0;
		// Start with the highest power available based on the number of bits.
		int power = 32; // 32 is actualy incorrect here - so value that is 1 << 32 would fit in the unsigned int result.
		// Note the use of an UNSIGNED 64 bit value for the power. If it's not unsigned we will potentially run into an infinite loop.
		unsigned long long ypow = unsigned long long(y) << power;
		while (x >= y)
		{
			// Skip powers until we get one that is smaller than x;
			// DO NOT add a >= sign here... I made this mistake when it should have been obvious.
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

unsigned Divide2(unsigned x, unsigned y)
{
	int result = 0;
	unsigned int power = 31;
	unsigned long long ypower = unsigned long long(y) << power;
	while (x >= y)
	{
		if (x >= ypower)
			x -= ypower, result |= 1 << power;
		ypower >>= 1, power--;
	}
	return result;
}