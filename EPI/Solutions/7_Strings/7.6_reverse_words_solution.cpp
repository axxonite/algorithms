// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Shared.h"

namespace Solutions
{
	void ReverseWords(string& s)
	{
		// First, reverse the whole string.
		reverse(s.begin(), s.end());

		size_t start = 0, end;
		// Go over each word boundary. So that start and end are at the beginning and end of a word.
		while ((end = s.find(" ", start)) != string::npos) // note the use of npos to indicate the end of a string.
		{
			// Reverses each word in the string.
			reverse(s.begin() + start, s.begin() + end);
			start = end + 1; // move to next word.
		}
		// Reverses the last word.
		reverse(s.begin() + start, s.end());
	}
}
