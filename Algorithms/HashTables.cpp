#include "stdafx.h"
#include "HashTables.h"
#include "BinaryTrees.h"
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ----------------------------------------------------------
// 13.1 TEST FOR PALINDROMIC PERMUTATIONS
bool TestForPalindromicPermutations(const string& s)
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

SubArray FindSmallestSubArrayCoveringSet(const vector<string>& paragraph, const unordered_set<string>& keywords)
{
	// Consider the set of all sub-arrays. There are n^2. Start a set at i, increasing length, Record which strings were covered in a hash table. But we can do better.
	// Note that, when moving from i to i+1, there is no way for [i+1..j to cover the set since [i..j] already barely covers the set. We thus need to advance j until it 
	// covers the set. When j matches, we can advance i again, switching back and forth between advancing i and j.

	unordered_map<string, int> keywordsToCover;
	for (auto k : keywords)
		keywordsToCover[k]++;

	SubArray result{-1, -1};
	int remainingToCover = keywordsToCover.size();
	for (int left = 0, right = 0; right < static_cast<int>(paragraph.size()); right++)
	{
		if (keywordsToCover.count(paragraph[right]) > 0 && --keywordsToCover[paragraph[right]] >= 0)
			remainingToCover--;
		while (remainingToCover == 0)
		{
			if ((result.start == -1 && result.end == -1) || (right - left < result.end - result.start))
				result = {left, right};
			if (keywords.count(paragraph[left]) && ++keywordsToCover[paragraph[left]] > 0) // Note the use of count() to check if the key exists in the unordered map.
				remainingToCover++;
			left++;
		}
	}
	return result;
}

void TestFindSmallestSubArrayCoveringSet()
{
	vector<string> p = {"save", "my", "paramount", "object", "in", "this", "struggle", "is", "to", "save", "the", "Union", "Union"};
	unordered_set<string> k = {"Union", "save"};
	auto r = FindSmallestSubArrayCoveringSet(p, k);
	assert(r.start == 9 && r.end == 11);
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
	unordered_map<string, int> keywordToIndex;
	for (size_t i = 0; i < keywords.size(); i++)
		keywordToIndex[keywords[i]] = i;

	vector<int> pos(keywords.size(), -1);
	vector<int> length(keywords.size(), -1);

	int bestDistance = numeric_limits<int>::max();
	SubArray result{-1, -1};
	for (int i = 0; i < static_cast<int>(paragraph.size()); i++)
	{
		if (keywordToIndex.count(paragraph[i]) > 0)
		{
			int index = keywordToIndex.find(paragraph[i])->second; // Do I need to use find or at? Why second?
			pos[index] = i;
			if (index == 0)
				length[0] = 1;
			else if (length[index - 1] != -1)
				length[index] = length[index - 1] + i - pos[index - 1];
			if (index == keywords.size() - 1 && length.back() != -1 && length.back() < bestDistance)
			{
				result = {i - length.back() + 1, i}; // Note the +1
				bestDistance = result.end - result.start;
			}
		}
	}
	return result;
}

void FindSmallestSubArraySequentiallyCoveringAllValues()
{
	vector<string> p = {"save", "my", "paramount", "object", "in", "this", "struggle", "is", "to", "save", "the", "Union", "Union"};
	vector<string> k = {"Union", "save"};
	auto r = FindSmallestSubArraySequentiallyCoveringAllValues(p, k);
	assert(r.start == -1 && r.end == -1);
	vector<string> k2 = {"save", "Union"};
	auto r2 = FindSmallestSubArraySequentiallyCoveringAllValues(p, k2);
	assert(r2.start == 9 && r2.end == 11);
}

// ----------------------------------------------------------
// 13.9 FIND THE LONGUEST SUBARRAY WITH DISTINCT ENTRIES*
int LonguestSubArrayWithDistinctEntries(const vector<int>& a)
{
	// Start at i = 1, which gives us a starting matching set of size one. The next character c can either be a new distinct character, which extends the current matching set. Or
	// a character that is already in the sequence we've matched; in this case, we need to advance to the start of the match to the last occurrence of c, plus one. We can then try
	// to extend the matching set on the right again.
	int longuest = 0, left = 0;
	unordered_map<int, int> lastOccurence;
	for (int i = 0; i < static_cast<int>(a.size()); i++)
	{
		if (lastOccurence.count(a[i]) > 0)
			left = lastOccurence.at(a[i]) + 1;
		lastOccurence[a[i]] = i;
		longuest = max(longuest, i - left);
	}
	return longuest;
}

void TestLonguestSubArrayWithDistinctEntries()
{
	vector<int> a = {0, 1, 0, 2, 3, 4, 2, 5, 4, 2};
	auto r = LonguestSubArrayWithDistinctEntries(a);
	assert(r == 4);
}

