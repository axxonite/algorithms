#include "stdafx.h"

#define TEST 0

struct SCCGraphVertex
{
	int data;
	vector<shared_ptr<SCCGraphVertex>> edges;
};

vector<unordered_set<shared_ptr<SCCGraphVertex>>> StronglyConnectedComponents(vector<shared_ptr<SCCGraphVertex>> G)
{
	vector<unordered_set<shared_ptr<SCCGraphVertex>>> result;
	return result;
}

#pragma region Test

void StronglyConnectedComponentsTest()
{
#if TEST
	vector< shared_ptr<SCCGraphVertex>> G;
	for (int i = 0; i < 8; ++i)
		G.emplace_back(make_shared<SCCGraphVertex>(SCCGraphVertex{ i }));

	G[0]->edges.emplace_back(G[1]);
	G[1]->edges.emplace_back(G[2]);
	G[1]->edges.emplace_back(G[4]);
	G[1]->edges.emplace_back(G[5]);
	G[2]->edges.emplace_back(G[3]);
	G[2]->edges.emplace_back(G[6]);
	G[3]->edges.emplace_back(G[2]);
	G[3]->edges.emplace_back(G[7]);
	G[4]->edges.emplace_back(G[0]);
	G[4]->edges.emplace_back(G[5]);
	G[5]->edges.emplace_back(G[6]);
	G[6]->edges.emplace_back(G[5]);
	G[6]->edges.emplace_back(G[7]);
	G[7]->edges.emplace_back(G[7]);
	auto result = StronglyConnectedComponents(G);
	assert(result[0] == unordered_set<shared_ptr<SCCGraphVertex>>({ G[0], G[1], G[4] }));
	assert(result[1] == unordered_set<shared_ptr<SCCGraphVertex>>({ G[2], G[3] }));
	assert(result[2] == unordered_set<shared_ptr<SCCGraphVertex>>({ G[5], G[6] }));
	assert(result[3] == unordered_set<shared_ptr<SCCGraphVertex>>({ G[7] }));
#endif
}

#pragma endregion