// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<string> DecomposeIntoDictionaryWords(const string& domain, const unordered_set<string>& dictionary)
	{
		// When the algorithm finishes, last_length[i] != -1 indicates domain.substr(0, i + 1) has a valid decomposition, and the length of the last string in the decomposition is last_length[i].
		vector<int> last_length(domain.size(), -1);
		for (int i = 0; i < domain.size(); ++i)
		{
			// If domain.substr(0, i + 1) is a dictionary word, set last_length[i] to the length of that word.
			if (dictionary.count(domain.substr(0, i + 1)))
				last_length[i] = i + 1;

			// If last_length[i] = -1 look for j < i such that domain.substr(0, j + 1) has a valid decomposition and domain.substring(j + 1, i + 1) is a dictionary word. 
			// If so, record the length of that word in last_length[i].
			if (last_length[i] == -1)
			{
				for (int j = 0; j < i; ++j)
				{
					if (last_length[j] != -1 && dictionary.count(domain.substr(j + 1, i - j)))
					{
						last_length[i] = i - j;
						break;
					}
				}
			}
		}

		vector<string> decompositions;
		if (last_length.back() != -1)
		{
			// domain can be assembled by dictionary words.
			int idx = domain.size() - 1;
			while (idx >= 0)
			{
				decompositions.emplace_back(domain.substr(idx + 1 - last_length[idx], last_length[idx]));
				idx -= last_length[idx];
			}
			reverse(decompositions.begin(), decompositions.end());
		}
		return decompositions;
	}
}
