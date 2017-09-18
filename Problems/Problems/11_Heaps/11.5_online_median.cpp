// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<double> global_result; // ?????? Fix this, we don't need this to be global.

void OnlineMedian(istringstream* sequence)
{
}

#pragma region Test

void OnlineMedianSmallTest()
{
	istringstream sequence("5 4 3 2 1");
	OnlineMedian(&sequence);
	vector<double> golden = {5, 4.5, 4, 3.5, 3};
	assert(equal(golden.begin(), golden.end(), global_result.begin(),
		global_result.end()));

	global_result.clear();
	istringstream sequence1("1 2 3 4 5");
	OnlineMedian(&sequence1);
	golden = {1, 1.5, 2, 2.5, 3};
	assert(equal(golden.begin(), golden.end(), global_result.begin(),
		global_result.end()));

	global_result.clear();
	istringstream sequence2("1 0 3 5 2 0 1");
	OnlineMedian(&sequence2);
	golden = {1, 0.5, 1, 2, 2, 1.5, 1};
	assert(equal(golden.begin(), golden.end(), global_result.begin(),
		global_result.end()));

	global_result.clear();
	istringstream sequence3("-1");
	OnlineMedian(&sequence3);
	golden = {-1.0};
	assert(equal(golden.begin(), golden.end(), global_result.begin(),
		global_result.end()));
}

void OnlineMedianTest()
{
#if TEST
	OnlineMedianSmallTest();
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> dis(1, 10000);
	int num = dis(gen);
	vector<int> stream;
	for (int i = 0; i < num; ++i)
	{
		uniform_int_distribution<int> dis(1, 10000);
		stream.emplace_back(dis(gen));
	}
	string s;
	for (int i = 0; i < stream.size(); ++i)
	{
		//cout << stream[i] << endl;
		stringstream ss;
		ss << stream[i];
		s += ss.str();
		s += ' ';
	}
	//cout << endl;
	istringstream sequence(s);
	OnlineMedian(&sequence);
#endif
}

#pragma endregion Test
