// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Finds the candidates which may occur > n / k times.
	//
	// Some observations:
	// We reject k elements at a time, which implies we will only ever do n/k rejections.
	// Thus any candidate with greater than n/k elements is guaranteed to have a positive count after all rejections have been performed.
	// Furthermore, there can't be more than k such candidates, since those candidates have more than n/k elements to start with.
	//
	// Also, it can proved that elements that appear n/k times before discarding the current set of candidates wills still appear n/k times after discarding the current set (aka m-1>/(n-k)/k implies m>n/k).
	vector<string> SearchFrequentItems(int k, istringstream* stream)
	{
		string buf;
		unordered_map<string, int> table;
		int n = 0;  // Count the number of strings.

		while (*stream >> buf)
		{
			++table[buf], ++n;
			// Detecting k items in table, at least one of them must have exactly one in it. We will discard those k items by one for each.
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