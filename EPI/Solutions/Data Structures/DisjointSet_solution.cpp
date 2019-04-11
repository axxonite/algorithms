#include "stdafx.h"

using namespace std;

namespace Solutions
{
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
      set->head = set->tail = x;
      x->set = set.get();
      set->length = 1;
      return set;
    }

    static DisjointSet* FindSet(shared_ptr<SetElem> x)
    {
      return x->set;
    }

    static DisjointSet* Union(shared_ptr<SetElem> x, shared_ptr<SetElem> y)
    {
      auto dstSet = y->set;
      auto srcSet = x->set;
      if (srcSet->length > dstSet->length)
        swap(srcSet, dstSet);
      for (auto cur = srcSet->head; cur; cur = cur->next)
      {
        cur->set = dstSet;
        dstSet->tail->next = cur;
        dstSet->tail = cur;
        dstSet->length++;
      }
      srcSet->head = srcSet->tail = nullptr;
      return dstSet;
    }

  private:

    shared_ptr<SetElem> head, tail;
    int length = 0;

  };

}