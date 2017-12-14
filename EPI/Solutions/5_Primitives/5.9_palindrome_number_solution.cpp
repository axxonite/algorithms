// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool IsPalindromeNumber(int x)
	{
		if (x < 0)
			return false;

		const int num_digits = int(floor(log10(x))) + 1;
		int msd_mask = int(pow(10, num_digits - 1));
		// Note that we are checking two digits on each iteration.
		for (int i = 0; i < num_digits; i += 2)
		{
			if (x / msd_mask != x % 10)
				return false;
			x %= msd_mask;  // Remove the most significant digit of x.
			x /= 10;  // Remove the least significant digit of x.
			msd_mask /= 100; // Shift the MSD mask decimally.
		}
		return true;
	}
}
