// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

vector<vector<int>> GeneratePascalTriangle(int rows) 
{
	vector<vector<int>> result;
	return result;
}

void PascalTriangleTest()
{
#ifdef TEST
	vector<vector<int>> goldenResult;
	goldenResult.emplace_back(vector<int>{1});
	goldenResult.emplace_back(vector<int>{1, 1});
	goldenResult.emplace_back(vector<int>{1, 2, 1});
	goldenResult.emplace_back(vector<int>{1, 3, 3, 1});
	goldenResult.emplace_back(vector<int>{1, 4, 6, 4, 1});
	assert(GeneratePascalTriangle(5) == goldenResult);
#endif
}

#pragma endregion Test