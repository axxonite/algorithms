#include "stdafx.h"
#include "GraphVertex.h"
#include "..\..\Solutions\19_Graphs\19.5_clone_graph_solution.h"
#include "..\..\Solutions\19_Graphs\BellmanFord_solution.h"
#include "..\..\Solutions\19_Graphs\Dijkstra_solution.h"

namespace Solutions
{
	bool Johnson(vector<GraphVertex*> G, vector<vector<int>>& result)
	{
		auto reweighted = Solutions::CloneGraph(G);
		auto s = make_shared<GraphVertex>(GraphVertex());
		for (auto v : reweighted)
			s->edges.emplace_back(Edge{ v, 0 });
		reweighted.emplace_back(s.get());
		if (!Solutions::BellmanFord(reweighted, reweighted.size() - 1))
			return false;
		for (int i = 0; i < G.size(); ++i)
			for (int j = 0; j < G[i]->edges.size(); ++j)
				G[i]->edges[j].weight = G[i]->edges[j].weight + reweighted[i]->dist - reweighted[i]->edges[j].dst->dist;
		for (int i = 0; i < G.size(); ++i)
		{
			for (int j = 0; j < G.size(); ++j)
				G[j]->dist = numeric_limits<int>::max();
			Solutions::Dijkstra(G, i);
			for (int j = 0; j < G.size(); ++j)
				result[i][j] = G[j]->dist + reweighted[j]->dist - reweighted[i]->dist;
		}
		return true;
	}
}