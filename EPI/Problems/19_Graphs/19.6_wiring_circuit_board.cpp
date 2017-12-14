// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct GraphVertex
{
	int d = -1;
	vector<GraphVertex*> edges;
};

bool IsAnyPlacementFeasible(vector<GraphVertex>& g)
{
	return true;
}

#pragma region Test

bool IsTwoColorableDFS(GraphVertex* s)
{
	for (GraphVertex*& t : s->edges)
	{
		if (t->d == -1)
		{
			t->d = s->d + 1;
			if (!IsTwoColorableDFS(t))
				return false;
		}
		else if (t->d == s->d)
			return false;
	}
	return true;
}

bool IsTwoColorable(vector<GraphVertex>* G)
{
	for (GraphVertex& v : *G)
		v.d = -1;

	for (GraphVertex& v : *G)
	{
		if (v.d == -1)
		{
			v.d = 0;
			if (!IsTwoColorableDFS(&v))
				return false;
		}
	}
	return true;
}

void IsAnyPlacementFeasibleTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 90; ++times)
	{
		int n;
		uniform_int_distribution<int> dis(2, 101);
		n = dis(gen);
		vector<GraphVertex> G(n);
		uniform_int_distribution<int> dis2(1, n * (n - 1) / 2);
		int m = dis2(gen);
		//cout << times << ' ' << n << ' ' << m << endl;
		vector<deque<bool>> is_edge_exist(n, deque<bool>(n, false));
		while (m-- > 0)
		{
			uniform_int_distribution<int> dis3(0, n - 1);
			int a, b;
			do
			{
				a = dis3(gen) , b = dis3(gen);
			}
			while (a == b || is_edge_exist[a][b] == true);
			is_edge_exist[a][b] = is_edge_exist[b][a] = true;
			G[a].edges.emplace_back(&G[b]);
			G[b].edges.emplace_back(&G[a]);
		}

		/*
		for (int i = 0; i < G.size(); ++i) {
		cout << i << endl;
		for (int j = 0; j < G[i].edges.size(); ++j) {
		cout << ' ' << G[i].edges[j];
		}
		cout << endl;
		}
		*/
		bool res = IsAnyPlacementFeasible(G);
		//cout << boolalpha << res << endl;
		bool res2 = IsTwoColorable(&G);
		assert(res == res2);
	}
#endif
}

#pragma endregion Test
