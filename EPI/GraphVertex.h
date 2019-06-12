#pragma once

#include <limits>
#include <vector>

struct GraphVertex;

enum class EdgeClassification
{
	Tree,
	Back,
  Forward,
  Cross,
  Unknown
};

struct Edge
{
	GraphVertex* dst;
	int weight;
};

struct GraphVertex
{
	string name;
	int dist = numeric_limits<int>::max();
	int stage = 0;
	int start = -1;
	int start2 = -1;
	int finish = -1;

	GraphVertex* pred = nullptr;
  GraphVertex* reachableAncestor = nullptr;
	vector<Edge> edges;
	vector<Edge> transposedEdges;

	// for articulation vertices.
	int degree = 0;
	GraphVertex* reachableAncestor;

	int Index() const { return name.back() - '1'; };

	bool operator < ( const GraphVertex& rhs ) const
	{
		return name < rhs.name;
	}
};