// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "shared.h"

namespace Solutions
{
	// Uses BFS to find the least steps of transformation.
	int TransformString(unordered_set<string> d, const string& s, const string& t)
	{
		struct StringWithDistance
		{
			string candidateString;
			int distance;
		};
		queue<StringWithDistance> q;
		d.erase(s); // Marks s as visited by erasing it in d.
		q.emplace(StringWithDistance{ s, 0 });

		while (!q.empty())
		{
			StringWithDistance f(q.front());
			// Returns if we find a match.
			if (f.candidateString == t)
				return f.distance; // Number of steps reaches t.

			// Tries all possible transformations of f.candidate_string.
			string str = f.candidateString;
			for (int i = 0; i < str.size(); ++i) // for every position in the string.
			{
				for (int c = 0; c < 26; ++c) // for every possible character.
				{ // Iterates through 'a' ~ 'z'.
					str[i] = 'a' + c;
					auto it(d.find(str));
					if (it != d.end())
					{
						d.erase(it); // found a match, erase it from dict and queue it in bfs
						q.emplace(StringWithDistance{ str, f.distance + 1 });
					}
				}
				str[i] = f.candidateString[i]; // Reverts the change of str.
			}
			q.pop();
		}

		return -1; // Cannot find a possible transformations.
	}
}
