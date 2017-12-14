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
		int i = 0, j = 0; // i is index of last result that incremented a, and j is index of last result that incremented b.
		for (int n = 1; n < k; ++n)
		{
			ABSqrt2 iplus1(result[i].a + 1, result[i].b); // increase a 
			ABSqrt2 jplussqrt2(result[j].a, result[j].b + 1); // increase b
			 // add the smaller one to the result.
			result.emplace_back(min(iplus1, jplussqrt2));
			if (iplus1.val == result.back().val) {
				++i;
			}
			if (jplussqrt2.val == result.back().val) {
				++j;
			}
		}
		return result;
	}
}
