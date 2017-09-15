// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Returns a random k-sized subset of {0, 1, ..., n - 1}.
	vector<int> RandomSubset(int n, int k)
	{
		unordered_map<int, int> changedElements;
		default_random_engine seed((random_device())());
		for (int i = 0; i < k; ++i)
		{
			// Generate a random index in [i, n - 1].
			int randIndex = uniform_int_distribution<int>{ i, n - 1 }(seed);
			auto iterRand = changedElements.find(randIndex), iterI = changedElements.find(i);
			if (iterRand == changedElements.end() && iterI == changedElements.end())
			{
				// Neither element is in the hash table, perform the swap on both elements.
				changedElements[randIndex] = i;
				changedElements[i] = randIndex;
			}
			else if (iterRand == changedElements.end() && iterI != changedElements.end())
			{
				// Note we are always adding the entry in the hash table that wasn't found. The other entry gets its iterator's value updated.
				// We picked an element < i, so we have to get what used to be at i.
				changedElements[randIndex] = iterI->second;
				iterI->second = randIndex; // Update spot i to have the new random index.
			}
			else if (iterRand != changedElements.end() && iterI == changedElements.end())
			{
				// We picked a specific random index > i that was picked before, so updated the i with the random index, and set the random index in the table to point to i.
				changedElements[i] = iterRand->second;
				iterRand->second = i;
			}
			else
			{
				// Both i and the random index are in the hash table. Swap the entries in the hash table.
				// Could have used the iterators here, which seems like it would be faster and more consistent.
				int temp = iterI->second;
				changedElements[i] = iterRand->second;
				changedElements[randIndex] = temp;
			}
		}

		vector<int> result;
		for (int i = 0; i < k; ++i)
			result.emplace_back(changedElements[i]);
		return result;
	}
}
