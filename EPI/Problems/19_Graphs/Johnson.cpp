#include "stdafx.h"
#include "GraphVertex.h"
#include "..\..\Solutions\19_Graphs\19.5_clone_graph_solution.h"
#include "..\..\Solutions\19_Graphs\BellmanFord_solution.h"
#include "..\..\Solutions\19_Graphs\Dijkstra_solution.h"

#define TEST 0

bool Johnson(vector<GraphVertex*> G, vector<vector<int>>& result)
{
	return true;
}

#pragma region Test

void JohnsonTest()
{
#if TEST
	unordered_map<char, shared_ptr<GraphVertex>> G;
	G['1'] = make_shared<GraphVertex>(GraphVertex{ '1' });
	G['2'] = make_shared<GraphVertex>(GraphVertex{ '2' });
	G['3'] = make_shared<GraphVertex>(GraphVertex{ '3' });
	G['4'] = make_shared<GraphVertex>(GraphVertex{ '4' });
	G['5'] = make_shared<GraphVertex>(GraphVertex{ '5' });

	G['1']->edges.emplace_back(Edge{ G['2'].get(), 3 });
	G['1']->edges.emplace_back(Edge{ G['3'].get(), 8 });
	G['1']->edges.emplace_back(Edge{ G['5'].get(), -4 });
	G['2']->edges.emplace_back(Edge{ G['4'].get(), 1 });
	G['2']->edges.emplace_back(Edge{ G['5'].get(), 7 });
	G['3']->edges.emplace_back(Edge{ G['2'].get(), 4 });
	G['4']->edges.emplace_back(Edge{ G['3'].get(), -5 });
	G['4']->edges.emplace_back(Edge{ G['1'].get(), 2 });
	G['5']->edges.emplace_back(Edge{ G['4'].get(), 6 });

	vector< GraphVertex*> v;
	v.emplace_back(G['1'].get());
	v.emplace_back(G['2'].get());
	v.emplace_back(G['3'].get());
	v.emplace_back(G['4'].get());
	v.emplace_back(G['5'].get());
	vector<vector<int>> result(v.size(), vector<int>(v.size(), numeric_limits<int>::max()));
	assert(Johnson(v, result));
	assert(result[0][1] == 1);
	assert(result[1][4] == -1);
	assert(result[2][4] == 3);
	assert(result[3][1] == -1);
	assert(result[4][1] == 5);
#endif
}

#pragma endregion