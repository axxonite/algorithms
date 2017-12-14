// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int FindMissingElement(ifstream* ifs)
{
	return 0;
}

#pragma region Test

void FindMissingElementTest()
{
#if TEST
	default_random_engine gen((random_device())());
	int n = 300000;
	vector<int> A(1000000000);
	iota(A.begin(), A.end(), 0);
	unordered_set<int> hash;
	ofstream ofs("missing.txt");
	for (int i = 0; i < n; ++i)
	{
		hash.emplace(A[i]);
		ofs << A[i] << endl;
	}
	A.clear();
	ofs.close();
	ifstream ifs("missing.txt");
	cout << "Before finding missing" << endl;
	int missing = FindMissingElement(&ifs);
	assert(hash.find(missing) == hash.cend());
	// Remove file after the execution.
	remove("missing.txt");
	cout << missing << endl;
#endif
}

#pragma endregion Test
