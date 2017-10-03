// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "shared.h"

namespace Solutions
{
	// Uses BFS to find the least steps of transformation.
	int TransformString(unordered_set<string> D, const string& s, const string& t)
	{
		struct StringWithDistance
		{
			string candidateString;
			int distance;
		};
		queue<StringWithDistance> q;
		D.erase(s); // Marks s as visited by erasing it in D.
		q.emplace(StringWithDistance{ s, 0 });

		while (!q.empty())
		{
			StringWithDistance f(q.front());
			// Returns if we find a match.
			if (f.candidateString == t)
				return f.distance; // Number of steps reaches t.

			// Tries all possible transformations of f.candidate_string.
			string str = f.candidateString;
			for (int i = 0; i < str.size(); ++i)
			{
				for (int c = 0; c < 26; ++c)
				{ // Iterates through 'a' ~ 'z'.
					str[i] = 'a' + c;
					auto it(D.find(str));
					if (it != D.end())
					{
						D.erase(it);
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
