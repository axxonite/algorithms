// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int ZeroOneRandom()
	{
		default_random_engine gen((random_device())());
		uniform_int_distribution<int> dis(0, 1);
		return dis(gen);
	}

	int UniformRandom(int low, int high)
	{
		int outcomes = high - low + 1, result; // note the +1
		do
		{
			result = 0;
			for (int i = 0; (1 << i) < outcomes; ++i) // iterator over every bit until that bit is higher than the number of outcomes.
				result = (result << 1) | ZeroOneRandom(); // Add one random bit
		} while (result >= outcomes); // start over if we generated a number above the max.
		return result + low; // add low.
	}
}
