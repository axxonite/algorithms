#include "stdafx.h"

using namespace std;

#define TEST 0

class DisjointSet;

struct SetElem
{
  DisjointSet* set = nullptr;
  shared_ptr<SetElem> next = nullptr;
};

class DisjointSet
{
public:

  static shared_ptr<DisjointSet> MakeSet(shared_ptr<SetElem> x)
  {
    auto set = make_shared<DisjointSet>();
    return set;
  }

  static DisjointSet* FindSet(shared_ptr<SetElem> x)
  {
    return nullptr;
  }

  static DisjointSet* Union(shared_ptr<SetElem> x, shared_ptr<SetElem> y)
  {
    return nullptr;
  }

private:

};

#pragma region Test

void DisjointSetTest()
{
  auto a = make_shared<SetElem>();
  auto b = make_shared<SetElem>();
  auto c = make_shared<SetElem>();
  auto d = make_shared<SetElem>();
  auto e = make_shared<SetElem>();
  auto f = make_shared<SetElem>();
  auto g = make_shared<SetElem>();
  auto h = make_shared<SetElem>();
  auto i = make_shared<SetElem>();
  auto j = make_shared<SetElem>();
  auto setA = DisjointSet::MakeSet(a);
  auto setB = DisjointSet::MakeSet(b);
  auto setC = DisjointSet::MakeSet(c);
  auto setD = DisjointSet::MakeSet(d);
  auto setE = DisjointSet::MakeSet(e);
  auto setF = DisjointSet::MakeSet(f);
  auto setG = DisjointSet::MakeSet(g);
  auto setH = DisjointSet::MakeSet(h);
  auto setI = DisjointSet::MakeSet(i);
  auto setJ = DisjointSet::MakeSet(j);
  DisjointSet::Union(b, d);
  DisjointSet::Union(e, g);
  DisjointSet::Union(a, c);
  DisjointSet::Union(h, i);
  DisjointSet::Union(a, b);
  DisjointSet::Union(e, f);
  
  auto testSet = DisjointSet::FindSet(a);
  assert(DisjointSet::FindSet(b) == testSet);
  assert(DisjointSet::FindSet(c) == testSet);
  assert(DisjointSet::FindSet(d) == testSet);

  testSet = DisjointSet::FindSet(e);
  assert(DisjointSet::FindSet(f) == testSet);
  assert(DisjointSet::FindSet(g) == testSet);

  testSet = DisjointSet::FindSet(h);
  assert(DisjointSet::FindSet(i) == testSet);

#if TEST
  DisjointSet s({});
#endif
}

#pragma endregion