#include "stdafx.h"

#define TEST 0

struct SCCGraphVertex
{
	int data;
	vector<SCCGraphVertex*> edges;
};

vector<unordered_set<SCCGraphVertex*>> StronglyConnectedComponents(vector<shared_ptr<SCCGraphVertex>> G)
{
	vector<unordered_set<SCCGraphVertex*>> result;
  return result;
}

#pragma region Test

void StronglyConnectedComponentsTest()
{
#if TEST
	vector< shared_ptr<SCCGraphVertex>> G;
	for (int i = 0; i < 8; ++i)
		G.emplace_back(make_shared<SCCGraphVertex>(SCCGraphVertex{ i }));

	G[0]->edges.emplace_back(G[1].get());
	G[1]->edges.emplace_back(G[2].get());
	G[1]->edges.emplace_back(G[4].get());
	G[1]->edges.emplace_back(G[5].get());
	G[2]->edges.emplace_back(G[3].get());
	G[2]->edges.emplace_back(G[6].get());
	G[3]->edges.emplace_back(G[2].get());
	G[3]->edges.emplace_back(G[7].get());
	G[4]->edges.emplace_back(G[0].get());
	G[4]->edges.emplace_back(G[5].get());
	G[5]->edges.emplace_back(G[6].get());
	G[6]->edges.emplace_back(G[5].get());
	G[6]->edges.emplace_back(G[7].get());
	G[7]->edges.emplace_back(G[7].get());
	auto result = StronglyConnectedComponents(G);
	assert(result[0] == unordered_set<SCCGraphVertex*>({ G[0].get(), G[1].get(), G[4].get() }));
	assert(result[1] == unordered_set<SCCGraphVertex*>({ G[2].get(), G[3].get() }));
	assert(result[2] == unordered_set<SCCGraphVertex*>({ G[5].get(), G[6].get() }));
	assert(result[3] == unordered_set<SCCGraphVertex*>({ G[7].get() }));
#endif
}

#pragma endregion