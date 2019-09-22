// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

struct ABSqrt2
{
	ABSqrt2(int a, int b) : a(a), b(b), val(a + b * sqrt(2))
	{
	}

	bool operator<(const ABSqrt2& that) const { return val < that.val; }

  bool operator == (const ABSqrt2& that) const { return a == that.a && b == that.b;  }

	int a, b;
	double val;
};

vector<ABSqrt2> GenerateFirstKABSqrt2(int k)
{
  vector<ABSqrt2> result;
	return result;
}

// No test.