#include "stdafx.h"
#include "DynamicProgramming.h"
#include <unordered_set>
#include <algorithm>
#include <unordered_set>
#include <tuple>

using namespace std;

// ----------------------------------------------------------
// 17.1 COUNT THE NUMBER OF SCORE COMBINATIONS*
int CountNumberOfScoreCombinations(int target, const vector<int> plays)
{
	// Let i be the maximum play index allowed and j be the target score. The key is to understand how adding the ith play affects the combinations without the new play. If we
	// consider the set that considers the new play i, we can split it into the set that includes the new play, and the set that doesn't. For the set that include the new play, 
	// it will consists of that play, and the remainder of the space left to attain the target score must be filled with combinations of other plays, potentially including play i.
	// This maps to A[i][j - p[i]]. 
	//
	// The set that does not include new the play i for the score j is simply A[i-1][j]. The union of both these sets gives us the total combination count for a given target score
	// and set of plays up to i, eg. A[i][j] = A[i-1][j] + A[i][j - p[i]]. 
	//
	// Thus loop, over plays over i and score ranges over j, and add these two combinations, caching the results for lower elements in the cache array. 
	
	// Note how are building a table that looks up its other rows and columns.
	vector<vector<int>> combinationCounts(plays.size(), vector<int>(target + 1, 0)); // Note how the 2d array is defined.
	for ( int i = 0; i < plays.size(); i++)
	{
		combinationCounts[i][0] = 1; // There is only one way to reach 0. Base cases are initialized separately.
		for (  int j = 1; j <= target; j++ ) // Skip zero, there are no additional ways to reach zero.
		{
			int without = i > 0 ? combinationCounts[i - 1][j] : 0;
			int with = j >= plays[i] ? combinationCounts[i][j - plays[i]] : 0; // If target less than play, than we can't use the play. Otherwise fill comb count with previously computed value.
			combinationCounts[i][j] = with + without;
		}
	} 
	return combinationCounts.back().back(); // Note the use of double backs.
}

void TestCountNumberOfScoreCombinations()
{
	auto r = CountNumberOfScoreCombinations(12, vector<int>({ 2, 3, 7 }));
	assert(r == 4);
}

// ----------------------------------------------------------
// 17. COMPUTE THE LEVENSTEIN DISTANCE**
int ComputeLevensteinDistance(const string& a, const string& b)
{
	// Let E be the Levenstein distance for words A and B with length a and b. If the last character of both strings is the same, then E(A,B)=E(A[0:a-2], B[0:b-2]). In other words,
	// the last character is ignored and we are computing the Levenstein distance between the two words without the shared character. If the last characters aren't identical, then
	// we will need to do an edit, valued at one point; we just need to find which edit will work best. E(A,B) will then be 1, plus the best (minimal) Levenstein distance from
	// one of three possible operations:
	// Substitution: E(A[0:a-2],B[0:b-2]), we are changing a matching character, so we just remove it from the end of both strings
	// Insertion: E(A[0:a-1], B[0:b-2]), we are inserting a matching character , so we have on less character to match on B but A remain the same.
	// Deletion: E(A[0:a-2], B[0:b-1]), we are deleting a character, so we have one less character on A, but B remains the same (aka still needs to be matched).
	// Caching the results for each a and b will ensure this gets computed in a time of O(ab).
	vector<vector<int>> best(a.size() + 1, vector<int>(b.size() + 1, 0));
	for ( int j = 0; j <= b.size(); j++ ) // Base cases are initialized separately.
		best[0][j] = j;
	for ( int i = 1; i <= a.size(); i++ )
	{
		best[i][0] = i; // Base cases are initialized separately.
		for ( int j = 1; j<= b.size(); j++ )
		{
			if ( a[i - 1] != b[j - 1] )
				best[i][j] = 1 + min({best[i - 1][j - 1], best[i][j-1], best[i - 1][j]}); // Note how we can take the min of a sequence.
			else
				best[i][j] = best[i - 1][j - 1];
		}
	} 
	return best.back().back();
}

void TestComputeLevensteinDistance()
{
	auto r = ComputeLevensteinDistance("carthorse", "orchestra");
	assert(r == 8);
	auto r2 = ComputeLevensteinDistance("Saturday", "Sundays");
	assert(r2 == 4);
}

