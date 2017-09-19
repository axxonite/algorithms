// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool MatchAllWordsInDict(const string& s, const unordered_map<string, int>& wordToFreq, int start, int wordCount, int unitSize)
	{
		unordered_map<string, int> curStringToFreq;
		for (int i = 0; i < wordCount; ++i)
		{
			string curWord = s.substr(start + i * unitSize, unitSize);
			auto iter = wordToFreq.find(curWord);
			if (iter == wordToFreq.end())
				return false;
			++curStringToFreq[curWord];
			if (curStringToFreq[curWord] > iter->second)
				return false; // curWord occurs too many times for a match to be possible.
		}
		return true;
	}

	vector<int> FindAllSubstrings(const string& s, const vector<string>& words)
	{
		unordered_map<string, int> wordToFreq;
		for (const string& word : words)
			++wordToFreq[word];

		int unitSize = words.front().size();
		vector<int> result;
		for (int i = 0; i + unitSize * words.size() <= s.size(); ++i)
			if (MatchAllWordsInDict(s, wordToFreq, i, words.size(), unitSize))
				result.emplace_back(i);
		return result;
	}
}
