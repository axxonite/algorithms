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

	int UniformRandom(int lowerBound, int upperBound)
	{
		int numberOfOUtcomes = upperBound - lowerBound + 1, result;
		do
		{
			result = 0;
			for (int i = 0; (1 << i) < numberOfOUtcomes; ++i)

				result = (result << 1) | ZeroOneRandom(); // ZeroOneRandom() is the provided random number generator.
		} while (result >= numberOfOUtcomes);
		return result + lowerBound;
	}
}
