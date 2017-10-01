// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

bool IsPalindromeNumber(int x) 
{
	return true;
}

#pragma region Test

bool CheckAns(int x) {
	auto s = to_string(x);
	for (size_t i = 0, j = s.size() - 1; i < j; ++i, --j) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

void IsPalindromeNumberTest() 
{
#if TEST
	default_random_engine gen((random_device())());
	int x;
	uniform_int_distribution<int> dis(-99999, 99999);
	for (int times = 0; times < 1000; ++times) {
		x = dis(gen);
		assert(CheckAns(x) == IsPalindromeNumber(x));
	}
#endif
}

#pragma endregion 