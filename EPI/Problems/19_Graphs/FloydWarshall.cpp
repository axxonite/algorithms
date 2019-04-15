// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

void FloydMarshall(vector<vector<int>>& g)
{
}

void FloydMarshallTest()
{
#if TEST
  vector<vector<int>> g(6, vector<int>(6, numeric_limits<int>::max()));
  for (int i = 0; i < g.size(); ++i)
    g[i][i] = 0;
  g[1][2] = 3;
  g[1][3] = 8;
  g[1][5] = -4;
  g[2][5] = 7;
  g[2][4] = 1;
  g[3][2] = 4;
  g[4][1] = 2;
  g[4][3] = -5;
  g[5][4] = 6;
  FloydMarshall(g);
  assert(g[1] == vector<int>({ numeric_limits<int>::max(),0,1,-3,2,-4 }));
  assert(g[2] == vector<int>({ numeric_limits<int>::max(),3,0,-4,1,-1 }));
  assert(g[3] == vector<int>({ numeric_limits<int>::max(),7,4,0,5,3 }));
  assert(g[4] == vector<int>({ numeric_limits<int>::max(),2,-1,-5,0,-2 }));
  assert(g[5] == vector<int>({ numeric_limits<int>::max(),8,5,1,6,0 }));
#endif
}