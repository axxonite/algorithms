// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Problems/Problems.h"

#define TEST 0

vector<vector<int>> NQueens(int n)
{
	vector<vector<int>> result;
	return result;
}

#pragma region Test

vector<string> ToTextRepresentation(const vector<int>& col_placement)
{
	vector<string> sol;
	for (int row : col_placement)
	{
		string line(col_placement.size(), '.');
		line[row] = 'Q';
		sol.emplace_back(line);
	}
	return sol;
}

static void SolveNQueensSimpleTest()
{
	auto result = NQueens(2);
	assert(0 == result.size());

	result = NQueens(3);
	assert(0 == result.size());

	result = NQueens(4);
	assert(2 == result.size());

	vector<int> place1 = {1, 3, 0, 2};
	vector<int> place2 = {2, 0, 3, 1};
	assert(result[0] == place1 || result[0] == place2);
	assert(result[1] == place1 || result[1] == place2);
	assert(result[0] != result[1]);
}


void SolveNQueensTest()
{
#if TEST
	SolveNQueensSimpleTest();
	default_random_engine gen((random_device())());
	int n;
	uniform_int_distribution<int> dis(1, 7);
	n = dis(gen);
	//cout << "n = " << n << endl;
	auto result = NQueens(n);
	//for (const vector<int>& vec : result)
	//{
	//	vector<string> text_rep = ToTextRepresentation(vec);
	//	for (const string& s : text_rep)
	//	{
	//		cout << s << endl;
	//	}
	//	cout << endl;
	//}
#endif
}
#pragma endregion Test
