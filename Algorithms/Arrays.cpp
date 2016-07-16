#include "stdafx.h"
#include "Arrays.h"
#include <deque>
#include <iostream>
#include <sstream>

using namespace std;

// ----------------------------------------------------------
// 6.1 THE DUTCH NATIONAL FLAG PROBLEM
// Write a program that takes an array A and an index i into A, and rearranges the elements such that all elements less than A[i], the pivot, appear first, followed by elements equal to the pivot, followed by elements
// greater than the pivot.
void DutchFlagProblem(vector<int>& a, int i)
{
	// This is the quicksort partitioning step.
	// Enforce loop invariant where array is separated into bottom, middle, unclassified and top parts at the start of each loop. Keep tracking indices to each of the sections in the array and update where they begin
	// as you go along.
}

// ----------------------------------------------------------
// 6.2 INCREMENT AN ARBITRARY PRECISION INTEGER
void IncrementArbitraryPrecisionInteger(vector<int>& in)
{
	int i;
	for (i = static_cast<int>(in.size()) - 1; i >= 0; i--)
	{
		if (in[i] == 9)
			in[i] = 0;
		else
		{
			in[i]++;
			break;
		}
	}
	if (i == -1)
		in.insert(in.begin(), 1);
}

void TestIncrementArray()
{
	vector<int> in = {1, 0, 0};
	vector<int> out = {1, 0, 1};
	IncrementArbitraryPrecisionInteger(in);
	assert(in == out);
	vector<int> in2 = {9, 9, 9};
	vector<int> out2 = {1, 0, 0, 0};
	IncrementArbitraryPrecisionInteger(in2);
	assert(in2 == out2);
	vector<int> in3 = {1, 2, 9};
	vector<int> out3 = {1, 3, 0};
	IncrementArbitraryPrecisionInteger(in3);
	assert(in3 == out3);
}

// ----------------------------------------------------------
// 6.3 MULTIPLY TWO ARBITRARY PRECISION INTEGERS
void MultiplyArbitraryPrecisionIntegers(const vector<int>& a, const vector<int>& b)
{
	// Use arrays to simulate the grade school multiplication algorithm.
}

// ----------------------------------------------------------
// 6.4 ADVANCING THROUGH AN ARRAY
bool AdvanceThroughAnArray(const vector<int> a)
{
	// Loop through each location, and keep a count of the farthest reachable location. If we arrive at a point in the loop where the farthest reachable location is further than the loop index, then we cannot advance through the
	// array.
	return false;
}

// ----------------------------------------------------------
// 6.5 DELETE DUPLICATES THROUGH AN ARRAY
void DeleteDuplicates(vector<int>& a)
{
	// Loop through each element. If it's the same as the last element, skip it, otherwise copy it to the current insertion position. The size of the new array is the last insertion point.
}

// ----------------------------------------------------------
// 6.6 BUY AND SELL A STOCK ONCE*
int BuyAndSellStockOnce(vector<int> prices)
{
	auto minPrice = numeric_limits<int>::max();
	auto result = 0;
	for (auto i = 0u; i < prices.size(); i++)
	{
		auto dif = prices[i] - minPrice;
		if (dif > result)
			result = dif;
		if (prices[i] < minPrice)
			minPrice = prices[i];
	}
	return result;
}

void TestBuyAndSellStockOnce()
{
	vector<int> prices = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
	auto result = BuyAndSellStockOnce(prices);
	assert(result == 30);
}

// ----------------------------------------------------------
// 6.7 BUY AND SELL A STOCK TWICE
int BuyAndSellStockTwice(vector<int> prices)
{
	// Record the most profit that can be made if we sell on day i into an array F. 
	// Then record the most profit that can made if we buy on day i into an array B.
	// Then the max profit for each day is F[i - 1] + B[i] where F[-1] = 0
	return 0;
}

