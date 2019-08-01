// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "shared.h"

// #define TEST

vector<string> DecomposeIntoDictionaryWords(const string& s, const unordered_set<string>& dict)
{
	vector<string> result;

	return result;
}

#pragma region Test

// Verify the strings in ans can be assembled into s.
void DecomposeIntoDictionaryWordsCheckAns(const string& s, vector<string>& ans)
{
	string temp;
	cout << s << endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << ' ';
		temp += ans[i];
	}
	cout << endl;
	assert(!ans.size() || !s.compare(temp));
}

void DecomposeIntoDictionaryWordsSmallCase()
{
	unordered_set<string> dictionary = {"bed", "bath", "and", "hand", "beyond"};
	auto ans = DecomposeIntoDictionaryWords("bedbathandbeyond", dictionary);
	vector<string> golden_ans = {"bed", "bath", "and", "beyond"};
	DecomposeIntoDictionaryWordsCheckAns("bedbathandbeyond", ans);
	assert(equal(ans.begin(), ans.end(), golden_ans.begin(), golden_ans.end()));

	dictionary = {"aa", "b", "ccc"};
	ans = DecomposeIntoDictionaryWords("b", dictionary);
	golden_ans = {"b"};
	DecomposeIntoDictionaryWordsCheckAns("b", ans);
	assert(equal(ans.begin(), ans.end(), golden_ans.begin(), golden_ans.end()));

	ans = DecomposeIntoDictionaryWords("ccc", dictionary);
	golden_ans = {"ccc"};
	DecomposeIntoDictionaryWordsCheckAns("ccc", ans);
	assert(equal(ans.begin(), ans.end(), golden_ans.begin(), golden_ans.end()));

	ans = DecomposeIntoDictionaryWords("aabccc", dictionary);
	golden_ans = {"aa", "b", "ccc"};
	DecomposeIntoDictionaryWordsCheckAns("aabccc", ans);
	assert(equal(ans.begin(), ans.end(), golden_ans.begin(), golden_ans.end()));

	ans = DecomposeIntoDictionaryWords("baabccc", dictionary);
	golden_ans = {"b", "aa", "b", "ccc"};
	DecomposeIntoDictionaryWordsCheckAns("baabccc", ans);
	assert(equal(ans.begin(), ans.end(), golden_ans.begin(), golden_ans.end()));

	dictionary.insert("bb");
	ans = DecomposeIntoDictionaryWords("bbb", dictionary);
	// Note: golden_ans relies on how our algorithm is implemented: our
	// algorithm chooses longest word ending at that index, so the answer
	// is "b", "bb", not "b", "b", "b" or "bb", "b".
	golden_ans = {"b", "bb"};
	DecomposeIntoDictionaryWordsCheckAns("bbb", ans);
	assert(equal(ans.begin(), ans.end(), golden_ans.begin(), golden_ans.end()));

	ans = DecomposeIntoDictionaryWords("bbcccb", dictionary);
	golden_ans = {"bb", "ccc", "b"};
	DecomposeIntoDictionaryWordsCheckAns("bbcccb", ans);
	assert(equal(ans.begin(), ans.end(), golden_ans.begin(), golden_ans.end()));

	ans = DecomposeIntoDictionaryWords("bbcccbabb", dictionary);
	golden_ans = {};
	assert(equal(ans.begin(), ans.end(), golden_ans.begin(), golden_ans.end()));

	ans = DecomposeIntoDictionaryWords("d", dictionary);
	golden_ans = {};
	assert(equal(ans.begin(), ans.end(), golden_ans.begin(), golden_ans.end()));
}

void DecomposeIntoDictionaryWordsTest()
{
#ifdef TEST
	DecomposeIntoDictionaryWordsSmallCase();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 100; ++times)
	{
		unordered_set<string> dictionary;
		uniform_int_distribution<int> dis(1, 50);
		string target = RandString(dis(gen));
		uniform_int_distribution<int> n_dis(1, 10000);
		int n = n_dis(gen);
		while (n--)
		{
			uniform_int_distribution<int> dis(1, 15);
			dictionary.emplace(RandString(dis(gen)));
		}
		vector<string> ans(DecomposeIntoDictionaryWords(target, dictionary));
		DecomposeIntoDictionaryWordsCheckAns(target, ans);
	}
#endif
}

#pragma endregion Test
