// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int RomanToInteger(const string& s)
	{
		unordered_map<char, int> T = { { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };

		int sum = T[s.back()]; // start from the right.
		for (int i = s.length() - 2; i >= 0; --i)
		{
			if (T[s[i]] < T[s[i + 1]]) // if the value of the digit to the left is less than the value of the digit to the right, then subtract it
				sum -= T[s[i]];
			else
				sum += T[s[i]]; // otherwise add it.
		}
		return sum;
	}
}
