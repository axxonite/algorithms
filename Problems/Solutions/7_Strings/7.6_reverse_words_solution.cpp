// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "shared.h"

namespace Solutions
{
	void ReverseWords(string* s)
	{
		// First, reverses the whole string.
		reverse(s->begin(), s->end());

		size_t start = 0, end;
		while ((end = s->find(" ", start)) != string::npos)
		{
			// Reverses each word in the string.
			reverse(s->begin() + start, s->begin() + end);
			start = end + 1;
		}
		// Reverses the last word.
		reverse(s->begin() + start, s->end());
	}
}
