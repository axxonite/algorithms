// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int NumCombinationsForFinalScore(int finalScore, const vector<int>& scores)
{
	return 0;
}

#pragma region Test

void NumCombinationsForFinalScoreSimpleTest()
{
	const vector<int> individual_play_scores = { 2, 3, 7 };
	assert(4 == NumCombinationsForFinalScore(12, individual_play_scores));
	assert(1 == NumCombinationsForFinalScore(5, individual_play_scores));
	assert(3 == NumCombinationsForFinalScore(9, individual_play_scores));
}

int CheckAnswer(int total_score, const vector<int>& score_ways)
{
	vector<int> combinations(size_t(total_score) + 1, 0);
	combinations[0] = 1; // One way to reach 0.
	for (int score : score_ways)
	{
		for (int j = score; j <= total_score; ++j)
			combinations[j] += combinations[size_t(j) - score];
	}
	return combinations[total_score];
}

void NumCombinationsForFinalScoreTest()
{
#ifdef TEST
	NumCombinationsForFinalScoreSimpleTest();
	default_random_engine gen((random_device())());
	vector<int> individual_play_scores;
	const uniform_int_distribution<int> k_dis(0, 999);
	const int k = k_dis(gen);
	const uniform_int_distribution<int> size_dis(1, 50);
	individual_play_scores.resize(size_dis(gen));
	for (int& individual_play_score : individual_play_scores)
	{
		uniform_int_distribution<int> score_dis(1, 1000);
		individual_play_score = score_dis(gen);
	}

	// cout << NumCombinationsForFinalScore(k, scores) << endl;
	assert(NumCombinationsForFinalScore(k, individual_play_scores) == CheckAnswer(k, individual_play_scores));
#endif
}

#pragma endregion Test
