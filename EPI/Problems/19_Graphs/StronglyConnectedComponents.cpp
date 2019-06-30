#include "stdafx.h"
#include "GraphVertex.h"

// #define TEST

vector<unordered_set<GraphVertex*>> StronglyConnectedComponents(vector<shared_ptr<GraphVertex>> G)
{
	vector<unordered_set<GraphVertex*>> result;
	return result;
}

#pragma region Test

void StronglyConnectedComponentsTest()
{
#ifdef TEST
	vector<shared_ptr<GraphVertex>> G;
	for (int i = 0; i < 8; ++i)
		G.emplace_back(make_shared<GraphVertex>(GraphVertex()));

	G[0]->edges.emplace_back(Edge{ G[1].get(), 1 });
	G[1]->edges.emplace_back(Edge{ G[2].get(), 1 });
	G[1]->edges.emplace_back(Edge{ G[4].get(), 1 });
	G[1]->edges.emplace_back(Edge{ G[5].get(), 1 });
	G[2]->edges.emplace_back(Edge{ G[3].get(), 1 });
	G[2]->edges.emplace_back(Edge{ G[6].get(), 1 });
	G[3]->edges.emplace_back(Edge{ G[2].get(), 1 });
	G[3]->edges.emplace_back(Edge{ G[7].get(), 1 });
	G[4]->edges.emplace_back(Edge{ G[0].get(), 1 });
	G[4]->edges.emplace_back(Edge{ G[5].get(), 1 });
	G[5]->edges.emplace_back(Edge{ G[6].get(), 1 });
	G[6]->edges.emplace_back(Edge{ G[5].get(), 1 });
	G[6]->edges.emplace_back(Edge{ G[7].get(), 1 });
	G[7]->edges.emplace_back(Edge{ G[7].get(), 1 });
	auto result = StronglyConnectedComponents(G);
	assert(result[0] == unordered_set<GraphVertex*>({ G[0].get(), G[1].get(), G[4].get() }));
	assert(result[1] == unordered_set<GraphVertex*>({ G[2].get(), G[3].get() }));
	assert(result[2] == unordered_set<GraphVertex*>({ G[5].get(), G[6].get() }));
	assert(result[3] == unordered_set<GraphVertex*>({ G[7].get() }));
#endif
}

#pragma endregion