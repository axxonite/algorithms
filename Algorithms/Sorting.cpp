#include "stdafx.h"
#include "Sorting.h"
#include "Lists.h"
#include <algorithm>

using namespace std;

// ----------------------------------------------------------
// 14.1 COMPUTE THE INTERSECTION OF TWO SORTED ARRAYS *
vector<int> ComputeIntersectionOfTwoSortedArrays(const vector<int>& a, const vector<int>& b)
{
	// Compare the arrays with each other. Track an iterator for each array and advance the smaller one. Stop when the smaller array has been fully processed. If the arrays are
	// very uneven in length then a a binary search will be faster, as it will skip all the unavailable entries in the larger array.
	vector<int> result;
	for ( auto aIt = a.begin(), bIt = b.begin(); aIt != a.end() && bIt != b.end(); )
	{
		if (*aIt == *bIt && (result.empty() || *aIt != result.back()))
		{
			result.emplace_back(*aIt);     
			++aIt, ++bIt;
		} 
		else if (*aIt <= *bIt)
			++aIt;
		else ++bIt;
	}
	return result;
}

void TestComputeIntersectionOfTwoSortedArrays()
{
	vector<int> a = {2, 3, 3, 5, 7, 11};
	vector<int> b = {3, 3, 7, 15, 31};
	auto r = ComputeIntersectionOfTwoSortedArrays(a, b);
	assert(r == vector<int>({3, 7}));
}

// ----------------------------------------------------------
// 14.2 MERGE TWO SORTED ARRAYS
void MergeTwoSortedArrays(int A[], int m, int B[], int n)
{
	// Go backwards from longer array. Compare with other array, and insert larger values at the end.
}

// ----------------------------------------------------------
// 14.3 REMOVE FIRST NAME DUPLICATES
struct Name
{
	string first, last;
};

void RemoveFirstNameDuplicates(vector<Name>& names)
{
	// Sort the names. Skip first names when they are they same as the previous first name.
}

// ----------------------------------------------------------
// 14.4 RENDER A CALENDAR
struct Event
{
	int start, finish;
};

int FindMaxSimultaneousEvents(const vector<Event>& events)
{
	// Sort endpoints. Increase and decrease count as we enter and leave events, and keep the max.
	return 0;
}

// ----------------------------------------------------------
// 14.5 MERGING INTERVALS *
struct Interval
{
	int left, right;

	bool operator == (const Interval& b) const
	{
		return left == b.left && right == b.right;
	}
};

vector<Interval> MergingInterval(const vector<Interval>& disjointIntervals, Interval newInterval)
{
	// Sort the intervals. First iterate through intervals which are completely before the interval to be added and add them directly. Then, for each interval that intersects the interval to be added, compute the union with 
	// new interval. This union is itsef an interval; iterate through subsequent intervals as long as they intersect with the union we are forming. Then iterate through the remaining intervals and add them to the result.
	vector<Interval> result;
	int i = 0;
	while ( i < disjointIntervals.size() && disjointIntervals[i].right < newInterval.left )
		result.emplace_back(disjointIntervals[i++]);
	Interval u = newInterval;
	while ( i < disjointIntervals.size() && disjointIntervals[i].left < newInterval.right )
		u = { min(u.left, disjointIntervals[i].left), max(u.right, disjointIntervals[i++].right) };
	result.emplace_back(u);
	result.insert(result.end(), disjointIntervals.begin() + i, disjointIntervals.end()); // Note the use of insert instead of making a third loop to add the array.
	return result;
}

void TestMergingIntervals()
{
	vector<Interval> a = {{-4, -1}, {0,2}, {3, 6}, {7, 9}, {11, 12}, {14, 17}};
	auto r = MergingInterval(a, {1, 8});
	vector < Interval> ref = { {-4, -1}, {0, 9}, {11, 12}, {14, 17} };
	assert(r == ref);
}

// ----------------------------------------------------------
// 14.6 COMPUTE THE UNION OF INTERVALS *
struct OpenClosedInterval
{
	int left, right;
	bool leftClosed, rightClosed;
	
	bool operator < (const OpenClosedInterval& b ) const
	{
		if ( left != b.left )
			return left < b.left;
		return leftClosed && !b.leftClosed;
	}

	bool operator == (const OpenClosedInterval& b) const
	{
		return left == b.left && right == b.right && leftClosed == b.leftClosed && rightClosed == b.rightClosed;
	}
};