// ----------------------------------------------------------
// 17.3 COUNT THE NUMBER OF WAYS TO TRAVER A 2D ARRAY
int NumberOfWaysToTraverse2DArray( int n, int m)
{
	// If iterating over rows and columns, the possible paths are 1 for the top row and left column, and  for every other cell, the sum of the paths computed for the cell on the left
	// and the cell above.
	return 0;
}

// ----------------------------------------------------------
// 17.4 COMPUTE THE BINOMIAL COEFFICIENTS**
int ComputeBinomialCoefficients(vector<vector<int>>& sets, int i, int j)
{
   if (sets[i][j] != 0 )
	   return sets[i][j];
   if ( j == 0 || i == j )
	   sets[i][j] =1;
   else sets[i][j] = ComputeBinomialCoefficients(sets, i - 1, j - 1) + ComputeBinomialCoefficients(sets, i - 1, j);
   return sets[i][j];
}

int ComputeBinomialCoefficients(int n, int k)
{
	// For a coefficient with n and k, when iterating over n, we can decompose it into the sets without the latest n in it, and the set with. The subset without n is (n - 1, k).
	// For the sets with n, they need to include n, which will occupy one slot in the subset of size k, which means the remaining combinations that include n are (n - 1, k - 1).
	// Hence, (n, k) = (n - 1, k) + (n - 1, k - 1). The base cases are (r, r) = 1 and (r, 0) = 1 and we are guaranteed to hit either of these cases.
	// This is fairly similar to 7.1
	vector<vector<int>> sets(n + 1, vector<int>(k + 1, 0 ));
	return ComputeBinomialCoefficients(sets, n, k);
}

void TestComputeBinomalCoefficients()
{
	auto r = ComputeBinomialCoefficients(7, 3);
	assert(r == 35);
}

// ----------------------------------------------------------
// 17.5 SEARCH FOR A SEQUENCE IN A 2D ARRAY*
struct HashTuple
{
	size_t operator()(const tuple<int, int, int>& t) const
	{
		return hash<int>()(get<0>(t) ^ get<1>(t) ^ 1021 ^ get<2>(t) * 1048573); // What... the... FUUUCK??? Ugggh... Make note of this... somehow.
	}
};

bool TestPattern(unordered_set<tuple<int, int, int>, HashTuple>& failedPrev, const vector<vector<int>>& grid, const vector<int>& pattern, int x, int y, int patternOffset)
{
	if ( patternOffset == pattern.size() )
		return true;
	if ( x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || failedPrev.find({x, y, patternOffset}) != failedPrev.cend()) // Notice how we look up in the set.
		return false;
	if ( grid[x][y] == pattern[patternOffset] )
	{
		if (TestPattern(failedPrev, grid, pattern, x - 1, y, patternOffset + 1))
			return true;
		if (TestPattern(failedPrev, grid, pattern, x + 1, y, patternOffset + 1))
			return true;
		if (TestPattern(failedPrev, grid, pattern, x, y - 1, patternOffset + 1))
			return true;
		if (TestPattern(failedPrev, grid, pattern, x, y + 1, patternOffset + 1))
			return true;
	}
	failedPrev.emplace(x, y, patternOffset); // Note that we don't use emplace_back, and we don't use {}.
	return false;
}

bool IsPatternContainedInGrid(const vector<vector<int>>& grid, const vector<int>& pattern)
{
	// Search over each grid square, matching the pattern as we go. The one twist is that if we've already searched a specific s, y and pattern offset, we can use a cached result
	// and not compute that again.
	unordered_set<tuple<int, int, int>, HashTuple> failedPrev;    // Note the use of an unordered set with a tuple.
	for ( int i = 0; i < grid.size(); i++ )
		for ( int j = 0; j < grid[i].size(); j++ )
			if ( TestPattern(failedPrev, grid, pattern, i, j, 0) )
				return true;
	return false;
}

