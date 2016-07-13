#include "stdafx.h"
#include "GreedyAlgorithms.h"

using namespace std;

// ----------------------------------------------------------
// 18.1 COMPUTE AN OPTIMUM ASSIGNMENT OF TASKS
struct PairedTasks
{
	int task1, task2;
};

vector<PairedTasks> ComputeOptimumAssignmentOfTasks(vector<int> taskDurations)
{
	// Pair the longuest task with the smallest task. This achieves the lowest average duration per task.
	return vector<PairedTasks>();
}

// ----------------------------------------------------------
// 18.2 SCHEDULE TO MINIMIZE WAITING TIME
int ScheduleToMinimizeWaitingTime(vector<int> times)
{
	// We are trying to minimize the sum of waiting times. The first times will show up in the summation more often than the later terms, so put the shortest waiting times first.
	return 0;
}

// ----------------------------------------------------------
// 18.3 THE INTERVAL COVERING PROBLEM*
struct Interval
{
	int left, right;
};

vector<int> FIndMinimumVisits(vector<Interval> intervals)
{
	// Focus on the block that ends the earliest. Then its endpoint is required to cover said block, and will cover all other blocks that start before that block. Picking an earlier point cannot improve that local solution.
	// Thus, pick the first end point, remove all intervals covered by that endpoint from consideration, pick the next earliest end point, and so forth.
	return vector<int>();
}

// Note for invariants: Maintain an array that is guaranteed to have a solution. 

// ----------------------------------------------------------
// 18.4 THE 3-SUM PROBLEM*
bool HasThreeSum(vector<int> a, int t)
{
	// Sort the input, then use the solution for the 2-sum problem. Pick the first and last items. If tmin + tmax < sum, then tmin is too small and should be rejected. If tmin + tmax > sum, then tmax is too large and should
	// be rejected. For the 3-sum problem, this is modified slightly to be, if Aj + Ak < t - Ai, then go to Aj+1 + Ak (Aj is too small), if Aj + Ak > t - Ai, go to Aj + Ak-1 (Ak is too large).
	return false;
}

// ----------------------------------------------------------
// 18.5 FIND THE MAJORITY ELEMENT**
string FindMajorityElement(stringstream* input)
{
	// Pick the first element as a candidate. If another element of the same type is encountered, increment count, otherwise decrement. If count reaches zero, set count to one and take the new element as the candidate. Because
	// the majority element has >50% of the elements in the array, it's count is guaranteed to be higher than the count for any other element, and it will overwhelm any other count to be the last element standing.
	return string();
}

// ----------------------------------------------------------
// 18.6 THE GASUP PROBLEM*
size_t FindAmpleCity(const vector<int>& gallons, const vector<int>& distances)
{
	// Drawing a graph of the consumption along the circle of cities shows that the graph is always the same no matter which city we start for, it is simply shifted horizontally and vertically; hence the minimum city (the one
	// with the largest gas shortfall) is always the same. Hence, to ensure we never run out of gas during the trip, we should always start at the minimum city. It wasn't clear that the minimum city will always offer enough gas
	// to get to the next city - if it didn't, another city would be the minimum. The problem statement guarantees that there is always at least one solution to the problem.
	return size_t();
}

// ----------------------------------------------------------
// 18.7 COMPUTE TGE MAXIMUM WATER TRAPPED BY A PAIR OF VERTICAL LINES
int GetMaxTrappedWater(const vector<int>& heights)
{
	// Start from the widest pair. If A[0] < A[n - 1] then this is the best possible value for A[0], so now consider the lines from [1..n-1]. If A[0] > A[n - 1], then reject A[n-1] as a candidate with possible further 
	// improvement, instead. Keep going until you cross over. We are exploring the best way to trade off width for height. It's still not clear to me why a local maximum leads to a global maximum, however.
	return 0;
}

// ----------------------------------------------------------
// 18.8 COMPUTE THE LARGEST RECTANGLE UNDER THE SKYLINE**
int ComputeLargestRectangleUnderSkyline(const vector<int>& heights)
{
	// When we iterate, we know that the largest rectangle supported by earlier buildings whose height > Ai cannot extend past i because building i is shorter. All we need to keep track of is buildings that have not been
	// blocked yet. Additionally, we can replace buildings whose height equal that of the current buildings with the current building. Call these buildings the active pillars.
	//
	// The set of active pillars always has an increasing slope. When removing buildings from the pillar set, look for the closest active pillar that has a lower height on the left. The active pillar set is a stack, hence the
	// closest active pillar that has a lower height on the left is the next entry in the stack.
	//
	// Don't forget the end of the algorithm, where we have some active pillars that need to have their rectangles sealed off by the right edge of the skyline.
	return 0;
}