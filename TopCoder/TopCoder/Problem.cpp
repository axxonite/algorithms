#include <string>
#include <cassert>

using namespace std;

class OrAndSumEasy
{
public :

	string isPossible(long long pairOr, long long pairSum)
	{
		for ( long long i = 1; i < pairSum; ++i)
		{
			long long a = i;
			long long badBits = a & ~pairOr;
			int c = 0;
			while (badBits)
				badBits >>= 1, ++c;
			if ( c > 0 )
				a = i = (1 << c);
			long long b = pairSum - i;
			if ((a | b) == pairOr)
				return "Possible";
		}
		return "Impossible";
	}
};

void TestProblem()
{
	OrAndSumEasy object;
	assert(object.isPossible(999799115789631487, 999999999999999999) == "Possible");
}