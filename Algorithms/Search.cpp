#include "stdafx.h"
#include "Search.h"
#include <algorithm>

using namespace std;

// ----------------------------------------------------------
// 12.1 SEARCH A SORTED ARRAY FOR FIRST OCCURENCE OF K
int SearchForFirstK(const vector<int>& a, int k)
{
	// Keep a set of candidates solutions, and perform the binary search. Whichever side k is not on, is eliminated from the search. Do not terminate search when any k is found, instead keep searching, rejecting ks on the right
	// if the left also contains ks, and stop when the candidate set is down to one element.
	return 0;
}

// ----------------------------------------------------------
// 12.2 SEARCH A SORTED ARRAY FOR ENTRY EQUAL TO ITS INDEX
int SearchForEntryEqualToIndex(const vector<int>& a)
{
	// Map the array to A[i] - i through the search and search for zero. Since the values are distinct (important), there is only one solution; if A[j] > j, then no entries after j can satisfy the criterion.
	return 0;
}

// ----------------------------------------------------------
// 12.3 SEARCH A CYCLICALLY SORTED ARRAY
int SearchCyclicallySortedArray(const vector<int>& a)
{
	// If A[m] > A[n], then the start of the cycle is somewhere in m <= x <= n, so do a binary search, focusing on the side which satisfies that criterion. Keep going until we are down to a candidate set of one element.
	return 0;
}

// ----------------------------------------------------------
// 12.4 COMPUTE THE INTEGER SQUARE ROOT
int ComputeIntegerSquareRoot(int x)
{
	// Search the space of integers, splitting the range based on y^2, searching left if y^2 > x^2 and right otherwise.
	return 0;
}

// ----------------------------------------------------------
// 12.5 COMPUTE THE REAL SQUARE ROOT*
double ComputeRealSquareRoot(double x)
{
	// Similar to 12.4 above, but pay attention to overflow, especially for where x < 1. If x = 1, then the answer is in [1,x]. If x < 1, then the answer is in [x,1].
	return 0;
}

// ----------------------------------------------------------
// 12.6 SEARCH A 2D SORTED ARRAY*
bool Search2DSortedArray(const vector<vector<int>>&a, int x)
{
	// Note the values are increasing along the top, then right edge of the array, so we can do a binary search along that specific sequence of values and expect a unique result. Remove whichever column or row can't have the
	// value based on the result of his binary search, and keep iterating until the value being searched for is in the top right corner.
	if ( a.size() == 0 || a[0].size() == 0 )
		return false;
	int minRow = 0;
	int maxColumn = a[0].size() - 1;
	while ( minRow < a.size() && maxColumn >= 0)
	{
		if ( a[minRow][maxColumn] == x)
			return true;
		if ( a[minRow][maxColumn] < x)
			minRow++;
		else maxColumn--;
	}
	return false;
}

void TestSearch2DSortedArray()
{
	vector<vector<int>> a = { {-1, 2, 4, 4, 6}, {1, 5, 5, 9, 21}, {3, 6, 6, 9, 22}, {3, 6, 8, 10, 24}, {6, 8, 9, 12, 25}, {8, 10, 12, 13, 40} };
	auto r = Search2DSortedArray(a, 10);
	assert(r);
	auto r2 = Search2DSortedArray(a, 7);
	assert(!r2);
}

// ----------------------------------------------------------
// 12.7 FIND THE MIN AND MAX SIMULTANEOUSLY**
struct MinMax
{
	int min;
	int max;
};

MinMax FindMinMax(vector<int>& a)
{
	// Use a strategy based on "teams". Compare pairs of values to place values into a "winning" and "losing" tier; the max has to be in the winning tier, and the min has to be in the losing tier. Then do a brute force
	// comparison among each tier to find the actual min and max. We end up with 3n/2-2 comparisons.
	if ( a.size() <= 1)
		return {a.front(), a.front()};

	MinMax minMax = {min(a[0], a[1]), max(a[0], a[1])};  
	for ( int i = 2; i + 1 < a.size(); i += 2)
		minMax = {min(minMax.min, min(a[i], a[i+ 1])), max(minMax.max, max(a[i], a[i + 1]))};
	if ( a.size() % 2 == 1 )
		minMax = {min(minMax.min, a.back()), max(minMax.max, a.back())};
	return minMax;
}


