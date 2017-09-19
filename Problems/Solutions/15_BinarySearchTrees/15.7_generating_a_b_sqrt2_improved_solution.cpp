// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// These numbers have very interesting property, and people called it ugly numbers. It is also called Quadratic integer rings.
	struct ABSqrt2
	{
		ABSqrt2(int a, int b) : a(a), b(b), val(a + b * sqrt(2))
		{
		}

		bool operator<(const ABSqrt2& that) const { return val < that.val; }

		int a, b;
		double val;
	};

	vector<ABSqrt2> GenerateFirstKABSqrt2(int k)
	{
		// Will store the first k numbers of the form a + b sqrt(2).
		vector<ABSqrt2> result;
		result.emplace_back(0, 0);
		int i = 0, j = 0;
		for (int n = 1; n < k; ++n)
		{
			ABSqrt2 iplus1(result[i].a + 1, result[i].b); // increase a 
			ABSqrt2 jplusqrt2(result[j].a, result[j].b + 1); // increase b
			 // add the smaller one to the result.
			if (iplus1 < jplusqrt2)
			{
				result.emplace_back(iplus1);
				++i;
			}
			else
			{
				result.emplace_back(jplusqrt2);
				++j;
			}
		}
		return result;
	}
}
