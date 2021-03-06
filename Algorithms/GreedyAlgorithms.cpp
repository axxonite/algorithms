#include "stdafx.h"
#include "GreedyAlgorithms.h"
#include <algorithm>
#include <sstream>
#include <stack>

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

vector<int> FindMinimumVisits(vector<Interval> intervals)
{
    // Focus on the block that ends the earliest. Then its endpoint is required to cover said block, and will cover all other blocks that start before that block. Picking an earlier point cannot improve that local solution.
    // Thus, pick the first end point, remove all intervals covered by that endpoint from consideration, pick the next earliest end point, and so forth.
    if ( intervals.empty() )
        return vector<int>();
	sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) -> bool { return a.right < b.right; }); // Note how the sort lambda needs to the < operator.
    int lastVisitTime = intervals.front().right;
    vector<int> result = { lastVisitTime };
    for ( const Interval& interval : intervals) // Note how we avoid changing the array.
    {
        if ( interval.left > lastVisitTime )
        {
            lastVisitTime = interval.right;
            result.emplace_back(lastVisitTime);
        }        
    }
    return result;
}

void TestFindMinimumVisits()
{
	vector<Interval> intervals = {{1, 2}, {2, 3}, {3, 4}, {2, 3}, {3, 4}, {4, 5}};
	auto r = FindMinimumVisits(intervals);
	assert(r == vector<int>({2, 4}));
}

// Note for invariants: Maintain an array that is guaranteed to have a solution. 

// ----------------------------------------------------------
// 18.4 THE 3-SUM PROBLEM*
bool HasThreeSum(vector<int> a, int t)
{
    // Sort the input, then use the solution for the 2-sum problem. Pick the first and last items. If tmin + tmax < sum, then tmin is too small and should be rejected. If tmin + tmax > sum, then tmax is too large and should
    // be rejected. For the 3-sum problem, this is modified slightly to be, if Aj + Ak < t - Ai, then go to Aj+1 + Ak (Aj is too small), if Aj + Ak > t - Ai, go to Aj + Ak-1 (Ak is too large).
    sort(a.begin(), a.end());
    for ( int valueI : a )
    {
        auto remainder = t - valueI;
        int j = 0, k = a.size() - 1;
        while ( j <= k )
        {
            auto sum = a[j] + a[k];
            if ( sum < remainder )
                j++;
            else if ( sum > remainder )
                k--;
            else return true;
        }
    }
    return false;
}

void TestHasThreeSum()
{
	vector<int> a = {11, 2, 5, 7, 3};
	assert(HasThreeSum(a, 21));
	assert(!HasThreeSum(a, 22));
}

// ----------------------------------------------------------
// 18.5 FIND THE MAJORITY ELEMENT**
string FindMajorityElement(stringstream* input)
{
    // If count is zero, set count to one and take the new element as the candidate.  If another element of the same type is encountered, increment count, otherwise decrement.
	// Because the majority element has >50% of the elements in the array, it's count is guaranteed to be higher than the count for any other element, and it will overwhelm any other count to be the last element standing.
    string x, candidate;
    int count = 0; // Don't forget to initialize.
    while ( *input >> x )
    {
        if ( count == 0 )
        {
            candidate = x;
            count = 1;
        }
        if ( x == candidate )
            count++;
        else
            count--;
    }
    return candidate;
}

void TestTestFindMajorityElement()
{
	stringstream a;
	a << "4 3 4 3 2 4 2 4 2 4 2 4";
	auto r = FindMajorityElement(&a);
	assert(r == "4");
}

// ----------------------------------------------------------
// 18.6 THE GASUP PROBLEM*
size_t FindAmpleCity(const vector<int>& gallons, const vector<int>& distances)
{
    // Drawing a graph of the consumption along the circle of cities shows that the graph is always the same no matter which city we start for, it is simply shifted horizontally and vertically; hence the minimum city (the one
    // with the largest gas shortfall) is always the same. Hence, to ensure we never run out of gas during the trip, we should always start at the minimum city. It wasn't clear that the minimum city will always offer enough gas
    // to get to the next city - if it didn't, another city would be the minimum. The problem statement guarantees that there is always at least one solution to the problem.
    int gas = 0, minGas = 0;
    size_t best = 0;
    const int mpg = 20;
    for ( int i = 1; i < static_cast<int>(gallons.size()); i++)
    {
        gas += gallons[i - 1] - distances[i - 1] / mpg; // A little iffy on the -1 here.
        if ( gas < minGas )
        {
            minGas = gas;
            best = i;
        }
    }
    return best;
}

void TestFindAmpleCity()
{
	vector<int> gas = {50, 20, 5, 30, 25, 10, 10};
	vector<int> dist = {900, 600, 200, 400, 600, 200, 100};
	auto r = FindAmpleCity(gas, dist);
	assert(r == 3);
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

	// todo I IMPLEMENTED THIS ONE ALL WRONG. IT SHOULD BE REVIEWED.
    stack<int> pillars;
    int best = 0;
    for ( int i = 0; i <= static_cast<int>(heights.size()); i++ )
    {
        if ( !pillars.empty() && i < static_cast<int>(heights.size()) && heights[i] == heights[pillars.top()])
        {
            pillars.pop();
            pillars.emplace(i);
        }
    
        while ( !pillars.empty() && ( i == heights.size() || heights[pillars.top()] > heights[i]) )
        {
            int height = heights[pillars.top()];
            pillars.pop();
            int width = pillars.empty() ? i : i - pillars.top() - 1;
            best = max(best, width * height);
        }
        pillars.emplace(i);
    }
    return best;
}

void TestComputeLargestRectangleUnderSkyline()
{
	vector<int> b = {1, 4, 2, 5, 6, 3, 2, 6, 6, 5, 2, 1, 3};
	auto r = ComputeLargestRectangleUnderSkyline(b);
	assert(r == 20);
}

void TestGreedyAlgorithms()
{
	TestFindMinimumVisits();
	TestHasThreeSum();
	TestTestFindMajorityElement();
	TestFindAmpleCity();
	TestComputeLargestRectangleUnderSkyline();
}