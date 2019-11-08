// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int FindLongestSubarrayLessEqualK(const vector<int>& A, int k)
{
	return 0;
}

#pragma region Test

// O(n^2) checking answer.
template <typename T>
void CheckAnswer(const vector<T> &A, int ans, const T &k) {
	vector<T> sum(A.size() + 1, 0);
	sum[0] = 0;
	for (size_t i = 0; i < A.size(); ++i) {
		sum[i + 1] = sum[i] + A[i];
	}
	if (ans != 0) {
		for (size_t i = 0; i < sum.size(); ++i) {
			for (size_t j = i + 1; j < sum.size(); ++j) {
				if (sum[j] - sum[i] <= k) {
					assert((j - i) <= ans);
				}
			}
		}
	}
	else {
		for (size_t i = 0; i < sum.size(); ++i) {
			for (size_t j = i + 1; j < sum.size(); ++j) {
				assert(sum[j] - sum[i] > k);
			}
		}
	}
}

void SmallTestFindLongestSubarrayLessEqualK() {
	vector<int> A = { 1, 1 };
	int k = 0;
	int res = FindLongestSubarrayLessEqualK(A, k);
	assert(res == 0);
	k = -100;
	res = FindLongestSubarrayLessEqualK(A, k);
	assert(res == 0);
}

void FindLongestSubarrayLessEqualKTest() {
#ifdef TEST
	SmallTestFindLongestSubarrayLessEqualK();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 2; ++times) {
		int n, k;
		uniform_int_distribution<int> n_dis(1, 1000);
		n = n_dis(gen);
		uniform_int_distribution<int> k_dis(0, 999);
		k = k_dis(gen);
		vector<int> A;
		for (size_t i = 0; i < n; ++i) {
			uniform_int_distribution<int> dis(-1000, 1000);
			A.emplace_back(dis(gen));
		}
		int ans = FindLongestSubarrayLessEqualK(A, k);
		//cout << k << ' ' << ans << endl;
		CheckAnswer(A, ans, k);
	}
#endif
}

#pragma endregion 