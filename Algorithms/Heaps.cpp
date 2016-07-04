#include "stdafx.h"
#include "Heaps.h"

using namespace std;

// ----------------------------------------------------------
// 11.1 MERGE SORTED FILES
vector<int> MergeSortedFiles(const vector<vector<int>>& files)
{
	// Use a min-heap, then insert the first entry from each file, along with the index of the file it came from. Extract the min, and insert the next value from the file the min came from, if any. Keep going until the min-heap is
	// emptied.
	return vector<int>();
}

// ----------------------------------------------------------
// 11.2 SORT AN INCREASING-DECREASING ARRAY
vector<int> SortIncreasingDecreasingArray(const vector<int>& a)
{
	// Each increasing or decreasing sequence if a sorted sub-array. First, make sure to reverse the order of each decreasing sequence so we end up with a series of sorted sequences. Then we can use solution 11.1 to merge it.
	return vector<int>();
}

// ----------------------------------------------------------
// 11.3 SORT AN ALMOST SORTED ARRAY
vector<int> SortAlmostSortedArray(const vector<int>& a, int k)
{
	// Use a min heap to keep track of k element as we run through the array. Once we have k elements, extract the min and insert the next element in the array, until the entire array is consumed and the min heap is empty.
	// O( n log k)
	return vector<int>();
}

// ----------------------------------------------------------
// 11.4 COMPUTE THE K CLOSEST STARS
vector<int> ComputeKClosestStars(const vector<int>& stars, int k)
{
	// Similar to 11.3, but with a max heap. Run through array, inserting if there is either less than k stars in the max heap, or the star is closer than the max.
	return vector<int>();
}

// ----------------------------------------------------------
// 11.5 COMPUTE THE MEDIAN OF ONLINE DATA
int ComputeMedian(istringstream* s)
{
	// Use a max heap and a min heap and keep the heaps balanced size.
	return 0;
}

// ----------------------------------------------------------
// 11.6 COMPUTE THE K LARGEST ELEMENTS IN A HEAP
vector<int> FindKLargestElementsInHeap(const vector<int>& heap, int k)
{
	// Walk down the tree, adding candidates to another max heap. Process the root. Extract it, then process its children. Extract the max, then process the children of the max. Keep going until you have k results.
	return vector<int>();
}

// ----------------------------------------------------------
// 11.7 IMPLEMENT A STACK API USING A HEAP
//
// A stack needs to return the most recently push element. A heap can support the same functionality by using a timestamp (an index incremented after each insertion) as the key for a max heap.