// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Shared.h"

#define TEST 0

string MajoritySearch(istringstream& input)
{
	return "";
}

#pragma region Test

void CheckAns(vector<string>& stream, const string& ans)
{
	sort(stream.begin(), stream.end());
	int candidate_count = 1;
	bool find = false;
	for (int i = 1; i < stream.size(); ++i)
	{
		if (stream[i].compare(stream[i - 1]))
		{
			if (candidate_count * 2 >= stream.size())
			{
				assert(ans.compare(stream[i - 1]) == 0);
				find = true;
			}
			candidate_count = 1;
		}
		else
		{
			++candidate_count;
		}
	}
	if (candidate_count * 2 >= stream.size())
	{
		assert(ans.compare(stream.back()) == 0);
		find = true;
	}
	assert(find == true);
}

void MajoritySearchTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 100; ++times)
	{
		int n;
		vector<string> stream;
		uniform_int_distribution<int> n_dis(1, 1000);
		n = n_dis(gen);
		for (int i = 0; i < n; ++i)
		{
			uniform_int_distribution<int> dis(1, 5);
			stream.emplace_back(RandString(dis(gen)));
		}
		// generate the majority
		for (int i = 0; i < n; ++i)
		{
			stream.emplace_back(stream.back());
		}
		string s;
		for (int i = 0; i < stream.size(); ++i)
		{
			s += stream[i];
			s += ' ';
		}
		istringstream input_stream(s);
		string ret(MajoritySearch(input_stream));
		//cout << ret << endl;
		CheckAns(stream, ret);
	}
#endif
}

#pragma endregion Test
