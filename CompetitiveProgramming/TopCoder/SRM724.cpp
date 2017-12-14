#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Division 1

// 90% success rate
struct GravityPuzzleEasy
{
	vector <string> solve(vector <string> board)
	{
		for (int i = 0; i < board[0].size(); ++i)
		{
			int dst = board.size() - 1;
			for (int j = board.size() - 1; j >= 0; --j)
			{
				if (board[j][i] == '#')
				{
					board[j][i] = '.';
					board[dst--][i] = '#';
				}
			}
		}
		return board;
	}
};

// 47% success rate
// This is based on working out a truth table for all possible bit values of a, b, a carry, pairOr and pairSum.
// This ultimately leads to the finding that there is only one value a that could meet both conditions, and this
// value will always equal to pairOr.
struct OrAndSumEasy
{
	string isPossible(long long pairOr, long long pairSum)
	{
		long long a = pairOr, b = pairSum - a;
		if ((a | b) == pairOr)
			return "Possible";
		return "Impossible";
	}
};

// 6% success rate. Too hard.
struct UnfinishedTournamentEasy
{
	double maximal(vector <string> G)
	{
		return 0;
	}
};


struct Tuple
{
	long long a, b;
};
struct OrAndSum
{
	void findValues(long long pairOr, long long pairSum, long long index, long long a, long long b, int c, vector<Tuple>& values)
	{
		if (index == 64)
		{
			if (c == 0)
				values.emplace_back(Tuple{ a, b });
			return;
		}
		long long mpo = (pairOr >> index) & 1, mps = (pairSum >> index) & 1, bit = 1ULL << index;

		if (!mps && !mpo)
		{
			if (c)
				return;
			findValues(pairOr, pairSum, index + 1, a, b, 0, values);
		}
		else if (!mps && mpo)
		{
			if (c)
			{
				findValues(pairOr, pairSum, index + 1, a | bit, b, 1, values);
				findValues(pairOr, pairSum, index + 1, a, b | bit, 1, values);
			}
			else findValues(pairOr, pairSum, index + 1, a | bit, b | bit, 1, values);
		}
		else if (mps && !mpo)
		{
			if (!c)
				return;
			findValues(pairOr, pairSum, index + 1, a, b, 0, values);
		}
		else if (mps && mpo)
		{
			if (!c)
			{
				findValues(pairOr, pairSum, index + 1, a | bit, b, 0, values);
				findValues(pairOr, pairSum, index + 1, a, b | bit, 0, values);
			}
			else findValues(pairOr, pairSum, index + 1, a | bit, b | bit, 1, values);
		}
	}

	bool isPossible(vector<long long> pairOr, vector<long long> pairSum, int index, long long last, bool first)
	{
		if (index == pairOr.size())
			return true;
		// Find all values, and see if we can chain the values together.
		vector<Tuple> values;
		findValues(pairOr[index], pairSum[index], 0, 0, 0, 0, values);
		//for (int i = 0; i < values.size(); ++i)
		//{
		//	//set.emplace(values[i].a);
		//	//assert(values[i].a + values[i].b == pairSum[index]);
		//	//assert(values[i].a | values[i].b == pairOr[index]);
		//}
		for (int i = 0; i < values.size(); ++i)
		{
			if ((first || values[i].a == last) && isPossible(pairOr, pairSum, index + 1, values[i].b, false))
				return true;
		}
		return false;
	}


	string isPossible(vector<long long> pairOr, vector<long long> pairSum)
	{
		return isPossible(pairOr, pairSum, 0, 0, true) ? "Possible" : "Impossible";
	}
};

void TestSRM724()
{
	GravityPuzzleEasy object;
	auto test = object.solve({"#", ".", "."});
	OrAndSum orAndSum;
	auto test3 = orAndSum.isPossible({ 3 }, { 3});
	auto test2 = orAndSum.isPossible({ 3, 3,7, 5,7 }, { 3,5, 7, 9, 11 });
	auto test4 = orAndSum.isPossible({ 261208776456074191, 261208776456074191, 261208776456074191 }, { 333333333333333333, 333333333333333333, 333333333333333333 });
}
