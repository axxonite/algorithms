#include "stdafx.h"
#include "Honors.h"

using namespace std;

// ----------------------------------------------------------
// 25.2 FIND THE MISSING POSITIVE ENTRY
int FindFirstMissingEntry(vector<int> A)
{
	// The key insight here is that the smallest possible integer that can be missing cannot be greater than n + 1. If the array contains all positive integers from 0..n, then the solution is n+1; if it doesn't sound, the solution
	// has to be <= n. This means we can use the array as a hash table by swapping the values in the slot corresponding to their value, then swapping the value that was there before with the slot where that values belongs,
	// in so forth, continuing the cycle until we arrive at a value <= 0 or a value that is already in its proper slot.
	// This effectively sorts the array, except for the negative values which stay where they are and are inconsequential. We can then go through the array looking for the first gap in the sequence.
	return 0;
}