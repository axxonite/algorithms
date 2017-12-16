#pragma region Includes
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#pragma endregion

using namespace std;

namespace BricksGame
{
	long long SolveDP(vector<int>& A, int n, vector<long long>& dp)
	{
		if (n >= A.size())
			return 0;
		if (dp[n] == -1)
		{
			long long score1 = A[n] + min({SolveDP(A, n + 2, dp), SolveDP(A, n + 3, dp), SolveDP(A, n + 4, dp)});
			long long score2 = n < A.size() - 1 ? A[n] + A[n + 1] + min({SolveDP(A, n + 3, dp), SolveDP(A, n + 4, dp), SolveDP(A, n + 5, dp)}) : 0;
			long long score3 = n < A.size() - 2 ? A[n] + A[n + 1] + A[n + 2] + min({SolveDP(A, n + 4, dp), SolveDP(A, n + 5, dp), SolveDP(A, n + 6, dp)}) : 0;
			dp[n] = max({score1, score2, score3});
		}
		return dp[n];
	}

	long long Solve(vector<int>& A)
	{
		vector<long long> dp(A.size(), -1);
		auto result = SolveDP(A, 0, dp);
		return result;
	}

	void Run(istream& in, ostream& out)
	{
		int t;
		in >> t;
		for (int i = 0; i < t; ++i)
		{
			int n, x;
			in >> n;
			vector<int> a(n);
			for (int j = 0; j < n; ++j)
			{
				in >> x;
				a[j] = x;
			}

			auto result = Solve(a);
			out << result << endl;
		}
	}
}

int main4()
{
	BricksGame::Run(cin, cout);
	return 0;
}

// ----- TEST -----
void BricksGameTest()
{
	const char* testCase = R"(
2
5
999 1 1 1 0
5
0 1 1 1 999
)";

	istringstream in(testCase);
	ostringstream out;
	BricksGame::Run(in, out);
}
