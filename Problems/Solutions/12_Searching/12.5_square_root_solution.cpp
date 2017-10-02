// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	typedef enum
	{
		SMALLER,
		EQUAL,
		LARGER
	} Ordering;

	Ordering Compare(double a, double b)
	{
		// Uses normalization for precision problem.
		double diff = (a - b) / b;
		return diff < -numeric_limits<double>::epsilon() ? SMALLER : diff > numeric_limits<double>::epsilon() ? LARGER : EQUAL;
	}

	double SquareRoot(double x)
	{
		// Decides the search range according to x's value relative to 1.0.
		double left, right;
		if (x < 1.0)
			left = x, right = 1.0;
		else
			left = 1.0, right = x;

		// Keeps searching as long as left != right, within tolerance.
		while (Compare(left, right) != EQUAL)
		{
			double mid = left + 0.5 * (right - left);
			double mid_squared = mid * mid;
			if (Compare(mid_squared, x) == LARGER)
				right = mid;
			else
				left = mid;
		}
		return left;
	}
	
}
