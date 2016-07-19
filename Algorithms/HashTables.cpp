#include "stdafx.h"
#include "HashTables.h"
#include "BinaryTrees.h"
#include <unordered_set>

using namespace std;

// ----------------------------------------------------------
// 13.1 TEST FOR PALINDROMIC PERMUTATIONS
bool TestForPalindromicPermutations(const string& s )
{
	// Map characters to their frequencies in a hash table (or just an array, really). For an even-length word, we need two of each character. For an odd-length word, we need
	// two of each character, and one of a single character.
	return false;
}

// ----------------------------------------------------------
// 13.2 CONSTRUCT ANONYMOUS LETTER
bool IsLetterConstructible(const string& text, const string& magazine)
{
	// Count letters in the letter, assigning them to a hash table. Then run through the letters in the magazine decrementing the count from the hash table for each matching letter.
	// We are done when have removed all the letters from the letter.
	return false;
}

// ----------------------------------------------------------
// 13.3 IMPLEMENT AN ISBN CACHE
//
// Store in a hash table, keyed on the ISBN. Each entry should map to a node in a linked list (a queue, really), so we can keep track of the LRU. Remove the LRU when the cache 
// is full.

// ----------------------------------------------------------
// 13.4 COMPUTE THE LCA, OPTIMIZING FOR CLOSE ANCESTORS
TreeNodePtr ComputeLCA(TreeNodePtr node0, TreeNodePtr node1)
{
	// Iterate through the ancestors of one node, then the other node, adding the parents to a hash table. When the parent is already in the hash table, we have found the LCA. 
	return TreeNodePtr();
}

// ----------------------------------------------------------
// 13.5 COMPUTE THE K MOST FREQUENT QUERIES
//
// Add the strings in a hash table, keeping a node to a min-heap.
// Alternatively you can use solution 12.8 to compute the k largest elements in the array of unique strings, comparing strings on their frequencies.

// ----------------------------------------------------------
// 13.6 FIND THE NEAREST REPEATED ENTRIES IN AN ARRAY
int FindNearestRepeatedEntriesInAnArray(const vector<string>& paragraph)
{
	// Keep a hash table with the location of the last instance of that entry. Compute difference with hash table value, and keep track of the best solution.
	return 0;
}

// ----------------------------------------------------------
// 13.7 FIND THE SMALLEST SUBARRRAY COVERING ALL THE VALUES**
struct SubArray
{
	int start;
	int end;
};

SubArray FindSmallestSubArrayCoveringSet( const vector<string>& paragraph, const unordered_set<string>& keywords)
{
	// Consider the set of all sub-arrays. There are n^2. Start a set at i, increasing length, Record which strings were covered in a hash table. But we can do better.
	// Note that, when moving from i to i+1, there is no way for [i+1..j to cover the set since [i..j] already barely covers the set. We thus need to advance j until it 
	// covers the set. When j matches, we can advance i again, switching back and forth between advancing i and j.
	return SubArray();
}

// ----------------------------------------------------------
// 13.8 FIND SMALLEST SUBARRAY SEQUENTIALLY COVERING ALL VALUES*
SubArray FindSmallestSubArraySequentiallyCoveringAllValues(const vector<string>& paragraph, const vector<string> keywords)
{
	// There's two solutions. One is to find k1, k2, k3, etc. That gives one solution. Then find next k1, if k1 <= k2, we have another (better solution). Keep looking for k1s.
	// When k1 > k2, start looking for k2s. If k2 < k3, then we have another solution. Keep going in this manner, until we reach kn. When no more kns can be found, we move k1
	// again, and so forth.
	//
	// The book's solution: keep a hash table p of the position of the most recent occurrence of a keyword, and a hash table l of the length of the shortest sub-array that ends
	// at that keyword. When look for a match for keyword j, then M[j] = (p[j-1]-l[j-1], p[j]). We are building solution j from the solution for j-1.
	// Note that we don't really need two hash tables. We can use one hash table that contains both values.
	return SubArray();
}

// ----------------------------------------------------------
// 13.9 FIND THE LONGUEST SUBARRAY WITH DISTINCT ENTRIES*
int LonguestSubArrayWithDistinctEntries(const vector<int>& a)
{
	// Start at i = 1, which gives us a starting matching set of size one. The next character c can either be a new distinct character, which extends the current matching set. Or
	// a character that is already in the sequence we've matched; in this case, we need to advance to the start of the match to the last occurrence of c, plus one. We can then try
	// to extend the matching set on the right again.
	return 0;
}

// ----------------------------------------------------------
// 13.10 FIND THE LENGTH OF A LONGUEST CONTAINED INTERVAL*
int FindLengthLonguestContainingInterval(const vector<int>& a)
{
	// Store the values in an unordered set. Then start from the first item in the array and look for a chain of subsequents, and a chain of antecedents. Remove
	// then entries from the set as they are found. This gives us the length of that chain. Move to the next item, and walk the chain on both sides there too, and so forth.
	// Removing the entries from the hash table ensure we don't walk the same chain twice.
	return 0;
}

// ----------------------------------------------------------
// 13.11 COMPUTE THE AVERAGE OF THE TOP THREE SCORES
string FindStudentWithhighestBothOfThreeScores(ifstream* ifs)
{
	// Store the test scores in a hash table that has a min-heap for each entry.
	return string();
}

// ----------------------------------------------------------
// 13.12 COMPUTE ALL STRING DECOMPOSITIONS*
vector<int> ComputeAllStringDecompositions(const string& s, const vector<string>& words)
{
	// Add the words to a set. Consume the string, attempting to match with each word in the set. If matched, remove from the candidate set. Do this at each index in the string.
	// Of note, if the keywords had not been distinct, and a keyword may have been a prefix of another. In this case, we would have had to do recursive test, testing for multiple
	// potential candidates at each level.
	return vector<int>();
}

// ----------------------------------------------------------
// 13.3 TEST THE COLLATZ CONJECTURE*
bool TestColltzConjectur(int n)
{
	// This is an open-ended problem whose solution entails checking multiple aspects of the series. A hash table should be used to cache values previously visited. If all integers
	// below some n have been visited, there is no need to store them in the hash table, they can be removed and we can simply test if our candidate is >= n. x/2 does not need
	// to be tested since all numbers below x will have been tested. Check for overflows for the 3x+1 value. Use parallelism to compute multiple segments of the interval 
	// simultaneously.
	return false;
}

// ----------------------------------------------------------
// 13.4 IMPLEMENT A HASH FUNCTION FOR CHESS**
//
// Generate 64-bit random bit integers for each of the 13 states and the 64 positions on the board, which gives 832 different codes. The hash of a chess position is then the XOR
// of all codes. To update with a move, erase the state of the starting square, add the new state of the starting square, erase the state of the destination square, and add the
// new state of the destination square, through 4 XOR operations.