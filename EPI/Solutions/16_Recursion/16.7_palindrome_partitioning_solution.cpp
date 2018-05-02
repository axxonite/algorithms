// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool IsPalindrome(const string& prefix)
	{
		for (int i = 0, j = prefix.size() - 1; i < j; ++i, --j)
		{
			if (prefix[i] != prefix[j])
				return false;
		}
		return true;
	}

	// Why is this not a dynamic programming solution?
	// Say we have "ABAABABEEB".
	// Then we can have "ABA+ABA+BEEB" or "ABAABA+BEEB". When we do the second case we could have looked it up in an array instead of doing a palindromic test on BEEB.
	// It was somewhat harder to write though, because that means storing all decompositions start at the index.
	void DirectedPalindromePartitioning(const string& input, int offset, vector<string>& partial, vector<vector<string>>& result)
	{
		if (offset == input.size())
		{
			result.emplace_back(partial);
			return;
		}

		// Test for palindromic prefixes of all possible sizes starting at offset.
		// Note the <= test with the input size, so that a prefix starting at the last character in the string, will have a count of at least one.
		for (int i = offset + 1; i <= input.size(); ++i)
		{
			// The prefix is from the offset, with a length of 1, 2, and so forth
			string prefix = input.substr(offset, i - offset);
			if (IsPalindrome(prefix))
			{
				partial.emplace_back(prefix);
				// Found a prefix, now test the remainder of the string.
				DirectedPalindromePartitioning(input, i, partial, result);
				partial.pop_back();
			}
		}
	}

	// Also called... anagram.
	vector<vector<string>> PalindromePartitioning(const string& input)
	{
		vector<vector<string>> result;
		vector<string> partial;
		DirectedPalindromePartitioning(input, 0, partial, result);
		return result;
	}
}