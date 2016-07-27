#include "stdafx.h"
#include "Recursion.h"
#include "BinaryTrees.h"
#include <array>
#include <stack>

using namespace std;

// ----------------------------------------------------------
// 16.1 THE TOWERS OF HANOI PROBLEM**
void MoveRings(array<stack<int>, 3>& s, int n, int from, int to, int use)
{
	if (n > 0)
	{
		MoveRings(s, n - 1, from, use, to);
		s[to].push(s[from].top());
		s[from].pop();
		MoveRings(s, n - 1, use, to, from);
	}
}

array<stack<int>, 3> ComputeTowerOfHanoi(int rings)
{
	// The recursive procedure is as follows: move n - 1 discs from FROM to USE through to, then move the nth disc from FROM to TO, then move n-1 discs back from USE to TO through FROM. Perform recursively.
	array<stack<int>, 3> s;
	for (int i = 0; i < rings; i++)
		s[0].push(rings - i);
	MoveRings(s, rings, 0, 1, 2);
	return s;
}

void TestComputeTowerOfHanoi()
{
	auto s = ComputeTowerOfHanoi(4);
	assert(s[1].size() == 4);
	assert(s[0].empty());
	assert(s[2].empty());
}

// ----------------------------------------------------------
// 16.2 GENERATE ALL NONATTACKING PLACEMENTS OF N-QUEENS*
bool IsPlacementValid(vector<int>& p)
{
	auto r = (int)p.size() - 1;
	for (int i = 0; i < r; i++)
	{
		int t = abs(p[i] - p[r]);
		if (t == r - i || t == 0)
			return false;
	}
	return true;
}

void TestQueen(vector<int> p, int row, int n, vector<vector<int>>& results)
{
	if (row == n)
		results.emplace_back(p);
	else
	{
		for (int i = 0; i < n; i++)
		{
			p.emplace_back(i);
			if (IsPlacementValid(p))
				TestQueen(p, row + 1, n, results);
			p.pop_back();
		}
	}
}

vector<vector<int>> GenerateNonAttackingPlacementNQueens(int n)
{
	// Solve for each additional queen recursively, testing each starting position, considering one queen per row. The test for an invalid queen can be made in a succinct manner by testing if i - p[j] == row - j (diagonal) or 
	// zero (column), where p is the column on which each queen is placed for each row.
	vector<vector<int>> results;
	vector<int> p;
	TestQueen(p, 0, n, results);
	return results;
}

void TestGenerateNonAttackingPlacementNQueens()
{
	auto r = GenerateNonAttackingPlacementNQueens(4);
	assert(r[0] == vector<int>({1, 3, 0, 2}));
	assert(r[1] == vector<int>({2, 0, 3, 1}));
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
void SearchParens(string s, int ko, int kc, vector<string>& result)
{
	if (ko == 0 && kc == 0)
		result.emplace_back(s);
	if (ko > 0)
		SearchParens(s + "(", ko - 1, kc, result);
	if (ko < kc)
		SearchParens(s + ")", ko, kc - 1, result);
}

vector<string> GenerateStringsMatchedParens(int k)
{
	// Track that we need ko ( and kc ). if ko > 0, search recursively with ( suffix. If ko < kc, search with ) suffix. This consume the parens according to the specified rule set.
	vector<string> result;
	SearchParens("", k, k, result);
	return result;
}

void TestGenerateStringsMatchedParens()
{
	auto r = GenerateStringsMatchedParens(2);
	assert(r == vector<string>({"(())", "()()"}));
}

// ----------------------------------------------------------
// 16.7 GENERATE PALINDROMIC DECOMPOSITIONS* TRICKY
bool IsPalindrome(const string& s)
{
	for (int i = 0, j = s.size() - 1; i < j; i++ , j--)
	{
		if (s[i] != s[j])
			return false;
	}
	return true;
}

void FindPalindromicDecomp(const string& s, int offset, vector<string>& partialDecomp, vector<vector<string>>& result)
{
	if (offset == s.size())
	{
		result.emplace_back(partialDecomp);
		return;
	}
	for (int i = offset + 1; i <= static_cast<int>(s.size()); i++)
	{
		string prefix = s.substr(offset, i - offset);
		if (IsPalindrome(prefix))
		{
			partialDecomp.emplace_back(prefix); // Note the push pop behavior to implement the recursive structure properly.
			FindPalindromicDecomp(s, i, partialDecomp, result);
			partialDecomp.pop_back();
		}
	}
}

vector<vector<string>> GeneratePalindromicDecompositions(const string& s)
{
	// Recursively test with palindrome of length n, consuming the string as you advance.
	vector<string> partialDecomp;
	vector<vector<string>> result;
	FindPalindromicDecomp(s, 0, partialDecomp, result);
	return result;
}

void TestGeneratePalindromicDecompositions()
{
	auto r = GeneratePalindromicDecompositions("0204451881");
	for (auto& s : r)
	{
		string conc = "";
		for (auto& s2 : s)
		{
			conc += s2;
			assert(IsPalindrome(s2));
		}
		assert(conc == "0204451881");
	}
}

// ----------------------------------------------------------
// 16.8 GENERATE BINARY TREES* TRICKY (yet simple)
TreeNodePtr CloneTree(TreeNodePtr t)
{
	return t ? make_shared<TreeNode<int>>(TreeNode<int>{t->value, CloneTree(t->left), CloneTree(t->right)}) : nullptr;
}

vector<TreeNodePtr> GenerateBinaryTrees(int n)
{
	// View the numbers in an array as a representation of a binary tree. Then split the array recursively according to all the possible subdivisions at each node: 1 element on left, 2 element on left, etc.
	if (n == 0)
		return vector<TreeNodePtr>({nullptr});
	vector<TreeNodePtr> result;
	for (int i = 0; i < n; i++)
	{
		auto leftTrees = GenerateBinaryTrees(i);
		auto rightTrees = GenerateBinaryTrees(n - i - 1);
		for (auto left : leftTrees)
			for (auto right : rightTrees)
				result.emplace_back(make_shared<TreeNode<int>>(TreeNode<int>{0, CloneTree(left), CloneTree(right)}));
	}
	return result;
}

void TestGenerateBinaryTrees()
{
	auto r = GenerateBinaryTrees(3);
	assert(r.size() == 5);
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
template <class T>
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

void TestRecursion()
{
	TestComputeTowerOfHanoi();
	TestGenerateNonAttackingPlacementNQueens();
	TestGenerateStringsMatchedParens();
	TestGeneratePalindromicDecompositions();
	TestGenerateBinaryTrees();
}