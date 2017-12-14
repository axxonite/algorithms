// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

bool IsArbitrageExist(vector<vector<double>> G)
{
	return false;
}

#pragma region Test

void IsArbitrageExistTest()
{
#if TEST
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> n_dis(1, 100);
	int n = n_dis(gen);
	vector<vector<double>> G(n, vector<double>(n));
	// Assume the input is a complete graph.
	for (size_t i = 0; i < G.size(); ++i)
	{
		G[i][i] = 1;
		for (size_t j = i + 1; j < G.size(); ++j)
		{
			uniform_real_distribution<double> dis(0, 1);
			G[i][j] = dis(gen);
			G[j][i] = 1.0 / G[i][j];
		}
	}
	bool res = IsArbitrageExist(G);
	cout << boolalpha << res << endl;
	vector<vector<double>> g(3, vector<double>(3));
	for (size_t i = 0; i < 3; ++i)
	{
		g[i][i] = 1;
	}
	g[0][1] = 2 , g[1][0] = 0.5 , g[0][2] = g[2][0] = 1 , g[1][2] = 4 ,
		g[2][1] = 0.25;
	res = IsArbitrageExist(g);
	assert(res == true);
	cout << boolalpha << IsArbitrageExist(g) << endl;
#endif
}

#pragma endregion Test
