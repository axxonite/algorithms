#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>
#include <list>
#include <forward_list>
#include <stack>

using namespace std;

class CGraph
{
public :

	typedef enum
	{
		Undiscovered,
		Discovered,
		Processed
	} Status;

	typedef enum
	{
		Unclassified,
		Tree,
		Back,
		Forward,
		Cross
	} EdgeType;

	struct Node;

	struct Edge
	{
		Node* node = nullptr; // If we want a more compact representation, use an index.
		EdgeType type;
	};

	struct NodeState
	{
		Status status = Undiscovered;
		Node* parent = nullptr;
		int distance = numeric_limits<int>::max();
		int start = 0;
		int finish = 0;
		int component = 0;
	};

	struct Node
	{
		forward_list<Edge> edges;
		NodeState state; // Could be stored in a separate array if needed for a more compact representation.

		void Print() const
		{
			cout << this;
		}
	};

	// O(V+E)
	static bool BFS(Node& s, int component)
	{
		bool bipartite = true;
		s.state.distance = 0;
		s.state.parent = nullptr;
		s.state.status = Discovered;
		queue<Node*> q;
		q.push(&s);
		while (!q.empty())
		{
			auto v = q.front();
			v->state.component = component; // Assign the component index - all new vertices reachable from a BFS form one component.
			q.pop();
			// can do early processing here.
			for (auto& e : v->edges)
			{
				auto edgeNode = e.node;
				v->state.status = Processed;
				
				if (edgeNode->state.status == Undiscovered)
				{
					edgeNode->state.status = Discovered;
					edgeNode->state.distance = v->state.distance + 1;
					edgeNode->state.parent = v;
					q.emplace(edgeNode);
				}
				
				if (edgeNode->state.status != Processed) // If directed, change this to true.
				{
					// Any edge processing goes here.
					if (edgeNode->state.distance % 2 == v->state.distance % 2) // We assign a different color for each distance, hence we go to a distance that maps to the same color, then we are not bipartite.
						bipartite = false;
				}
			}
			// can do late processing here.
		}
		return bipartite;
	}

	static int ConnectedComponents(vector<Node>& nodes)
	{
		int component = 0;
		for (auto& v : nodes)
		{
			if (v.state.status == Undiscovered)
				BFS(v, component++);
		}
		return component;
	}

	// O(V+E)
	static void DFS(vector<Node>& nodes)
	{
		stack<Node*> topoSort;
		int time = 0;
		for (auto& v : nodes)
		{
			if (v.state.status == Undiscovered)
				DFS(v, time, topoSort);
		}
	}

	// Depth first search.
	static bool DFS(Node& v, int& time, stack<Node*>& topoSort)
	{
		bool hasCycle = false;
		time++; // Note time that we discovered node.
		v.state.start = time;
		v.state.status = Discovered;
		// can do early processing here.

		// Iterate all edges.
		for (auto& e : v.edges)
		{
			// If edge is undiscovered, visit it.
			auto edgeNode = e.node;
			if (edgeNode->state.status == Undiscovered)
			{
				edgeNode->state.parent = &v;
				e.type = Tree; // All edges get classified as tree edges here, first.			
				// can process edge here.
				DFS(*edgeNode, time, topoSort);
			}
			else if (edgeNode->state.status != Processed)
			{
				if (v.state.parent != edgeNode)
					hasCycle = true;
				e.type = ClassifyEdge(v, *edgeNode); // Edges get reclassified when they are encountered again.
			}
		}

		// can do late processing here.

		// Note the finish time and mark as completed.
		v.state.status = Processed;
		v.state.finish = ++time;
		topoSort.push(&v);
		// If we want to do a topological sort, this is where we would insert this node at the front of a linked list.

		return hasCycle;
	}

	static EdgeType ClassifyEdge(Node& x, Node& y)
	{
		if (y.state.parent == &x)
			return Tree;
		if (y.state.status == Discovered)
			return Back;
		if (y.state.status == Processed)
			return y.state.start > x.state.start ? Forward : Cross;
		return Unclassified;
	}

	static bool BFSPrintPath(Node* start, Node* end)
	{
		if (start == end)
		{
			start->Print();
			return true;
		}
		if (end->state.parent == nullptr)
			return false; // no path.
		auto result = BFSPrintPath(start, end->state.parent);
		if (result)
			end->Print();
		return result;
	}

private :

	Node* mRoot = nullptr;
	vector<Node> mNodes;
};
