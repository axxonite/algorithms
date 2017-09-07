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

	void DirectedPalindromePartitioning(const string& input, int offset, vector<string>* partial_partition, vector<vector<string>>* result)
	{
		if (offset == input.size())
		{
			result->emplace_back(*partial_partition);
			return;
		}

		for (int i = offset + 1; i <= input.size(); ++i)
		{
			string prefix = input.substr(offset, i - offset);
			if (IsPalindrome(prefix))
			{
				partial_partition->emplace_back(prefix);
				DirectedPalindromePartitioning(input, i, partial_partition, result);
				partial_partition->pop_back();
			}
		}
	}

	vector<vector<string>> PalindromePartitioning(const string& input)
	{
		vector<vector<string>> result;
		DirectedPalindromePartitioning(input, 0, make_unique<vector<string>>().get(), &result);
		return result;
	}
}