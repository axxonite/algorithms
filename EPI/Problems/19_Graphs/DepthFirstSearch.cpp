#include "stdafx.h"

struct DFSGraphVertex
{
	vector<DFSGraphVertex*> edges;
	DFSGraphVertex* pred;
};

void DFS(vector<DFSGraphVertex*> g)
{
}