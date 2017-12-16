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

tuple<long long, long long> Solve(vector<long long>& A)
{
	vector<long long> sum(A.size(), 0);
	long long longestS = 0, maxVal = numeric_limits<long long>::min(), count = 0;
	sum[0] = A[0];
	for ( int i = 0; i < A.size(); ++i)
	{
		if (A[i] > 0)
			longestS += A[i], ++count;
		maxVal = max(maxVal, A[i]);
		if ( i > 0 )
			sum[i] = max(sum[i - 1] + A[i], A[i]);

	}
	if (count == 0)
		longestS = maxVal;
	return { *max_element(sum.begin(), sum.end()), longestS };
}

void Run(istream& in, ostream& out)
{
	int t;
	in >> t;
	for (int i = 0; i < t; ++i)
	{
		int n, x;
		in >> n;
		vector<long long> a(n);
		for (int j = 0; j < n; ++j)
		{
			in >> x;
			a[j] = x;
		}

		auto result = Solve(a);
		out << get<0>(result) << " " << get<1>(result) << endl;
	}
}

//int main() 
//{
//	Run(cin, cout);
//	return 0;
//}

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