// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

double FindSalaryCap(double targetPayroll, vector<double> current_salaries)
{
	return 0;
}

#pragma region Test

void FindSalaryCapSmallTest()
{
	vector<double> A = {20, 30, 40, 90, 100};
	double T = 210;
	assert(FindSalaryCap(T, A) == 60);
	T = 280;
	assert(FindSalaryCap(T, A) == 100);
	T = 50;
	assert(FindSalaryCap(T, A) == 10);
	T = 281;
	assert(FindSalaryCap(T, A) == -1.0);
}

void FindSalaryCapTest()
{
#if TEST
	FindSalaryCapSmallTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		int n;
		vector<double> A;
		double tar;
		uniform_int_distribution<int> n_dis(1, 1000);
		n = n_dis(gen);
		uniform_int_distribution<int> tar_dis(0, 9999);
		tar = tar_dis(gen);
		for (int i = 0; i < n; ++i)
		{
			uniform_int_distribution<int> dis(0, 9999);
			A.emplace_back(dis(gen));
		}
		//cout << "A = ";
		//copy(A.begin(), A.end(), ostream_iterator<double>(cout, " "));
		//cout << endl;
		//cout << "tar = " << tar << endl;
		double ret = FindSalaryCap(tar, A);
		sort(A.begin(), A.end());
		if (ret != -1.0)
		{
			//cout << "ret = " << ret << endl;
			double sum = 0.0;
			for (int i = 0; i < n; ++i)
			{
				if (A[i] > ret)
				{
					sum += ret;
				}
				else
				{
					sum += A[i];
				}
			}
			tar -= sum;
			//cout << "sum = " << sum << endl;
			assert(tar < 1.0e-8);
		}
	}
#endif
}
#pragma endregion Test
