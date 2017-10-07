// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void MergeTwoSortedArrays(int A[], int m, int B[], int n)
	{
		int a = m - 1, b = n - 1, destIndex = m + n - 1; // start from the end of both arrays and back fill.
		while (a >= 0 && b >= 0)
			A[destIndex--] = A[a] > B[b] ? A[a--] : B[b--]; // Put greater entry first, going in reverse order.
		while (b >= 0) // If a >= 0 but b < 0, then the destination array is already in sorted order.
			A[destIndex--] = B[b--]; // otherwise, all remaining entries in B are < the current entries in the destination.
	}
}