// ----------------------------------------------------------
// 6.8 ENUMERATE ALL PRIMES TO N**
vector<int> GeneratePrimes(int n)
{
	// Create a boolean array to keep track of multiples of primes. All numbers are first tagged as primes, then as we enumerate through n, all multiples of i are tagged as non-primes.
	// Optimization: don't store even numbers, and treat them as a special case.
	// Optimization: start the sieving from p squared instead of p, since all numbers of the form kp where k < p have already been sieved out.
	// Time complexity is difficult for this problem.
	deque<bool> isPrime(n + 1, true); // Make sure to allocate space for n + 1. Prefer a deque because of the potentially large size of n.
	vector<int> result;
	result.emplace_back(2);
	for (auto i = 3; i <= n; i += 2) // Start at 2, 1 will just mark everything as a non-prime... tricky.
	{
		if (isPrime[i])
		{
			result.emplace_back(i); // Use emplace back whenever possible.
			// This loop should only run if we have a prime.
			// Sieve. Compute j * i. Start i square because all prior values have already been computed.
			for (auto j = static_cast<int64_t>(i) * static_cast<int64_t>(i); j <= n; j += i) // Wrong, need to increase j + i. Whoops.
				isPrime[static_cast<unsigned int>(j)] = false;
		}
	}
	return result;
}

