// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void MergeTwoSortedArrays(int A[], int m, int B[], int n)
	{
		int a = m - 1, b = n - 1, destIndex = m + n - 1;
		while (a >= 0 && b >= 0)
			A[destIndex--] = A[a] > B[b] ? A[a--] : B[b--];
		while (b >= 0)
			A[destIndex--] = B[b--];
	}
}
