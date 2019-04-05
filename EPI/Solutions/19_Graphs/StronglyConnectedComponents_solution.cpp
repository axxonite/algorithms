#include "stdafx.h"

namespace Solutions
{
	struct SCCGraphVertex
	{
		int data;
		bool discovered[2] = { false, false };
		int finishTime = -1;
		vector<shared_ptr<SCCGraphVertex>> edges;
		vector<shared_ptr<SCCGraphVertex>> edgesTransposed;
	};

	void SCCDFS1(shared_ptr<SCCGraphVertex> v, int& time)
	{
		if (v->discovered[0])
			return;
		v->discovered[0] = true;
		for (auto e : v->edges)
			SCCDFS1(e, time);
		for (auto e : v->edges)
			e->edgesTransposed.emplace_back(v);
		v->finishTime = time++;
	}

	bool SortEdges(const shared_ptr<SCCGraphVertex>& a, const shared_ptr<SCCGraphVertex>& b)
	{
		return a->finishTime > b->finishTime;
	}

	void SCCDFS2(shared_ptr<SCCGraphVertex> v, int& time, unordered_set<shared_ptr<SCCGraphVertex>>& component)
	{
		if (v->discovered[1])
			return;
		v->discovered[1] = true;
		sort(v->edgesTransposed.begin(), v->edgesTransposed.end(), SortEdges);
		for (auto e : v->edgesTransposed)
			SCCDFS2(e, time, component);
		component.emplace(v);
	}

	vector<unordered_set<shared_ptr<SCCGraphVertex>>> StronglyConnectedComponents(vector<shared_ptr<SCCGraphVertex>> G)
	{
		vector<unordered_set<shared_ptr<SCCGraphVertex>>> result;
		int time = 0;
		for (auto e : G)
			if (!e->discovered[0])
				SCCDFS1(e, time);
		for (auto e : G)
			if (!e->discovered[1])
			{
				result.emplace_back(unordered_set<shared_ptr<SCCGraphVertex>>());
				SCCDFS2(e, time, result.back());
			}
		return result;
	}
}