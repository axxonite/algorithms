#include <string>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

struct MulticoreProcessingEasy
{
	int fastestTime(int jobLength, int corePenalty, vector <int> speed, vector <int> cores)
	{
		int best = numeric_limits<int>::max();
		for (int i = 0; i < speed.size(); ++i)
			for (int j = 1; j < cores.size(); ++j)
				best = min(best, jobLength / (j * speed[i]) + (j - 1) * corePenalty);
		return best;
	}
};

void TestProblem()
{
	//MulticoreProcessingEasy object;
	//int test = object.longest(2, 1, 0);
}
