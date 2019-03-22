#include "stdafx.h"

using namespace std;
namespace Solutions
{

  class CMaxHeap
  {
  public:

    CMaxHeap(vector<int> values)
    {
      mSize = values.size();
      mHeap = values;
      // size / 2 is the last possible node that may have children, since its children are size/2*2 and size/2*2+1.
      // This start from the last bottom node, then processes all nodes going left and up to rearrange those nodes in the tree.
      for (int i = values.size() / 2; i >= 0; i--)
        HeapifyNode(i);
    }

    int Max() const { return mHeap.front(); }

    void Pop()
    {
      mHeap[0] = mHeap[mSize - 1];
      mSize--;
      HeapifyNode(0);
    }

    int ExtractMax()
    {
      if (mSize == 0)
        throw length_error("max-heap is empty");
      int max = Max();
      Pop();
      return max;
    }

    void IncreaseKey(int i, int value)
    {
      assert(value >= mHeap[i]);
      mHeap[i] = value;
      int parent = i / 2;
      // if parent is now smaller than the current node, then we need to swap parent and child.
      while (i > 0 && mHeap[parent] < mHeap[i])
      {
        swap(mHeap[i], mHeap[parent]);
        i = parent;
      }
    }

    void InsertKey(int value)
    {
      mHeap[mSize++] = numeric_limits<int>::min();
      IncreaseKey(mSize - 1, value);
    }

  private:

    vector<int> mHeap;
    int mSize;

    void HeapifyNode(int i)
    {
      auto l =  i * 2;
      auto r = i * 2 + 1;
      // Find the largest nodes between the left, right and the current node.
      auto largest = l < mSize && mHeap[l] > mHeap[i] ? l : i;
      largest = r < mSize && mHeap[r] > mHeap[largest] ? r : largest;
      if (largest != i)
      {
        // If left or right are larger, swap it with the parent, and walk down the tree recursively.
        swap(mHeap[i], mHeap[largest]);
        HeapifyNode(largest);
      }
    }
  };
}