void TestIsPatternContainedInGrid()
{
	vector<vector<int>> grid = {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
	vector<int> pattern = { 1, 3, 4, 6 };
	vector<int> pattern2 = { 1, 2, 3, 4 };
	auto r = IsPatternContainedInGrid(grid, pattern);
	assert(r);
	auto r2 = IsPatternContainedInGrid(grid, pattern2);
	assert(!r2);
}

// ----------------------------------------------------------
// 17.6 THE KNAPSACK PROBLEM*
struct Item
{
	int weight, value;
};

int FindOptimumSubjectToCapacity(const vector<Item>& items, int capacity)
{
	// Again, split the set with the ith clock, and without the ith clock. Let be an array V[i,w] representing the total value, i being the number of number clocks allowed and
	// w a specific capacity. If we are not adding the ith clock, then we have V[i-1][w] for current i and w. If we are adding the ith clock, assuming we have enough space
	// for the clock, that is w >= w'[i], then we have V[i-1][w-w'[i]]+v[i]. That is, the value of the new clock, plus the optimum result for the remaining space in the sack.
	return 0;
}

// ----------------------------------------------------------
// 17.7 THE BEDBATHANDBEYONDPROBLEM.COM
vector<string> DecomposeIntoDictionaryWords(const string& s, const unordered_set<string> dict)
{
	// Search for valid prefixes of the string. A prefix is valid if it's a dictionary word or its a word + a valid prefix. Cache whether each prefix was valid or not. Keep length
	// of last dictionary word to know where it started.
	return vector<string>();
}

// ----------------------------------------------------------
// 17.8 FIND THE MINIMUM WEIGHT PATH IN A TRIANGLE
int FindMinimumWeightPathInTriangle(const vector<vector<int>>& triangle)
{
	// Start from bottom. Min weight path at a cell is min of either path both the cell + the value of the cell. Keep going until you reach the top of the triangle.
	return 0;
}

// ----------------------------------------------------------
// 17.9 PICK UP COINS FOR MAXIMUM GAIN*
int MaximumRevenue(const vector<int>& coins)
{
	// Let R(a,b) be the maximum revenue with starting coin a and ending coin b. Both players play the best possible move they can. Player A can remove coins from either end,
	// and player B can remove coins from either end, which gives us 4 possibilities. Since total revenue is constant, if player B minimizes A's revenue, it's the same as maxxing
	// his own revenue. Let C be the coin values. R(a, b) would be
	// the max of either:
	// C[a] + min(R(a + 2, b), R(a + 1, b - 1)) // We gain the value of coin A and add the minimum value gained from whether player B takes coin a + 1, or b.
	// C[b] + min(R(a + 1, b - 1), R(a, b - 2)) // We gain the value of coin B and add the minimum value gained from whether player B takes coin a, or b - 1.
	// This formulation is the simplest calculation. We can then implement R, caching the values for combinations of a and b.s
	return 0;
}

// ----------------------------------------------------------
// 17.10 COUNT THE NUMBER OF MOVES TO CLIMB STAIRS
int COuntNumberOfWaysToClimbStairs(int top, int k)
{
	// For every k, we have F(n, k) = sum over 1..k of F(n - i, k). In other words, if we take i steps, the ways that we can finish the climb map to F(n - i, k). The base cases give 1. 
	return 0;
}

// ----------------------------------------------------------
// 17.11 THE PRETTY PRINTING PROBLEM**
int ComputeMinimumMessiness(const vector<string>& words, int lineLength)
{
	// M(i) = min of j over 0..i, inclusive, of f(j, i) + M(j - 1) where f(j, i) is the messiness of a single line. In other words, each line builds from a hypothetical optimal
	// prefix and adds a new value for the line. Iterate over i.
	//
	// Hypothesis, if we are in an optimal placement for i, and the last line goes from j to i, then M(j - 1) must be optimal.
	// I actually don't understand why that would be true.
	return 0;
}

// ----------------------------------------------------------
// 17.12 FIND THE LONGUEST NON-DECREASING SEQUENCE
int FindLonguestNonDecreasingSequence(const vector<int>& a)
{
	// Cache the length found at each entry. L[i] = max(L[j=0..i] for all entries where A[j] < A[i].
	return 0;
}

void TestDynamicProgramming()
{
	TestCountNumberOfScoreCombinations();
	TestComputeLevensteinDistance();
	TestComputeBinomalCoefficients();
	TestIsPatternContainedInGrid();
}