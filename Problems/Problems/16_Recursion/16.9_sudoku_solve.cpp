// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

const int kEmptyEntry = 0;

bool SolveSudoku(vector<vector<int>>* partial_assignment)
{
	return false;
}

#pragma region Test

void SolveSudokuTest()
{
#if TEST
	vector<vector<int>> A(9, vector<int>(9, 0));
	A[0] = { 0, 2, 6, 0, 0, 0, 8, 1, 0 };
	A[1] = { 3, 0, 0, 7, 0, 8, 0, 0, 6 };
	A[2] = { 4, 0, 0, 0, 5, 0, 0, 0, 7 };
	A[3] = { 0, 5, 0, 1, 0, 7, 0, 9, 0 };
	A[4] = { 0, 0, 3, 9, 0, 5, 1, 0, 0 };
	A[5] = { 0, 4, 0, 3, 0, 2, 0, 5, 0 };
	A[6] = { 1, 0, 0, 0, 3, 0, 0, 0, 2 };
	A[7] = { 5, 0, 0, 2, 0, 4, 0, 0, 9 };
	A[8] = { 0, 3, 8, 0, 0, 0, 4, 6, 0 };
	assert(SolveSudoku(&A));
	vector<vector<int>> golden_A = {
		{ 7, 2, 6, 4, 9, 3, 8, 1, 5 },{ 3, 1, 5, 7, 2, 8, 9, 4, 6 },
		{ 4, 8, 9, 6, 5, 1, 2, 3, 7 },{ 8, 5, 2, 1, 4, 7, 6, 9, 3 },
		{ 6, 7, 3, 9, 8, 5, 1, 2, 4 },{ 9, 4, 1, 3, 6, 2, 7, 5, 8 },
		{ 1, 9, 4, 8, 3, 6, 5, 7, 2 },{ 5, 6, 7, 2, 1, 4, 3, 8, 9 },
		{ 2, 3, 8, 5, 7, 9, 4, 6, 1 } };
	for (size_t i = 0; i < 9; ++i) {
		for (size_t j = 0; j < 9; ++j) {
			assert(A[i][j] == golden_A[i][j]);
		}
	}
#endif
}

#pragma endregion Test
