// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void DirectedGenerateBalancedParentheses(const string& s, int remaining, int open, vector<string>& result)
	{
		if (remaining == 0 && open == 0)
		{
			result.emplace_back(s);
			return;
		}
		if (remaining > 0)
			DirectedGenerateBalancedParentheses(s + "(", remaining - 1, open + 1, result);
		if (open > 0)
			DirectedGenerateBalancedParentheses(s + ")", remaining, open - 1, result);
	}

	vector<string> GenerateBalancedParentheses(int num_pairs)
	{
		vector<string> result;
		DirectedGenerateBalancedParentheses("", num_pairs, 0, result);
		return result;
	}
}
