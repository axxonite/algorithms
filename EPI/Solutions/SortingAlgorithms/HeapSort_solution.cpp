#include "stdafx.h"

namespace Solutions
{
  void HeapifyNode(vector<int>& a, int i, int end)
  {
    int left = i * 2, right = i * 2 + 1;
    // Find the largest nodes between the left, right and the current node.
    int largest = left < end && a[left] > a[i] ? left : i;
    largest = right < end && a[right] > a[largest] ? right : largest;
    if (largest != i)
    {
      // If left or right are larger, swap it with the parent, and walk down the tree recursively.
      swap(a[i], a[largest]);
      HeapifyNode(a, largest, end);
    }
  }

  void HeapSort(vector<int>& a)
  {
    // Create max heap.

    // size / 2 is the last possible node that may have children, since its children are size/2*2 and size/2*2+1.
    // This start from the last bottom node, then processes all nodes going left and up to rearrange those nodes in the tree.
    for (int i = a.size() / 2; i >= 0; i--)
      HeapifyNode(a, i, a.size());

    for (auto i = a.size() - 1; i >= 1; i--)
    {
      // The max is at the top of the heap, so put it at the end of the sorted array.
      swap(a[0], a[i]);
      // We've swapped a value, so put this swapped value in its proper position in the heap.
      HeapifyNode(a, 0, i);
    }
  }
}
