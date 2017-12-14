// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool MatchAllWordsInDict(const string& s, const unordered_map<string, int>& dictWordInstanceCount, int start, int wordCount, int wordSize)
	{
		unordered_map<string, int> stringWordInstanceCount; // count how many instances of each word appear in the source string.
		// Try to make as many consequent matches as there are words in the dictionary.
		for (int i = 0; i < wordCount; ++i)
		{
			// Get the substring matching the current unit size position.
			string curWord = s.substr(start + i * wordSize, wordSize);
			auto iter = dictWordInstanceCount.find(curWord);
			if (iter == dictWordInstanceCount.end() || ++stringWordInstanceCount[curWord] > iter->second)
				return false; // can't match this word because there are more instance in the string than in the word dictionary.
		}
		return true;
	}

	vector<int> FindAllSubstrings(const string& s, const vector<string>& words)
	{
		// count how often each unique word appears in the dictionary.
		unordered_map<string, int> dictWordInstanceCount;
		for (const string& word : words)
			++dictWordInstanceCount[word];

		// all words have the same length so use the first word's length as the unit size.
		int wordSize = words.front().size();

		vector<int> result;
		// try to match each wordSize position in the input string.
		// Notice the use of <= because we are comparing word sizes.
		for (int i = 0; i + wordSize * words.size() <= s.size(); ++i)
			if (MatchAllWordsInDict(s, dictWordInstanceCount, i, words.size(), wordSize))
				result.emplace_back(i);
		return result;
	}
}
