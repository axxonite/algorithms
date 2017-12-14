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

using namespace std;

int FindBest(vector<int>& a, int left, int right, vector<vector<int>>& dp)
{
	if (dp[left][right] == -1)
	{
		if (right == left)
			return 0;
		if (right - left == 1)
			return a[left];
		int best = 0;
		for ( int i = left + 1; i < right; ++i)
			best = max(best, FindBest(a, left, i, dp) + FindBest(a, i + 1, right, dp));
		dp[left][right] = best;
	}
	return dp[left][right];
}

int main3() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n, x;
		cin >> n;
		vector<int> a(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> x;
			a[j] = x;
		}

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
		int result = FindBest(a, 0, a.size(), dp);
		cout << result;
	}
	return 0;
}
