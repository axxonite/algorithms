#include "stdafx.h"
#include "MaxHeap.h"

using namespace std;

// MaxHeap. The value of a node is at most that of its parent. The root node thus always contains the highest value.
class CMaxHeap
{
public:

	// O(lg n)
	explicit CMaxHeap(vector<int> values)
	{
		mSize = values.size();
		mHeap = values;
		// size / 2 is the last possible node that may have children, since its children are size/2*2 and size/2*2+1.
		// This start from the last bottom node, then processes all nodes going left and up to rearrange those nodes in the tree.
		for (int i = values.size() / 2; i >= 0; i--)
			HeapifyNode(i);
	}

	// O(n lg n)
	// A heap has the max value, so grab the max element in the heap, put it at the end of the sort order, then pop the value from the heap.
	static void HeapSort(vector <int>& values)
	{
		CMaxHeap heap(values);
		for (auto i = heap.mSize - 1; i >= 1; i--)
		{
			// The max is at the top of the heap, so put it at the end of the sorted array.
			swap(heap.mHeap[0], heap.mHeap[i]);
			heap.mSize--;
			// We've swapped a value, so put this swapped value in its proper position in the heap.
			heap.HeapifyNode(0);
		}
		values = heap.mHeap;
	}

	// O(1)
	int Max() const { return mHeap[0]; }

	// O(lg n)
	void Pop()
	{
		mHeap[0] = mHeap[mSize - 1];
		mSize--;
		HeapifyNode(0);
	}

	// O(lg n)
	int ExtractMax()
	{
		assert(mSize >= 0);
		auto max = Max();
		Pop();
		return max;
	}

	// O(lg n)
	void IncreaseKey(int i, int value)
	{
		assert(value >= mHeap[i]);
		mHeap[i] = value;
		auto parent = Parent(i);
		// if parent is now smaller than the current node, then we need to swap parent and child.
		while ( i > 0 && mHeap[parent] < mHeap[i])
		{
			swap(mHeap[i], mHeap[parent]);
			i = parent;
		}
	}

	// O(lg n)
	void Insert(int value)
	{
		mHeap[mSize++] = numeric_limits<int>::min();
		IncreaseKey(mSize - 1, value);
	}

private:

	vector<int> mHeap;
	int mSize;

	static int Parent(int i) { return i / 2; }
	static int Left(int i) { return i * 2; }
	static int Right(int i) { return i * 2 + 1; }

	// O(lg n) or O(h)
	void HeapifyNode(int i)
	{
		auto l = Left(i);
		auto r = Right(i);
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

void Heapsort(vector<int>& values)
{
	CMaxHeap::HeapSort(values);
}