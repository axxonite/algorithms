// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool IsPalindrome2(const string& s)
	{
		// i moves forward, and j moves backward.
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			// i and j both skip non-alphanumeric characters.
			while (!isalnum(s[i]) && i < j)
				++i;
			while (!isalnum(s[j]) && i < j)
				--j;
			if (tolower(s[i++]) != tolower(s[j--]))
				return false;
		}
		return true;
	}
}