vector<OpenClosedInterval> ComputeTheUnionOfIntervals(vector<OpenClosedInterval> intervals)
{
	// Sort the intervals. There are a few cases. Let r be the most recently added interval and c be the current interval. If r does not overlap c, add c to the result. If r and c intersect, update r to 
	// include c. If the right endpoint of r is equal to the left endpoint of c, and at least one of the two is closed, updated r to include c.
	if ( intervals.empty() )
		return intervals;
	sort(intervals.begin(), intervals.end());
	vector<OpenClosedInterval> result;
	auto& r = intervals.front();
	for ( int i = 1; i < intervals.size(); i++)
	{
		if (intervals[i].left < r.right || (intervals[i].left == r.right && (intervals[i].leftClosed || r.rightClosed))) // Extremely tricky.
		{
			if (intervals[i].right > r.right || (intervals[i].right == r.right && intervals[i].rightClosed)) // Extremely tricky.
			{
				r.right = intervals[i].right;
				r.rightClosed = intervals[i].rightClosed;
			}
		}
		else
		{
			result.emplace_back(r);
			r = intervals[i];
		}
	}
	result.emplace_back(r);
	return result;
}

void TestComputeTheUnionOfIntervals()
{
	vector<OpenClosedInterval> intv = {{0, 3, false, false}, {1, 1, true, true}, {2, 4, true, true}, {3, 4, true, false}, {5, 7, true, false}, {7,8,true, false}, {8, 11, true, false}, {9, 11, false, true}, {12, 14, true, true}, {12, 16, false, true}, {13, 15, false, false}, {16, 17, false, false}};
	auto r = ComputeTheUnionOfIntervals(intv);
	vector<OpenClosedInterval> solution = { {0, 4, false, true}, {5, 11, true, true}, {12, 17, true, false} };
	assert(r == solution);
}

// ----------------------------------------------------------
// 14.7 PARTITIONING AND SORTING AN ARRAY WITH MANY REPEATED ENTRIES
struct Person
{
	int age;
	string name;
};

void PatitioningAndSortingAnArrayWithManyRepeatedEntries(vector<Person>& persons)
{
	// Compute frequency of each age, then compute position of each age in the array. Then move through the array, swapping students with their final position. This is a variation on counting sort.
}

// ----------------------------------------------------------
// 14.8 TEAM PHOTO DAY
//
// Sort both teams. Then the photo can be taken if there is one team is < than the other team for every sorted element.

// ----------------------------------------------------------
// 14.9 IMPLEMENT A FAST SORTING ALGORITHM FOR LISTS*

NodePtr MergeSortedLists(NodePtr l, NodePtr r)
{
	NodePtr result, curResult;
	while ( l != nullptr && r!= nullptr)
	{
		NodePtr lesser;
		if ( l->value <= r->value )
			lesser = l, l= l->next;
		else
			lesser = r, r= r->next;
		if ( curResult )
			curResult = curResult->next = lesser;
		else curResult = result = lesser;
	}
	curResult->next = l != nullptr ? l: r;
	return result;
}

NodePtr MergeSort(NodePtr l)
{
	// Implement a merge sort on lists. Find the middle of the list through a fast and slow iterator, and recurse on the sublists.
	if (l == nullptr || l->next == nullptr)
		return l;
	NodePtr prevMid = nullptr, mid = l, fast = l;
	while ( fast && fast->next)
	{
		prevMid  = mid;
		mid = mid->next;
		fast = fast->next->next;
	}
	prevMid->next = nullptr;   
	return MergeSortedLists(MergeSort(l), MergeSort(mid));
}

NodePtr FastSortingAlgorithmForLists(NodePtr l)
{
	// Implement a merge sort on lists. Find the middle of the list through a fast and slow iterator, and recurse on the sublists.
	return MergeSort(l);
}

void TestMergeSortedLists()
{
	NodePtr l = BuildList({4, 5, 6, 2, 1, 0, 3, 7});
	auto r = FastSortingAlgorithmForLists(l);
	auto lastValue = -1;
	for ( NodePtr it = r; it != nullptr; it = it->next )
	{
		assert(it->value == lastValue + 1);
		lastValue = it->value;
	}
}

// ----------------------------------------------------------
// 14.10 COMPUTE A SALARY THRESHOLD *
double FindSalaryCap(double targetPayrol, vector<double> salaries)
{
	// Sort by distinct salary levels and compute payrolls for each salary level in an array P[]. Find the index in P[] that bounds the target payroll than do P[i] + (target - P[i]) / (n - i) to distribute the remainder of the
	// payroll.
	return 0;
}

void TestSorting()
{
	TestComputeIntersectionOfTwoSortedArrays();
	TestMergingIntervals();
	TestComputeTheUnionOfIntervals();
	TestMergeSortedLists();
}