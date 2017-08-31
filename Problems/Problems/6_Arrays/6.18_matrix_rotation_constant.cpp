// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

void RotateMatrix(vector<vector<int>>* A_ptr)
{
}

#pragma region Test

class RotatedMatrix
{
public:
	explicit RotatedMatrix(vector<vector<int>>* square_matrix) : square_matrix_(*square_matrix)
	{
	}

	int ReadEntry(int i, int j) const
	{
		return square_matrix_[square_matrix_.size() - 1 - j][i];
	}

	void WriteEntry(int i, int j, int v)
	{
		square_matrix_[square_matrix_.size() - 1 - j][i] = v;
	}

private:
	vector<vector<int>>& square_matrix_;
};

void CheckAnswer(vector<vector<int>> A, const vector<vector<int>>& B)
{
	RotatedMatrix rA(&A);
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < A.size(); ++j)
		{
			assert(rA.ReadEntry(i, j) == B[i][j]);
		}
	}
}

void RotateMatrixTest()
{
#if TEST
	int n;
	default_random_engine gen((random_device())());
	for (int times = 0; times < 10; ++times)
	{
		uniform_int_distribution<int> dis(1, 10);
		n = dis(gen);
		vector<vector<int>> A(1 << n, vector<int>(1 << n));
		int k = 1;
		for (int i = 0; i < A.size(); ++i)
		{
			for (int j = 0; j < A[i].size(); ++j)
			{
				A[i][j] = k++;
			}
		}
		vector<vector<int>> B(A);
		RotateMatrix(&B);
		CheckAnswer(A, B);
	}
#endif
}

#pragma endregion Test
