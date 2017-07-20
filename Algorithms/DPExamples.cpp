#include "stdafx.h"
#include "DPExamples.h"
#include <algorithm>
#include <math.h>

using namespace std;

int C[1];

int R(int a, int b)
{
	return min(C[a] + min(R(a + 1, b - 1), R(a + 2, b)), C[b] + min(R(a, b - 2),R(a + 1, b - 1)));
}


// O(n^2)
int BottomUpCutUpRod(vector<int> prices, int n, vector<int>& solution)
{
	vector<int> result(n + 1);
	vector<int> saved(n + 1);
	// Compute the solutions for 1..n, based on recurrent solutions saved in table.
	for (auto j = 1; j <= n; j++)
	{
		auto q = numeric_limits<int>::min();
		// Compute the solutions for 1..j. Think of a graph of solutions. where the solution for n=2, depends on the solution for n=1, the solution for n=3 depends on the solutions for n=1..2, and so forth.
		for (auto i = 1; i <= j; i++)
		{
			auto curPrice = prices[i] + saved[j - i];
			if (q < curPrice)
			{
				q = curPrice;
				result[j] = i;
			}
		}
		saved[j] = q;
	}
	solution = result;
	return saved[n];
}

int AssembleCutRodSolution(vector<int> prices, int n, vector<int>& finalSolution)
{
	vector<int> solution;
	auto result = BottomUpCutUpRod(prices, n, solution);
	while ( n > 0 )
	{
		finalSolution.push_back(solution[n]);
		n -= solution[n];
	}
	return result;
}

void TestBottomUpCutUpRod()
{
	vector<int> prices{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	vector<int> solution;
	auto result = AssembleCutRodSolution(prices, 4, solution);
	assert(result == 10);
	assert(solution[0] == 2);
	assert(solution[1] == 2);
}