void TestGeneratePrimes()
{
	auto result = GeneratePrimes(50);
	vector<int> ref{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	assert(result == ref);
}

// ----------------------------------------------------------
// 6.9 PERMUTE THE ELEMENTS OF AN ARRAY**
void PermuteArray(vector<int>& a, vector<int> p)
{
	// It's crucial to understand that p contains the DESTINATION for the corresponding slot, not the SOURCE as I originally believed. I spent more than an hour trying to figure out why I didn't understand the algorithm.
	// In essence, go through each slot, and perform the move for that slot by swapping with the destination. This leaves you with the destination slot correctly updated, and the a new value where the destination value used to be.
	// Looking up the permutation array that was under the destination slot, we can now figure out where the value that used to be there, now needs to be. This creates a cycle where each value is moved to its destination.
	// To ensure we don't keep performing permutations, we need to indicate which slots we've already moved to their destination so we don't move them again; one possible tactic is to make the permutation number negative.
	// Note that some cycles may be disjoint, ie entries 0 and 1 refer to each other and entires 1 and refer to each other. This is why we may need to apply multiple cycles as we go through the array from left to right.
	// If we need to avoid using storage entirely, we could run through the cycle once and only run it if the starting element is the leftmost one in the cycle; or the rightmost - all we need is one element to act as the gate
	// for running through a cycle.
	for (auto i = 0; i < static_cast<int>(p.size()); i++)
	{
		auto j = i;
		while (p[j] >= 0)
		{
			// p[i] says the the value at j needs to go to p[j].
			swap(a[i], a[p[j]]);
			auto temp = p[j];
			p[j] = p[j] - p.size();
			j = temp;
		}
	}
}

void TestPermuteArray()
{
	vector<int> a{0, 1, 2, 3};
	vector<int> p{2, 0, 1, 3};
	PermuteArray(a, p);
	vector<int> ref{1, 2, 0, 3};
	assert(a == ref);
}

// ----------------------------------------------------------
// 6.10 COMPUTE THE NEXT PERMUTATION**
vector<int> NextPermutation(vector<int> p)
{
	// Any permutation in strict decreasing order is last in the dictionary order, and cannot be increased. Thus any suffix from a permutation, also cannot be increased, and we cannot find the next permutation by doing
	// a swap within this suffix.
	// The next entry e to the left of the suffix is thus the entry that can be changed, and should be changed as to increase by as little as possible. This means swapping e with the smallest entry in the suffix that is greater
	// than e.
	// This guarantees that the prefix is now increased by as little as possible. The suffix is still in an arbitrary order, and we need to sort the suffix by decreasing order to make it as small as possible. SInce the 
	// suffix was originally in decreasing order, we can reverse it to put in increasing order without using a sorting algorithm.
	// To recap, this whole process effectively finds the rightmost entry that needs to be "incremented", then performs this "increment" by swapping the smallest entry to its right, and then setting all remaining values to the
	// right to the smallest possible suffix. This is similar to counting, where incrementing one of the digits on the left will reset all the digits on the right to zero.
	int i = p.size() - 2;
	// Find longest decreasing sequence.
	while (i >= 0 && p[i] > p[i + 1])
		i--;
	if (i < 0)
		return vector<int>();
	// Find smallest element greater than e.
	auto j = i + 1;
	while (j < static_cast<int>(p.size()) && p[j] > p[i])
		j++;
	auto result = p;
	swap(result[i], result[j - 1]);
	reverse(result.begin() + i + 1, result.end()); // Sort by reversing. tricky.
	return result;
}

void TestNextPermutation()
{
	vector<int> p{1, 0, 3, 2};
	auto result = NextPermutation(p);
	vector<int> ref{1, 2, 0, 3};
	assert(result == ref);
	vector<int> p2{3, 2, 1, 0};
	result = NextPermutation(p2);
	assert(result == vector<int>());
}

// ----------------------------------------------------------
// 6.11 SAMPLE OFFLINE DATA
void SampleOfflineData(vector<int>& values, int k)
{
	default_random_engine seed;
	for (auto i = 0; i < k; i++)
		swap(values[i], values[uniform_int_distribution<int>{i, static_cast<int>(values.size()) - 1}(seed)]);
}

void TestSampleOnlineData()
{
	vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> values2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	SampleOfflineData(values, 5);
	assert(values != values2);
}

// ----------------------------------------------------------
// 6.12 SAMPLE ONLINE DATA**
vector<int> SampleOnlineData(istringstream& values, int k)
{
	// The idea here is to keep the k first packets. Then for every packet > k, use a random number generator to keep a packet following odds of k/n. If we keep the packet, keep it, replacing a random packet from the existing
	// results.
	// The books mentions there is an inductive proof as to why this works, but doesn't go into any details. Specifically, the induction hypothesis is that all k-sized subsets are equally likely after n >= k packets have been read.
	vector<int> result;
	int x;
	for (int i = 0; i < k && (values >> x); i++)
		result.emplace_back(x);

	default_random_engine seed((random_device())());
	int n = k;
	while (values >> x)
	{
		// Probability of k / n.
		int index = uniform_int_distribution<int>{0, n}(seed);
		if (index < k)
			result[index] = x;
		n++;
	}
	return result;
}

// ----------------------------------------------------------
// 6.13 COMPUTE A RANDOM PERMUTATION**
vector<int> ComputeRandomPermutation()
{
	// Initialize an array with a default increasing sequence of n permutation values, than use solution 6.11 to sample from it, return a subsample of size n.
	// This seems incorrectly specified however. The problem specifically states we are given a random number generator that returns integers in the set [0,1,...,n-1]. Solution 6.11 uses a random number generator that returns
	// numbers in the range [0..n-i], where i is the loop index.
	return vector<int>();
}

// ----------------------------------------------------------
// 6.14 COMPUTE A RANDOM SUBSET*
vector<int> ComputeRandomSubset(int n)
{
	// Again, use solution 6.11. Recall that solution 6.11 swaps elements in the set so that the chosen elements are at the start of the array. Thus, we can use a hash table to keep track of which elements are traded
	// places. If the element is not in the hash table than s[i] = i, otherwise it is the value in the hash table. The hash table is a changeset over the original array.
	return vector<int>();
}

// ----------------------------------------------------------
// 6.15 GENERATE NONUNIFORM RANDOM NUMBERS
vector<int> GenerateNonUniformRandomNumbers(vector<int> values, vector<double> probabilities)
{
	// I've done this before. Sum up the probabilities going from the lowest to the highest number, creating probabilistic intervals. Then do a search of the array to find the random value assigned within an interval.
	// Since the intervals are sorted, we can use a binary search and proceed from the middle of the array.
	return vector<int>();
}

// ----------------------------------------------------------
// 6.16 THE SUDOKU CHECKER PROBLEM
bool SudokuCheckerProblem(vector<vector<int>> a)
{
	vector<int> subgridMask = {0, 0, 0,};
	vector<int> columnMask = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (auto y = 0; y < 9; y++)
	{
		auto rowMask = 0;
		if (y % 3 == 0)
			subgridMask = {0, 0, 0};
		for (auto x = 0; x < 9; x++)
		{
			auto valueFlag = 1 << a[y][x];
			if ((rowMask & valueFlag) != 0 || (columnMask[x] & valueFlag) != 0 || (subgridMask[x / 3] & valueFlag) != 0)
				return false;
			rowMask |= valueFlag;
			columnMask[x] |= valueFlag;
			subgridMask[x / 3] |= valueFlag;
		}
	}
	return true;
}

void TestSudokuCheckerProblem()
{
	vector<vector<int>> a = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, {6, 7, 2, 1, 9, 5, 3, 4, 8}, {1, 9, 8, 3, 4, 2, 5, 6, 7}, {8, 5, 9, 7, 6, 1, 4, 2, 3}, {4, 2, 6, 8, 5, 3, 7, 9, 1}, {7, 1, 3, 9, 2, 4, 8, 5, 6}, {9, 6, 1, 5, 3, 7, 2, 8, 4}, {2, 8, 7, 4, 1, 9, 6, 3, 5}, {3, 4, 5, 2, 8, 6, 1, 7, 9}};
	assert(SudokuCheckerProblem(a));
	//vector<vector<int>> b = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, {6, 7, 2, 1, 9, 5, 3, 4, 8}, {1, 9, 8, 3, 8, 2, 5, 6, 7}, {8, 5, 9, 7, 6, 1, 4, 2, 3}, {4, 2, 6, 8, 5, 3, 7, 9, 1}, {7, 1, 3, 9, 2, 4, 8, 5, 6}, {9, 6, 1, 5, 3, 7, 2, 8, 4}, {2, 8, 7, 4, 1, 9, 6, 3, 5}, {3, 4, 5, 2, 8, 6, 1, 7, 9}};
	//assert(SudokuCheckerProblem(b));
}

