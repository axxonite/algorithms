#include "stdafx.h"

struct BFSGraphVertex
{
  vector<BFSGraphVertex*> edges;
  int dist = -1;
  BFSGraphVertex* pred = nullptr;
};

void BFS(vector<BFSGraphVertex*> g)
{
}