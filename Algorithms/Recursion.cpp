#include "stdafx.h"
#include "Recursion.h"
#include "BinaryTrees.h"

using namespace std;

// ----------------------------------------------------------
// 16.1 THE TOWERS OF HANOI PROBLEM**
void ComputeTowerOfHanoi(int rings)
{
	// The recursive procedure is as follows: move n - 1 discs from FROM to TO through USE, then move the nth disc from FROM to TO, then move n-1 discs back from USE to TO through FROM. Perform recursively.
}

// ----------------------------------------------------------
// 16.2 GENERATE ALL NONATTACKING PLACEMENTS OF N-QUEENS*
vector<vector<int>> GenerateNonAttackingPlacementNQueends(int n)
{
	// Solve for each additional queen recursively, testing each starting position, considering one queen per row. The test for an invalid queen can be made in a succinct manner by testing if i - p[j] == row - j (diagonal) or 
	// zero (column), where p is the column on which each queen is placed for each row.
	return vector<vector<int>>();
}

// ----------------------------------------------------------
// 16.3 GENERATE PERMUTATIONS
vector<vector<int>> GeneratePermutations(vector<int>& a)
{
	// Perform a recursion on the array. Swap the chosen element with the end of the array and perform the next recursion on a[0.. n-1].
	return vector<vector<int>>();
}

// ----------------------------------------------------------
// 16.4 GENERATE THE POWER SET
vector<vector<int>> GeneratePowerSet(const vector<int>& input)
{
	// Enumerating all sets is equivalent to enumerating all bit combinations of a set of bits 2^n. x & (x - 1) will isolate the lowest bit, and log2(y) will give the index of a bit. Another possibility is to recurse on each
	// bit, testing with the bit 0, then bit 1.
	return vector<vector<int>>();
}

// ----------------------------------------------------------
// 16.5 GENERATE ALL SUBSETS OF SIZE K
vector<vector<int>> GenerateAllSubsetsSizeK(int n, int k)
{
	// Recurse over all possible entries for a slot 0, then recurse to slot 1, and so forth to slot n. Iterate from [0..n] for the top call, then [i+1..n] and so forth for the other recursive calls.
	return vector<vector<int>>();
}

// ----------------------------------------------------------
// 16.6 GENERATE STRINGS OF MATCHED PARENS*
vector<string> GenerateStringsMatchedParens(int k)
{
	// Track that we need ko ( and kc ). if ko > 0, search recursively with ( suffix. If ko < kc, search with ) suffix. This consume the parens according to the specified rule set.
	return vector<string>();
}

// ----------------------------------------------------------
// 16.7 GENERATE PALINDROMIC DECOMPOSITIONS*
vector<vector<string>> GeneratePalindromicDecompositions(const string& s)
{
	// Recursively test with palindrom of length n, consuming the string as you advance.
	return vector<vector<string>>();
}

// ----------------------------------------------------------
// 16.8 GENERATE BINARY TREES*
vector<TreeNodePtr> GenerateBinaryTrees(int n)
{
	// View the numbers in an array as a representation of a binary tree. Then split the array recursively according to all the possible subdivisions at each node: 1 element on left, 2 element on left, etc.
	return vector<TreeNodePtr>();
}

// ----------------------------------------------------------
// 16.9 IMPLEMENT A SUDOKU SOLVER
bool SolveSudoky(vector<vector<int>> sudoku)
{
	// Keep track of the numbers that could potentially be added to a column, row, block. Try all possibilities, using recursion. When adding a number we are only checking the new number to see if the sudoku is still valid.
	return false;
}

// ----------------------------------------------------------
// 16.10 COMPUTE A GRAY CODE
vector<int> ComputeGrayCode(int n)
{
	// One approach is to pick a value fro the set, then another value that obeys the gray code rule. Proceed recursively until you find the complete gray code. A more analytical approach is to build the sequence of length n+1
	// from the sequence of length n. Appending the two sequences n and n + 1 breaks the gray code rules at their joined point and the end of the combined sequence. Reversing the second sequence works however, since the last
	// entry from sequence n and the first entry from sequence n + 1 are the same apart from the additional 1 pre-pended to the first element of sequence n + 1. The last element of sequence n + 1 also matches the first element
	// of sequence n, with only one extra bit changed. This completes the sequence.
	return vector<int>();
}

// ----------------------------------------------------------
// 16.11 COMPUTE THE DIAMETER OF A TREE**
template<class T>
struct TreeNodeWithEdge : TreeNode<T>
{
	struct Edge
	{
		shared_ptr<TreeNodeWithEdge> root;
		double length;
	};

	vector<Edge> edges;
};

double ComputeDiameter(shared_ptr<TreeNodeWithEdge<int>> tree)
{
	// Note that this is a tree, not a BINARY tree. Going up the tree, the diameter is the max of the two values: the greatest diameter between all its children (path doesn't cross the node), and the sum of the two longest 
	// paths at that node (the path crosses the node, so the two longest paths should be on different children of the crossed node). 
	return 0;
}