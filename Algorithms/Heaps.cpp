#include "stdafx.h"
#include "Heaps.h"
#include <functional>
#include <queue>
#include <sstream>

using namespace std;

// ----------------------------------------------------------
// 11.1 MERGE SORTED FILES*
struct FileLocation
{
    bool operator > (const FileLocation& b ) const // Watch for const
    {
        return *fileBegin > *b.fileBegin; // Note that we must sort on the value, not the iterator.
    }
    

	vector<int>::const_iterator fileBegin;
    vector<int>::const_iterator fileEnd;
}; // Don't forget the semicolon.

vector<int> MergeSortedFiles(const vector<vector<int>>& files)
{
    // Use a min-heap, then insert the first entry from each file, along with the index of the file it came from. Extract the min, and insert the next value from the file the min came from, if any. Keep going until the min-heap is
    // emptied.
    priority_queue<FileLocation, vector<FileLocation>, greater<>> minHeap; // Notice how the min heap is declared. I hate c++ now.
    for ( const vector<int>& file : files )
        if ( !file.empty() )
            minHeap.emplace(FileLocation{file.cbegin(), file.cend()}); // Notice the use of constant iterators with cbegin and cend.
    
    vector<int> result;
	while (!minHeap.empty())
	{
		auto smallest = minHeap.top();
		minHeap.pop();
		result.emplace_back(*smallest.fileBegin);
		auto nextIt = next(smallest.fileBegin);
		if (nextIt != smallest.fileEnd)
			minHeap.emplace(FileLocation{ nextIt, smallest.fileEnd });  // Notice the use of next.       
	}
    return result;
}

void TestMergeSortedFiles()
{
	vector<int> a({0, 3, 6, 8, 13, 15, 20});
	vector<int> b({2, 5, 9, 17, 19, 20, 22});
	vector<vector<int>> c({ a, b });
	auto r = MergeSortedFiles(c);
	assert(r == vector<int>({0, 2, 3, 5, 6, 8, 9, 13, 15, 17, 19, 20, 20, 22}));
}

// ----------------------------------------------------------
// 11.2 SORT AN INCREASING-DECREASING ARRAY
vector<int> SortIncreasingDecreasingArray(const vector<int>& a)
{
	// Each increasing or decreasing sequence if a sorted sub-array. First, make sure to reverse the order of each decreasing sequence so we end up with a series of sorted sequences. Then we can use solution 11.1 to merge it.
	return vector<int>();
}

// ----------------------------------------------------------
// 11.3 SORT AN ALMOST SORTED ARRAY*
vector<int> SortAlmostSortedArray(const vector<int>& a, int k)
{
    // Use a min heap to keep track of k element as we run through the array. Once we have k elements, extract the min and insert the next element in the array, until the entire array is consumed and the min heap is empty.
    // O( n log k)
    priority_queue<int, vector<int>, greater<>> minHeap;
    vector<int> result;
    auto it = a.begin();
    while ( it != a.end() || !minHeap.empty() )
    {
         if ( it != a.end() )
            minHeap.push(*it++);
        if ( static_cast<int>(minHeap.size()) >= k + 1 || it == a.end() )
        {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    return result;
}

void TestSortAlmostSortedArray()
{
	vector<int> a({1, 0, 2, 4,  3, 6, 5, 7, 8, 10, 9});
	auto r = SortAlmostSortedArray(a, 1);
	assert(r == vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8,9, 10}));
}

// ----------------------------------------------------------
// 11.4 COMPUTE THE K CLOSEST STARS
vector<int> ComputeKClosestStars(const vector<int>& stars, int k)
{
	// Similar to 11.3, but with a max heap. Run through array, inserting if there is either less than k stars in the max heap, or the star is closer than the max.
	return vector<int>();
}

// ----------------------------------------------------------
// 11.5 COMPUTE THE MEDIAN OF ONLINE DATA*
int ComputeMedian(stringstream* s)
{
    // Use a max heap and a min heap and keep the heaps balanced size.
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int, vector<int>, less<>> maxHeap;
    int x;
    while (*s >> x) // really need to memorize this syntax.
    {
        if ( minHeap.size() == maxHeap.size())
            maxHeap.push(x);
        else minHeap.push(x);
        if ( !minHeap.empty() && maxHeap.top() > minHeap.top())
        {
            int more = maxHeap.top();
            int less = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            minHeap.push(more);
            maxHeap.push(less);
        }
    }
    if (!maxHeap.empty())
        return maxHeap.top();
    return 0;
}

void TestComputeMedian()
{
	stringstream a;
	a << "0 1 2 3 4 5 6 7 8 9 10";
	int r = ComputeMedian(&a);
	assert(r == 5);
}

// ----------------------------------------------------------
// 11.6 COMPUTE THE K LARGEST ELEMENTS IN A HEAP*
struct HeapEntry {
    int index, value;
};

vector<int> FindKLargestElementsInHeap(const vector<int>& heap, int k)
{
    // Walk down the tree, adding candidates to another max heap. Process the root. Extract it, then process its children. Extract the max, then process the children of the max. Keep going until you have k results.
    priority_queue<HeapEntry, vector<HeapEntry>, function<bool(HeapEntry, HeapEntry)>> candidatesMaxHeap(
        [](const HeapEntry& a, const HeapEntry& b) -> bool { return a.value < b.value; }); // Note the (horrible) lambda syntax.
    
    vector<int> result;
    candidatesMaxHeap.push(HeapEntry{1, heap[0]});    
    while (static_cast<int>(result.size()) < k && !candidatesMaxHeap.empty())
    {
        auto maxValue = candidatesMaxHeap.top();
        candidatesMaxHeap.pop();
        result.emplace_back(maxValue.value);
        if (maxValue.index * 2 < static_cast<int>(heap.size()))
        {
            candidatesMaxHeap.push(HeapEntry{maxValue.index * 2, heap[maxValue.index * 2 - 1]});
            candidatesMaxHeap.push(HeapEntry{maxValue.index * 2 + 1, heap[maxValue.index * 2]});        
        }
    }    
    return result;
}

void TestFindKLargestElementsInHeap()
{
	vector<int> a({561, 314, 401, 28, 156, 359, 271, 11, 3});
	auto r = FindKLargestElementsInHeap(a, 4);
	assert(r == vector<int>({561, 401, 359, 314}));
}

// ----------------------------------------------------------
// 11.7 IMPLEMENT A STACK API USING A HEAP*
//
// A stack needs to return the most recently push element. A heap can support the same functionality by using a timestamp (an index incremented after each insertion) as the key for a max heap.

void TestHeaps()
{
	TestMergeSortedFiles();
	TestSortAlmostSortedArray();
	TestComputeMedian();
	TestFindKLargestElementsInHeap();
}