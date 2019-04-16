#pragma once

#include <limits>
#include <vector>

struct GraphVertex;

struct Edge
{
  GraphVertex* dst;
  int weight;
};

struct GraphVertex
{
  char name;
  int stage = 0;
  int start = -1;
  int finish = -1;
  int dist = numeric_limits<int>::max();
  GraphVertex* pred = nullptr;
  vector<Edge> edges;

  int Index() const { return name - '1'; };
};