// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	string MajoritySearch(istringstream* input_stream)
	{
		string candidate, iter;
		int candidate_count = 0;
		while (*input_stream >> iter)
		{
			if (candidate_count == 0)
			{
				candidate = iter;
				candidate_count = 1;
			}
			else if (candidate == iter)
				++candidate_count;
			else
				--candidate_count;
		}
		return candidate;
	}
}