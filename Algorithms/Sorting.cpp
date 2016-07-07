#include "stdafx.h"
#include "Sorting.h"
#include "Lists.h"

using namespace std;

// ----------------------------------------------------------
// 14.1 COMPUTE THE INTERSECTION OF TWO SORTED ARRAYS
vector<int> ComputeIntersectionOfTwoSortedArrays(const vector<int>& a, const vector<int>& b)
{
	// Compare the arrays with each other. Track an iterator for each array and advance the smaller one. Stop when the smaller array has been fully processed. If the arrays are
	// very uneven in length then a a binary search will be faster, as it will skip all the unavailable entries in the larger array.
	return vector<int>();
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
// 14.5 MERGING INTERVALS
struct Interval
{
	int left, right;
};

vector<Interval> MergingInterval(const vector<Interval>& disjointIntervals, Interval newInterval)
{
	// Sort the intervals. First iterate through intervals which are completely before the interval to be added and add them directly. Then, for each interval that intersects the interval to be added, compute the union with 
	// new interval. This union is itsef an interval; iterate through subsequent intervals as long as they intersect with the union we are forming. Then iterate through the remaining intervals and add them to the result.
	return vector<Interval>();
}

// ----------------------------------------------------------
// 14.6 COMPUTE THE UNION OF INTERVALS
struct OpenClosedInterval
{
	int start, end;
	bool open;
};

vector<OpenClosedInterval> ComputeTheUnionOfIntervals(vector<OpenClosedInterval> intervals)
{
	// Sort the intervals. There are a few cases. Let r be the most recently added interval and c be the current interval. If r does not overlap c, add c to the result. If r and c intersect, update r to 
	// include c. If the right endpoint of r is equal to the left endpoint of c, and at least one of the two is closed, updated r to include c.
	return vector<OpenClosedInterval>();
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
NodePtr FastSortingAlgorithmForLists(NodePtr l)
{
	// Implement a merge sort on lists. Find the middle of the list through a fast and slow iterator, and recurse on the sublists.
	return NodePtr();
}

// ----------------------------------------------------------
// 14.10 COMPUTE A SALARY THRESHOLD
double FindSalaryCap(double targetPayrol, vector<double> salaries)
{
	// Sort by distinct salary levels and compute payrolls for each salary level in an array P[]. Find the index in P[] that bounds the target payroll than do P[i] + (target - P[i]) / (n - i) to distribute the remainder of the
	// payroll.
	return 0;
}