#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class CGraph
{
public :

	struct SNode
	{
		int state;
		SNode* parent;
		int distance;
		int start;
		int finish;
		vector<SNode*> edges;

		void Print() const
		{
			cout << this;
		}
	};

	CGraph() : mRoot(nullptr), mTime(0)
	{
	}

	// O(V+E)
	void BFS(SNode* s)
	{
		for (auto it = mNodes.begin(); it != mNodes.end(); ++it)
		{
			it->state = 0;
			it->distance = numeric_limits<int>::max();
			it->parent = nullptr;
		}
		s->distance = 0;
		s->parent = nullptr;
		queue<SNode> q;
		q.push(*s);
		while (!q.empty())
		{
			auto u = q.front();
			q.pop();
			for (auto it = u.edges.begin(); it != u.edges.end(); ++it)
			{
				auto e = *it;
				if (e->state == 0)
				{
					e->state = 1;
					e->distance = u.distance + 1;
					e->parent = &u;
				}
			}
			u.state = 2;
		}
	}

	// O(V+E)
	void DFS()
	{
		// Initialize all nodes to undiscovered.
		mTime = 0;
		for (auto it = mNodes.begin(); it != mNodes.end(); ++it)
		{
			it->state = 0;
			it->parent = nullptr;
		}

		// Visit all undiscovered nodes.
		for (auto it = mNodes.begin(); it != mNodes.end(); ++it)
		{
			if (it->state == 0)
				DFSVisit(&(*it));
		}
	}

	// Depth first search.
	void DFSVisit(SNode* u)
	{
		mTime++;
		// Note time that we discovered node.
		u->start = mTime;
		u->state = 1;

		// Iterate all edges.
		for (auto it = u->edges.begin(); it != u->edges.end(); ++it)
		{
			auto edge = *it;
			// If edge is undiscovered, visit it.
			if (edge->state == 0)
			{
				edge->parent = u;
				DFSVisit(edge);
			}
		}
		// Note the finish time and mark as completed. Note that there is no intermediary "gray" state.
		u->state = 2;
		mTime++;
		u->finish = mTime;
		// If we want to do a topological sort, this is where we would insert this node at the front of a linked list.
	}

	bool BFSPrintPath(SNode* start, SNode* end) const
	{
		if (start == end)
		{
			start->Print();
			return true;
		}
		else if (end->parent == nullptr)
		{
			// no path.
			return false;
		}
		else
		{
			auto result = BFSPrintPath(start, end->parent);
			if (result)
				end->Print();
			return result;
		}
	}

private :

	SNode* mRoot;
	int mTime;
	vector<SNode> mNodes;
};
