#pragma once

using namespace std;

namespace Solutions
{
  class DisjointSet;

  struct SetElem
  {
    shared_ptr<DisjointSet> set = nullptr;
    shared_ptr<SetElem> next = nullptr;
  };

  class DisjointSet
  {
  public:

    static shared_ptr<DisjointSet> MakeSet(shared_ptr<SetElem> x)
    {
      auto set = make_shared<DisjointSet>();
      set->head = set->tail = x;
	  x->set = set;
      set->length = 1;
      return set;
    }

    static DisjointSet* FindSet(SetElem* x)
    {
      return x->set.get();
    }

    static DisjointSet* Union(SetElem* x, SetElem* y)
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
      return dstSet.get();
    }

  private:

    shared_ptr<SetElem> head = nullptr, tail = nullptr;
    int length = 0;

  };

}