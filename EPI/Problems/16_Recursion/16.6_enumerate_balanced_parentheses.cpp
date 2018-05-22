// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<string> GenerateBalancedParentheses(int numPairs)
{
	vector<string> result;
	return result;
}

#pragma region Test

void GenerateBalancedParenthesesSmallTest() 
{
	auto result = GenerateBalancedParentheses(1);
	assert(result.size() == 1 && !result.front().compare("()"));
	result = GenerateBalancedParentheses(2);
	assert(
		result.size() == 2 &&
		((!result.front().compare("(())") && !result.back().compare("()()")) ||
		(!result.front().compare("()()") && !result.back().compare("(())"))));
}

void GenerateBalancedParenthesesTest()
{
#if TEST
	GenerateBalancedParenthesesSmallTest();
#endif
}

#pragma endregion Test