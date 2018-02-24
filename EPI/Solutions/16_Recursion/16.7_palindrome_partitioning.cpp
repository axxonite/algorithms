// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "shared.h"

#define TEST 0

bool IsPalindrome2(const string& prefix)
{
	return true;
}

vector<vector<string>> PalindromePartitioning(const string& input)
{
	vector<vector<string>> result;
	return result;
}

#pragma region Test

void CheckAns(const vector<vector<string>>& vecs, const string& input)
{
	for (const vector<string>& vec : vecs)
	{
		string temp;
		for (const string& s : vec)
		{
			assert( IsPalindrome2(s));
			temp += s;
		}
		assert(!temp.compare(input));
	}
}

static void PalindromePartitioningSimpleTest()
{
	auto result = PalindromePartitioning("abbbac");
	vector<string> v0 = {"a", "b", "b", "b", "a", "c"};
	vector<string> v1 = {"a", "b", "bb", "a", "c"};
	vector<string> v2 = {"a", "bb", "b", "a", "c"};
	vector<string> v3 = {"a", "bbb", "a", "c"};
	vector<string> v4 = {"abbba", "c"};
	vector<vector<string>> golden = {v0, v1, v2, v3, v4};
	assert(result == golden);
}

void PalindromePartitioningTest()
{
#if TEST
	PalindromePartitioningSimpleTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		uniform_int_distribution<size_t> dis_len(0, 10);
		string s = RandString(dis_len(gen));
		auto result = PalindromePartitioning(s);
		CheckAns(result, s);
		cout << "string s = " << s << endl;
		for (const vector<string>& vec : result)
		{
			for (const string& t : vec)
			{
				cout << t << " ";
			}
			cout << endl;
		}
	}
#endif
}

#pragma endregion Test
