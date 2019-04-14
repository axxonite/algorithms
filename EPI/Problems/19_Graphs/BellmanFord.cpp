#include "stdafx.h"

#define TEST 0

struct BFGraphVertex;

struct Edge
{
	BFGraphVertex* dst;
	int weight;
};

struct BFGraphVertex
{
	int data;
	vector<Edge> edges;
	int dist = numeric_limits<int>::max();
	BFGraphVertex* pred = nullptr;
};

bool BellmanFord(vector<BFGraphVertex*> G, int src)
{
	return true;
}

#pragma region Test

void BellmanFordTest()
{
#if TEST
	unordered_map<char, shared_ptr<BFGraphVertex>> G;
	G['s'] = make_shared<BFGraphVertex>(BFGraphVertex{ 's' });
	G['t'] = make_shared<BFGraphVertex>(BFGraphVertex{ 't' });
	G['x'] = make_shared<BFGraphVertex>(BFGraphVertex{ 'x' });
	G['y'] = make_shared<BFGraphVertex>(BFGraphVertex{ 'y' });
	G['z'] = make_shared<BFGraphVertex>(BFGraphVertex{ 'z' });

	G['s']->edges.emplace_back(Edge{ G['t'].get(), 6 });
	G['s']->edges.emplace_back(Edge{ G['y'].get(), 7 });
	G['t']->edges.emplace_back(Edge{ G['x'].get(), 5 });
	G['t']->edges.emplace_back(Edge{ G['y'].get(), 8 });
	G['t']->edges.emplace_back(Edge{ G['z'].get(), -4 });
	G['x']->edges.emplace_back(Edge{ G['t'].get(), -2 });
	G['y']->edges.emplace_back(Edge{ G['x'].get(), -3 });
	G['y']->edges.emplace_back(Edge{ G['z'].get(), 9 });
	G['z']->edges.emplace_back(Edge{ G['s'].get(), 2 });
	G['z']->edges.emplace_back(Edge{ G['x'].get(), 7 });

	vector< BFGraphVertex*> v;
	v.emplace_back(G['s'].get());
	v.emplace_back(G['t'].get());
	v.emplace_back(G['x'].get());
	v.emplace_back(G['y'].get());
	v.emplace_back(G['z'].get());
	assert(BellmanFord(v, 0));
	assert(G['s']->dist == 0);
	assert(G['t']->dist == 2);
	assert(G['x']->dist == 4);
	assert(G['y']->dist == 7);
	assert(G['z']->dist == -2);
#endif
}

#pragma endregion