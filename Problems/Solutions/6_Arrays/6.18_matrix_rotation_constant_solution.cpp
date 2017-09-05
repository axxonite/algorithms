// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void RotateMatrix(vector<vector<int>>& a)
	{
		int last = a.size() - 1;
		// We go around the edge of the array as we complete one iteration of i. 
		// Since there's there's two edges per dimension, we only need to iterate for the length of half the size of the array.
		for (int i = 0; i < a.size() / 2; ++i)
		{
			for (int j = i; j < a.size() - i - 1; ++j)
			{
				int temp = a[i][j];
				// Sequence is a[i][j] <- a[last-j][i] <- a[last - i][last - j] <- a[j][last - i] <- a[i][j]
				a[i][j] = a[last - j][i]; // Assign top left
				a[last - j][i] = a[last - i][last - j]; // Assign bottom left
				a[last - i][last - j] = a[j][last - i]; // Assign bottom right
				a[j][last - i] = temp; // Assign top right
			}
		}
	}
}
