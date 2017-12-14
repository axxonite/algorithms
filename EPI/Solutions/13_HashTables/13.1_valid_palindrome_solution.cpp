// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool CanFormPalindrome(const string& s)
	{
		unordered_set<char> oddFreqChars;
		for (char c : s)
		{
			if (oddFreqChars.count(c))			
				oddFreqChars.erase(c); // c now has appeared an even number of times.
			else
				oddFreqChars.insert(c); // c now has appeared an odd number of times.
		}
		// A string can be permuted to form a palindrome if and only if the number of chars whose frequencies is odd is at most 1.
		return oddFreqChars.size() <= 1;
	}
}
