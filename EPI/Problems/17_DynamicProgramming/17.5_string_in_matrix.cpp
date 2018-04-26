// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct HashTuple
{
	size_t operator()(const tuple<int, int, int>& t) const
	{
		// todo how is this hash generated?
		return hash<int>()(get<0>(t) ^ get<1>(t) * 1021 ^ get<2>(t) * 1048573);
	}
};

bool IsPatternContainedInGrid(const vector<vector<int>>& grid, const vector<int>& pattern)
{
	return false;
}

#pragma region Test

vector<vector<int>> RandMatrix(int n)
{
	vector<vector<int>> matrix(n, vector<int>(n));
	default_random_engine gen((random_device())());
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			uniform_int_distribution<int> dis(0, n - 1);
			matrix[i][j] = dis(gen);
		}
	}
	return matrix;
}

// Not an actual test.
void IsPatternContainedInGridTest()
{
#if TEST
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> dis(2, 10);
	int n = dis(gen);
	vector<vector<int>> A = RandMatrix(n);
	for (size_t i = 0; i < A.size(); ++i)
	{
		for (size_t j = 0; j < A[i].size(); ++j)
		{
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "S = ";
	uniform_int_distribution<int> dis2(1, n * n / 2);
	vector<int> S(1 + dis2(gen));
	for (size_t i = 0; i < S.size(); ++i)
	{
		uniform_int_distribution<int> dis3(0, n - 1);
		S[i] = dis3(gen);
	}
	copy(S.begin(), S.end(), ostream_iterator<int>(cout, " "));
	cout << endl << boolalpha << IsPatternContainedInGrid(A, S) << endl;
#endif
}

#pragma endregion Test