// ----------------------------------------------------------
// 13.10 FIND THE LENGTH OF A LONGUEST CONTAINED INTERVAL*
int FindLengthLonguestContainingInterval(const vector<int>& a)
{
	// Store the values in an unordered set. Then start from the first item in the array and look for a chain of subsequents, and a chain of antecedents. Remove
	// then entries from the set as they are found. This gives us the length of that chain. Move to the next item, and walk the chain on both sides there too, and so forth.
	// Removing the entries from the hash table ensure we don't walk the same chain twice.
	int result = 0;
	unordered_set<int> s(a.begin(), a.end()); // Note the use of iterators.
	while (!s.empty()) // Note that using the set as the outer loop is better than iterating the array.
	{
		int value = *s.begin(); // Pay attention to the dereferencing of the iterator to get the value on begin().
		s.erase(value); // Note the use of erase to remove entries from the set.
		auto length = 1;
		for (int v = value + 1; s.count(v); v++ , length++)
			s.erase(v);
		for (int v = value - 1; s.count(v); v-- , length++)
			s.erase(v);
		result = max(result, length);
	}
	return result;
}

void TestFindLengthLonguestContainingInterval()
{
	vector<int> a = {10, 5, 3, 11, 6, 100, 4};
	auto r = FindLengthLonguestContainingInterval(a);
	assert(r == 4);
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
bool MatchWords(const unordered_map<string, int>& freq, const vector<string>& words, int i, const string& s)
{
	unordered_map<string, int> found;
	int wordSize = words.front().size();
	for (size_t j = i; j + wordSize < s.size(); j += wordSize)
	{
		auto sub = s.substr(j, wordSize); // Note that substr takes a length, not the position of the last character.
		auto it = freq.find(sub); // Note the use of find.
		if (it != freq.end())
		{
			found[sub]++;
			if (found[sub] > it->second)
				return false;
		}
		else return false;
	}
	return true;
}

vector<int> ComputeAllStringDecompositions(const string& s, const vector<string>& words)
{
	// Add the words to a set. Consume the string, attempting to match with each word in the set. If matched, remove from the candidate set. Do this at each index in the string.
	// Of note, if the keywords had not been distinct, and a keyword may have been a prefix of another. In this case, we would have had to do recursive test, testing for multiple
	// potential candidates at each level.
	vector<int> result;
	if (words.empty())
		return result;
	unordered_map<string, int> freq;
	for (auto& word : words)
		freq[word]++;
	int wordSize = words[0].size();
	for (int i = 0; i + words.size() * wordSize < s.size(); i++) // Careful to not run off the end of the sentence. 
	{
		if (MatchWords(freq, words, i, s))
			result.emplace_back(i);
	}
	return result;
}

void TestComputeAllStringDecompositions()
{
	vector<string> words = {"can", "apl", "ana"};
	auto r = ComputeAllStringDecompositions("amanaplanacanal", words);
	assert(r == vector<int> { 4});
}

// ----------------------------------------------------------
// 13.3 TEST THE COLLATZ CONJECTURE*
bool TestCollatzConjecture(int n)
{
	// This is an open-ended problem whose solution entails checking multiple aspects of the series. A hash table should be used to cache values previously visited. If all integers
	// below some n have been visited, there is no need to store them in the hash table, they can be removed and we can simply test if our candidate is >= n. x/2 does not need
	// to be tested since all numbers below x will have been tested. Check for overflows for the 3x+1 value. Use parallelism to compute multiple segments of the interval 
	// simultaneously.
	unordered_set<int> proven;
	for (int i = 3; i <= n; i += 2) // Don't test even numbers since they lead to n / 2.
	{
		unordered_set<int> visited;
		long x = i;
		while (x > i)
		{
			visited.emplace(x);
			if (x % 1)
			{
				if (!proven.emplace(x).second) // Note how we emplace and use the second member to test if the set already contains that element.
					break;
				long temp = x * 3 + 1;
				if (temp < x) // Note how we test for overflow.
					throw overflow_error("Overflowed while testing.");
				x = temp;
			}
			else x /= 2;
			if (!visited.emplace(x).second)
				return false;
		}
		proven.erase(i);
	}
	return true;
}

void TestTestCollatzConjecture()
{
	auto r = TestCollatzConjecture(1000);
	assert(r);
}

// ----------------------------------------------------------
// 13.4 IMPLEMENT A HASH FUNCTION FOR CHESS**
//
// Generate 64-bit random bit integers for each of the 13 states and the 64 positions on the board, which gives 832 different codes. The hash of a chess position is then the XOR
// of all codes. To update with a move, erase the state of the starting square, add the new state of the starting square, erase the state of the destination square, and add the
// new state of the destination square, through 4 XOR operations.

void TestHashTables()
{
	TestFindSmallestSubArrayCoveringSet();
	FindSmallestSubArraySequentiallyCoveringAllValues();
	TestLonguestSubArrayWithDistinctEntries();
	TestFindLengthLonguestContainingInterval();
	TestComputeAllStringDecompositions();
	TestTestCollatzConjecture();
}