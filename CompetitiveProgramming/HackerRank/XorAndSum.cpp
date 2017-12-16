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

namespace XorAndSum
{
	int Solve(unsigned int a, unsigned int b)
	{
		unsigned long long sum = 0;
		for (int i = 0; i < 32; ++i)
			sum += a ^ (b << i);
		for (int i = 32; i < 314159; ++i)
			sum += a;
		//sum += long long(314159 - 32) * a;
		sum = sum % (1000000000 + 7);
		return sum;
	}

	void Run(istream& in, ostream& out)
	{
		char x;
		int a = 0, b = 0;
		string token;
		getline(in, token, '\n');
		for (auto c: token)
			a = (a << 1) | (c - '0');
		getline(in, token, '\n');
		for (auto c : token)
			b = (b << 1) | (c - '0');

		auto result = Solve(a, b);
		out << result << endl;
	}
}

int main8()
{
	XorAndSum::Run(cin, cout);
	return 0;
}

// ----- TEST -----
void XorAndSumTest()
{
	const char* testCase = R"(10
1010
)";

	istringstream in(testCase);
	ostringstream out;
	XorAndSum::Run(in, out);
}
