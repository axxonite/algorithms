// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct DuplicateAndMissing
	{
		int duplicate, missing;
	};

	DuplicateAndMissing FindDuplicateMissing(const vector<int>& A)
	{
		// m is the missing entry, d is the duplicate entry.
		// Compute the XOR of all numbers from 0 to |A| - 1 and all entries in A. mXORd tells us by which bits m and d differ.
		int mXORd = 0;
		for (int i = 0; i < A.size(); ++i)
			mXORd ^= i ^ A[i];

		// We need to find a bit that's set to 1 in mXORd. Such a bit must exist if there is a single missing number and a single duplicated number in A.
		// The bit-fiddling assignment below sets all of the bits in differ_bit to 0 except for the LSB in mXORd that's 1.
		int differBit = mXORd & ~(mXORd - 1);
		int mORd = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			// Focus on entries and numbers in which ith bit in differBit is 1.
			// Let Ak and Sk be the sequence of entries where the differBit is set. Then the XOR of both sequences is either m or d.
			if (i & differBit)
				mORd ^= i;
			if (A[i] & differBit)
				mORd ^= A[i];
		}

		// mORd is either the missing value or the duplicated entry.
		// Look for one entry and use XOR to get the other entry.
		for (int a : A)
		{
			// mORd is the duplicate.
			if (a == mORd)
				return { mORd, mORd ^ mXORd };
		}
		// mORd is the missing value.
		return { mORd ^ mXORd, mORd };
	}
}
