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
        // To union, append the src list to the dest list, reassign set elements and update heads and tails.
        auto dstSet = y->set;
        auto srcSet = x->set;
        // we are going to iterate over all elements of the src set so make src set is the shortest of the two.
        if (srcSet->length > dstSet->length)
          swap(srcSet, dstSet);
      
        dstSet->tail->next = srcSet->head;
        dstSet->tail = srcSet->tail;
        dstSet->length += srcSet->length;
        // reassign src set elements
        for (auto cur = srcSet->head; cur; cur = cur->next)
          cur->set = dstSet;
        // empty srcSet
        srcSet->head = srcSet->tail = nullptr;
        return dstSet.get();
    }

private:

    shared_ptr<SetElem> head = nullptr, tail = nullptr;
    int length = 0;

};

}