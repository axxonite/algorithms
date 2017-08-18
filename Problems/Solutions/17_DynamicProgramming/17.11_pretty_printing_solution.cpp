// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int MinimumMessiness(const vector<string>& words, int lineLength)
	{
		// minMessiness[i] is the minimum messiness when placing words[0, i]. A solution for a longer text is built from the optimal solutions for the shorter ones.
		vector<int> minMessiness(words.size(), numeric_limits<int>::max());
		// The base case has only one word in the text/
		int remainingBlanks = lineLength - words[0].size();
		minMessiness[0] = remainingBlanks * remainingBlanks;
		for (int i = 1; i < words.size(); ++i)
		{
			// The base case here starts with only one word on the last line.
			remainingBlanks = lineLength - words[i].size();
			minMessiness[i] = minMessiness[i - 1] + remainingBlanks * remainingBlanks;
			// Try a last line with the two last words, the three last words, and so forth.
			for (int j = i - 1; j >= 0; --j)
			{
				// j indicates the first word on the last line.
				// Add one word and a blank.
				remainingBlanks -= (words[j].size() + 1);
				if (remainingBlanks < 0)
					break; // Not enough space to add more words.
				// Define the the "body" of the text as the text before the last line. 
				int bodyMessiness = j - 1 < 0 ? 0 : minMessiness[j - 1];
				// Check if this new arrangement of words is better than the one we already have.
				minMessiness[i] = min(minMessiness[i], bodyMessiness + remainingBlanks * remainingBlanks);
			}
		}
		return minMessiness.back();
	}
}
