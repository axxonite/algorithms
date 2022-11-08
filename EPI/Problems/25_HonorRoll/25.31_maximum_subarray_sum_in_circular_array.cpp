// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int MaxSubarraySumInCircular(const vector<int>& A)
{
	return 0;
}

#pragma region Test
int CheckAnsMaxSubarraySumInCircular(const vector<int>& A)
{
	int ans = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		int sum = 0;
		for (int j = 0; j < A.size(); ++j)
		{
			sum += A[(i + j) % A.size()];
			ans = max(ans, sum);
		}
	}
	cout << "correct answer = " << ans << endl;
	return ans;
}

void MaxSubarraySumInCircularTest()
{
#ifdef TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		int n;
		vector<int> A;
		uniform_int_distribution<int> dis(1, 10000);
		n = dis(gen);
		while (n--)
		{
			uniform_int_distribution<int> dis(-10000, 10000);
			A.emplace_back(dis(gen));
		}
		int ans = MaxSubarraySumInCircular(A);
		/*
			for (size_t i = 0; i < A.size(); ++i) {
			cout << A[i] << ' ';
			}
			//*/
		cout << endl << "maximum sum = " << ans << endl;
		assert(ans == CheckAnsMaxSubarraySumInCircular(A));
	}
#endif
}
#pragma endregion Test