// ----------------------------------------------------------
// 6.17 COMPUTE THE SPIRAL ORDERING OF A 2D ARRAY
vector<int> ComputeSpiralOrder(vector<vector<int>> a)
{
	vector<int> result;
	vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	auto x = 0, y = 0, curDir = 0;
	for (auto i = 0u; i < a.size() * a.size(); i++)
	{
		result.push_back(a[y][x]);
		a[y][x] = 0; // Um, this is cheating.
		auto nextX = x + directions[curDir][0];
		auto nextY = y + directions[curDir][1];
		if (nextX < 0 || nextX >= static_cast<int>(a.size()) || nextY < 0 || nextY >= int(a.size()) || a[nextY][nextX] == 0)
		{
			curDir = (curDir + 1) % 4;
			nextX = x + directions[curDir][0];
			nextY = y + directions[curDir][1];
		}
		x = nextX;
		y = nextY;
	}
	return result;
}

void TestSpiralOrder()
{
	vector<vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	vector<int> out = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
	auto result = ComputeSpiralOrder(a);
	assert(result == out);
	vector<vector<int>> a2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<int> out2 = {1, 2, 3, 6, 9, 8, 7, 4, 5};
	auto result2 = ComputeSpiralOrder(a2);
	assert(result2 == out2);
}

// ----------------------------------------------------------
// 6.18 ROTATE A 2D ARRAY*
void RotateMatrix(vector<vector<int>>& m)
{
	// Notice we do not want to use additional storage. We can start from a corner, move it to the next corner, take the value that used to be at that corner and move that, and so forth, applying this operation four times.
	// Since there are always four operations for this, we can use an unrolled loop for this step.
	// We can similarly process the cell to the right of the corner in a loop, and cells on inner layer of the array in another loop, to process the entire matrix.
	// Another contrived hack would be to rotate the values on read. The problem specifically states we should rotate the array however, so this is more trivia than an actual solution.
}

// ----------------------------------------------------------
// 6.19 COMPUTE ROWS IN PASCAL'S TRIANGLE*
vector<vector<int>> ComputePascalTriangleRows(int n)
{
	// The hint threw me off, and I was looking for a more complicated answer than what I needed. The answer is simply to rotate the triangle by 45 degrees. Then it neatly maps to an array, and the sum of one cell in the triangle
	// is the of the value to the left and above it.
	return vector<vector<int>>();
}

// ----------------------------------------------------------
void TestArrays()
{
	TestSpiralOrder();
	TestSudokuCheckerProblem();
	TestSampleOnlineData();
	TestIncrementArray();
	TestBuyAndSellStockOnce();
	TestGeneratePrimes();
	TestPermuteArray();
	TestNextPermutation();
}
