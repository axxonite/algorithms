// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include <cassert>
#include <iostream>
#include <random>
#include <string>

using namespace std;

namespace Solutions
{
	int SSDecodeColID(const string& col) 
	{
		int result = 0;
		for (char c : col)
			result = result * 26 + c - 'A' + 1;
		return result;
	}
}