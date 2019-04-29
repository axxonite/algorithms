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
  int dist = numeric_limits<int>::max();
  int stage = 0;
  int start = -1;
  int start2 = -1;
  int finish = -1;
  GraphVertex* pred = nullptr;
  vector<Edge> edges;  
  vector<Edge> transposedEdges;


  int Index() const { return name - '1'; };
};