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

int f(int n)
{
	int result = n / 5;
	n %= 5;
	result += n / 2;
	n %= 2;
	return result + n;
}

int main2() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n, x;
		vector<int> a;
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			cin >> x;
			a.emplace_back(x);
		}

		// Find the minimum value.
		int m = numeric_limits<int>::max();
		for (int c : a)
			m = min(m, c);

		int best = numeric_limits<int>::max();
		for (int j = 0; j < 4; ++j)
		{
			// Find how many to remove from each candidate to reach the minimum.
			int s = 0;
			for (int c : a)
				s += f(c - m + j); // Add i to see if we get a quicker result from using a different baseline.
			best = min(best, s);
		}
		cout << best << std::endl;
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
