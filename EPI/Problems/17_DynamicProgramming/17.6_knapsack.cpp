// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

struct Item
{
	int weight, value;
};

int OptimumSubjectToCapacity(const vector<Item>& items, int capacity)
{
	return 0;
}

#pragma region Test

vector<int> RandVector(int len)
{
	vector<int> ret;
	default_random_engine gen((random_device())());
	while (len--)
	{
		uniform_int_distribution<int> dis(0, 99);
		ret.emplace_back(dis(gen));
	}
	return ret;
}

void OptimumSubjecToCapacitySmallTest()
{
	// The example in the book.
	vector<Item> items = { { 20, 65 },{ 8, 35 },{ 60, 245 },{ 55, 195 },
	{ 40, 65 },{ 70, 150 },{ 85, 275 },{ 25, 155 },
	{ 30, 120 },{ 65, 320 },{ 75, 75 },{ 10, 40 },
	{ 95, 200 },{ 50, 100 },{ 40, 220 },{ 10, 99 } };
	assert(695 == OptimumSubjectToCapacity(items, 130));

	items = { { 5, 60 },{ 3, 50 },{ 4, 70 },{ 2, 30 } };
	assert(80 == OptimumSubjectToCapacity(items, 5));
}

void OptimumSubjectToCapacityTest()
{
#ifdef TEST
	OptimumSubjecToCapacitySmallTest();
	default_random_engine gen((random_device())());
	vector<int> weight, value;
	int n, W;
	uniform_int_distribution<int> n_dis(1, 100);
	n = n_dis(gen);
	uniform_int_distribution<int> W_dis(1, 1000);
	W = W_dis(gen);
	weight = RandVector(n), value = RandVector(n);
	cout << "Weight: ";
	for (int i = 0; i < n; ++i)
	{
		cout << weight[i] << ' ';
	}
	cout << endl << "Value: ";
	for (int i = 0; i < n; ++i)
	{
		cout << value[i] << ' ';
	}
	cout << endl;
	vector<Item> items;
	for (int i = 0; i < weight.size(); ++i)
	{
		items.emplace_back(Item{ weight[i], value[i] });
	}
	cout << "Knapsack size = " << W << endl;
	cout << "all value = " << OptimumSubjectToCapacity(items, W) << endl;
#endif
}

#pragma endregion Test
