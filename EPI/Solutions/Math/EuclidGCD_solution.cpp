// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int EuclidGCD(int a, int b)
	{
		if (a == 0)
			return b;
		if (b == 0)
			return a;
		int c = a % b;
		while (c != 0)
		{
			a = b;
			b = c;
			c = a % b;
		}
		return b;
	}
}