void TestFindMinMax()
{
	vector<int> v = { 4, 6, 7, 8, 100, 30, 48, 0, 20 };
	auto r = FindMinMax(v);
	assert(r.min == 0);
	assert(r.max == 100);
}

// ----------------------------------------------------------
// 12.8 FIND THE KTH LARGEST ELEMENT**
int FindKthLargestElement(vector<int>& a, int k)
{
	// Pick a random pivot and categorize values with respect to the pivot, as in quicksort. This gives us the k-order p of the random pivot. If k > p, eliminate candidates on the right, otherwise eliminate candidates on the left.
	// Keep going until we find pivot p=k. We are effectively sampling the solution space, and most importantly, rejecting half the candidates for each sample, on average.
	int s = 0, f = a.size() - 1;
	default_random_engine rnd;
	while ( s <= f )
	{
		int p = uniform_int_distribution<int>{s, f}(rnd);
		
		swap( a[p], a[f] );
		int j = s;
		for ( int i = s; i < f; i++ )
		{
			if (a[i] > a[f]) // Largest means we have to order the larger elements first.
				swap(a[i], a[j++]);
		}
		swap(a[f], a[j]);
		
		if ( j < k - 1 ) // Note that k starts at 1.
			s = j + 1;
		else if ( j > k - 1 )
			f = j - 1;
		else return a[j];
	}
	return -1;
}

void TestFindKthLargestElement()
{
	vector<int> a = {3, 2, 1, 5, 4};
	auto r = FindKthLargestElement(a, 5);
	assert(r == 1);
}

// ----------------------------------------------------------
// 12.9 FIND THE MISSING IP ADDRESS
int FindMissingAddress(ifstream* ifs)
{
	// Read the file and mask the 16 least significant bits, and count how many entries are found with that mask. One of these will be less than 2<16. Zero in on it and do another pass over the 2^16 entries that have the
	// 16 most significant bits matching the pattern isolated in the first step.
	return 0;
}

// ----------------------------------------------------------
// 12.10 FIND THE DUPLICATE AND MISSING ELEMENTS***
struct DuplicateAndMissing
{
	int duplicate;
	int missing;
};

DuplicateAndMissing FindDuplicateAndMissing(const vector<int>& a)
{
	// This relies heavily on XOR cancellation. The sequence has an extra m, and a missing t. XORing the array with the sequence 0+1+...+n - 1 will leave out m XOR t, so we still don't know the solution. m XOR t does tell us
	// by which bits m and t differ however (m and t are guaranteed to differ by the problem statement), which gives us a way to focus on the elements which can only have m or t, but not both. If m and t differ in the kth bit,
	// XOR all numbers in the sequencer 0+1+...+n-1 that have bit k set, with all numbers in the array that have that bit set, yields a XOR that can be m or t but not both. To find out if we have m or t, see if the given XOR
	// is missing from the subsequence, then it is m otherwise it is t. XORing this result with the (m XOR t) result given before, will yield the other value.
	
	int xor = 0;
	for ( int i = 1; i < a.size(); i++)
		xor ^= i ^ a[i];
	// Now xor is m xor t.
	int bit = xor & (~(xor-1)); // Lowest bit set. Review this....

	int xor2 = 0;
	for ( int i = 1; i < a.size(); i++)
	{
		if ( i & bit )
			xor2 ^= i;
		if ( a[i] & bit )
			xor2 ^= a[i];
	}
	
	DuplicateAndMissing dm {-1, -1};
	for ( int v : a )
	{
		if ( v == xor2 )
			return DuplicateAndMissing { xor2, xor2 ^ xor };
	}
	return DuplicateAndMissing{xor2 ^ xor, xor};
}

void TestFindDuplicateAndMissing()
{
	vector<int> a = { 0, 1, 2, 3, 5, 9, 6, 7, 8, 9, 10 };
	auto r = FindDuplicateAndMissing(a);
	assert(r.missing == 4);
	assert(r.duplicate == 9);
}

void TestSearching()
{
	TestSearch2DSortedArray();
	TestFindMinMax();
	TestFindKthLargestElement();
	TestFindDuplicateAndMissing();
}