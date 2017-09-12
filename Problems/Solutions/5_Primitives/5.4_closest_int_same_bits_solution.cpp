// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	unsigned long ClosestIntSameBitCount(unsigned long x)
	{
		const static int kNumUnsignedBits = 64;
		for (int i = 0; i < kNumUnsignedBits - 1; ++i)
		{
			if (((x >> i) & 1) != ((x >> (i + 1)) & 1))
			{
				x ^= (1UL << i) | (1UL << (i + 1)); // Swaps bit-i and bit-(i + 1).
				return x;
			}
		}

		// Throw error if all bits of x are 0 or 1.
		throw invalid_argument("All bits are 0 or 1");
	}
}