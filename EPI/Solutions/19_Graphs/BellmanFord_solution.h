#pragma once
#include <vector>

struct GraphVertex;

namespace Solutions
{
	bool BellmanFord(vector<GraphVertex*> G, int src);
}