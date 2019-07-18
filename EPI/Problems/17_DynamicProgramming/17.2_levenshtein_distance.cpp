// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "shared.h"

// #define TEST

int LevenshteinDistance(const string& A, const string& B)
{
  return 0;
  }

#pragma region Test

int CheckAnswer(string A, string B)
{
	// Try to reduce the space usage.
	if (A.size() < B.size())
	{
		swap(A, B);
	}

	vector<int> D(B.size() + 1);
	// Initialization.
	iota(D.begin(), D.end(), 0);

	for (int i = 1; i <= A.size(); ++i)
	{
		int pre_i_1_j_1 = D[0]; // Stores the value of D[i - 1][j - 1].
		D[0] = i;
		for (int j = 1; j <= B.size(); ++j)
		{
			int pre_i_1_j = D[j]; // Stores the value of D[i -1][j].
			D[j] = A[i - 1] == B[j - 1] ? pre_i_1_j_1
				: 1 + min({pre_i_1_j_1, D[j - 1], D[j]});
			// Previous D[i - 1][j] will become the next D[i - 1][j - 1].
			pre_i_1_j_1 = pre_i_1_j;
		}
	}
	return D.back();
}

void LevenshteinDistanceTest()
{
#ifdef TEST
	default_random_engine gen((random_device())());
	string A, B;
	// Wiki example (http://en.wikipedia.org/wiki/Levenshtein_distance)
	A = "k" , B = "sitt";
	assert(4 == LevenshteinDistance(A, B));
	A = "Saturday" , B = "Sunday";
	assert(3 == LevenshteinDistance(A, B));
	A = "kitten" , B = "sitting";
	assert(3 == LevenshteinDistance(A, B));

	uniform_int_distribution<int> dis(1, 100);
	A = RandString(dis(gen));
	B = RandString(dis(gen));
	cout << A << endl << B << endl;
	cout << LevenshteinDistance(A, B) << endl;
	assert(LevenshteinDistance(A, B) == CheckAnswer(A, B));
#endif
}

#pragma endregion Test
