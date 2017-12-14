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

struct Best
{
	int seq, arr;
};

Best FindBest(vector<int>& a, int left, int right, vector<vector<Best>>& dp)
{
	if (dp[left][right].seq == -1)
	{
		if (right == left)
			return { 0, 0 };
		if (right - left == 1)
			return { a[left], a[left] };
		Best best = {0, 0};
		for (int i = left; i < right; ++i)
			best.seq += a[i];
		best.arr = best.seq;
		// subsequences
		for (int i = left + 1; i < right; ++i)
		{
			Best bestL = FindBest(a, left, i, dp);
			Best bestR = FindBest(a, i + 1, right, dp);
			best.seq = max(best.seq, bestL.seq + bestR.seq);
		}
		dp[left][right] = best;
	}
	return dp[left][right];
}

Best Solve(vector<int>& a)
{
	vector<vector<Best>> dp(a.size() + 1, vector<Best>(a.size() + 1, Best{ -1, -1 }));
	return FindBest(a, 0, int(a.size()), dp);
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

		Best result = Solve(a);
		out << result.arr << " " << result.seq << endl;
	}
}

int main3() 
{
	Run(cin, cout);
	return 0;
}

// ----- TEST -----
const char* testCase = R"(
2
4
1 2 3 4
6
2 -1 2 3 4 -5
)";

void MaximumSubarrayTest()
{
	istringstream in(testCase);
	ostringstream out;
	Run(in, out);
}