// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindBiggestNMinusOneProduct( const vector<int>& a )
	{
		int smallestPos = 0, smallestNeg = 0, largestNeg = 0, smallestPosIndex = -1, smallestNegIndex = -1, largestNegIndex = -1;
		int negs = 0;
		for ( int i = 0; i < a.size(); ++i )
		{
			if ( a[i] >= 0 )
			{
				if ( smallestPosIndex == -1 || a[i] < smallestPos )
					smallestPosIndex = i, smallestPos = a[i];
			}
			else if ( a[i] < 0 )
			{
				negs++;
				if ( largestNegIndex == -1 || a[i] < largestNeg )
					largestNegIndex = i, largestNeg = a[i];
				if ( smallestNegIndex == -1 || a[i] > smallestNeg )
					smallestNegIndex = i, smallestNeg = a[i];
			}
		}

		int indexToRemove;
		if ( negs % 2 ) // odd negatives, remove a negative so it flips the sign, get the smallest one so we end up with a large positive value.
			indexToRemove = smallestNegIndex;
		else if ( smallestPosIndex == -1 ) // all numbers are negative and we have an even number of them, remove the largest negative so we end up with the smallest negative value we can
			indexToRemove = largestNegIndex;
		else indexToRemove = smallestPosIndex; // even numbers of negatives, remove a positive number so we keep the positive sign, find the smallest so we get a large positive value.

		long long product = 1;
		for ( int i = 0; i < a.size(); ++i )
		{
			if ( i != indexToRemove )
				product *= a[i];
		}
		return product;
	}
}