// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	unsigned Add(unsigned a, unsigned b)
	{
		unsigned sum = 0, carryin = 0, mask = 1, shifted_a = a, shifted_b = b;
		// shifted_a and shifted_b are used to check when have run out of set bits to add.
		while (shifted_a || shifted_b)
		{
			unsigned am = a & mask, bm = b & mask; // Mask a and b so we are left only with the bit we are interested in for each of a and b.
			unsigned carryout = (am & bm) | (am & carryin) | (bm & carryin); // Compute carry. OR of AND of each pair.
			sum |= (am ^ bm ^ carryin);  // Compute sum. XOR of all three.
										 // Do shifts so masks, carry and shifted values all coincide with the next bit of interest.
			carryin = carryout << 1, mask <<= 1, shifted_a >>= 1, shifted_b >>= 1;
		}
		return sum | carryin;
	}

	unsigned Multiply(unsigned x, unsigned y)
	{
		// note that we do not support negative numbers in this example.
		unsigned sum = 0;
		// examine each bit in x. y represents (2^i)y.
		// Note that y is shifted to the left while x is shifted to the right.
		for (; x; x >>= 1, y <<= 1)
		{
			if (x & 1)
				sum = Add(sum, y);
		}
		return sum;
	}
}