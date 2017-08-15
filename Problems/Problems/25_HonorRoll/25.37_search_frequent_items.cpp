// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

// Finds the candidates which may occur > n / k times.
vector<string> SearchFrequentItems(int k, istringstream* stream) 
{
	vector<string> ret;
	return ret;
}

#pragma region Test

string RandStringFreqItems(int len)
{
	string ret;
	default_random_engine gen((random_device())());
	while (len--) 
	{
		uniform_int_distribution<int> dis('a', 'z');
		ret += dis(gen);
	}
	return ret;
}

void CheckAns(vector<string>* stream, int k, vector<string>* items) {
	sort(items->begin(), items->end());
	sort(stream->begin(), stream->end());
	int count = 1, idx = 0;
	for (int i = 1; i < stream->size(); ++i) 
	{
		if ((*stream)[i].compare((*stream)[i - 1])) 
		{
			if (count > static_cast<double>(stream->size()) / k) 
			{
				assert(idx < items->size());
				assert((*stream)[i - 1].compare((*items)[idx++]) == 0);
			}
			count = 1;
		}
		else {
			++count;
		}
	}
	if (count > static_cast<double>(stream->size()) / k) {
		assert((*stream).back().compare((*items)[idx++]) == 0);
	}
	assert(idx == items->size());
}

void SearchFrequentItemsTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 100; ++times) 
	{
		//cout << times << endl;
		vector<string> stream;
		int n, k;
		uniform_int_distribution<int> n_dis(0, 999);
		n = n_dis(gen);
		uniform_int_distribution<int> k_dis(1, n);
		k = k_dis(gen);
		for (int i = 0; i < n; ++i) 
		{
			uniform_int_distribution<int> dis(1, 5);
			stream.emplace_back(RandStringFreqItems(dis(gen)));
		}
		string s;
		for (int i = 0; i < stream.size(); ++i) 
		{
			s += stream[i];
			s += ' ';
		}
		istringstream stream2(s);
		vector<string> items = SearchFrequentItems(k, &stream2);
		CheckAns(&stream, k, &items);
	}
#endif
}

#pragma endregion Test