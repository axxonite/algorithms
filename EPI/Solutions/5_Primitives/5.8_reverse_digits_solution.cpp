// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int ReverseDigits(int x)
	{
		auto result = 0;
		auto neg = x < 0;
		x = abs(x);
		while (x > 0)
		{
			result = result * 10 + x % 10;
			x = x / 10;
		}
		return result * (neg ? -1 : 1);
	}
}