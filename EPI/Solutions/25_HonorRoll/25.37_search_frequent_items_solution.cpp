// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Finds the candidates which may occur > n / k times.
	//
	// We start with a set of elements (imagine a set of letter tiles in a bag), and lets assume that one element m appears more than n/k times, e.g. m>n/k. 
	// We take k DISTINCT elements at random and remove them from the set (which means if we draw the same letter twice from the bag, we will put it back in the bag). 
	// If m happened to not be in those k elements, then clearly m>(n-k)/k since only the right side was decremented.
	// Now let's assume m was part of the k elements. Now have m-1>(n-k)/k => k(m-1)>n-k => km-k>n-k => km>n => m>n/k.
	// This means that after taking k random, distinct letter tiles from an imaginary bag, the letters that are still in the bag still have enough m elements to have reach the threshold for the
	// right proportion.
	//
	// An easier way to see this is that we form random subsets of k distinct elements from the elements in the wider set. Each subset of distinct elements is discarded from the set.
	// Since there are k elements in each set, we will only have a maximum of n/k such subsets. Since the letters in each subset are distinct, a given element will only ever be discard n/k times.
	// Because the elements we are looking appear more than n/k times, they are guaranteed to be the last ones remaining after we have discarded as many distinct k-size subsets as we can.
	vector<string> SearchFrequentItems(int k, istringstream* stream)
	{
		string buf;
		unordered_map<string, int> table;
		int n = 0;  // Count the number of strings.

		while (*stream >> buf)
		{
			++table[buf], ++n;
			// Detecting k items in table, at least one of them must have exactly one in it. We will discard those k items by one for each.
			// Must check for exactly k here.
			if (table.size() == k)
			{
				auto it = table.begin();
				while (it != table.end())
				{
					if (--(it->second) == 0)
						table.erase(it++);
					else
						++it;
				}
			}
		}

		// Resets table for the following counting.
		// MUST get a reference here.
		for (auto& it : table)
			it.second = 0;

		// Resets the stream and read it again.
		stream->clear();
		stream->seekg(0, ios::beg);
		// Counts the occurrence of each candidate word.
		while (*stream >> buf)
		{
			auto it = table.find(buf);
			if (it != table.end())
				++it->second;
		}

		// Selects the word which occurs > n / k times.
		vector<string> ret;
		for (const auto& it : table)
		{
			if (it.second > static_cast<double>(n) / k)
				ret.emplace_back(it.first);
		}
		return ret;
	}
}