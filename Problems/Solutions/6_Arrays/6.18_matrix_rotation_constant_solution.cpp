// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void RotateMatrix(vector<vector<int>>* A_ptr)
	{
		auto& A = *A_ptr;
		for (int i = 0; i < (A.size() / 2); ++i)
		{
			for (int j = i; j < A.size() - i - 1; ++j)
			{
				int temp = A[i][j];
				A[i][j] = A[A.size() - 1 - j][i];
				A[A.size() - 1 - j][i] = A[A.size() - 1 - i][A.size() - 1 - j];
				A[A.size() - 1 - i][A.size() - 1 - j] = A[j][A.size() - 1 - i];
				A[j][A.size() - 1 - i] = temp;
			}
		}
	}
}
