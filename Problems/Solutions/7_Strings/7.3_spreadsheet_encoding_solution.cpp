// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int SSDecodeColID(const string& col) 
	{
		int result = 0;
		// Notice how multipying the existing resulting by 26 is a convenient way to generate numbers of base 26.
		for (char c : col)
			result = result * 26 + c - 'A' + 1;
		return result;
	}
}