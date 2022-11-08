#include "stdafx.h"

namespace Solutions
{
	inline bool HasTwoSum(const vector<int>& A, int t)
	{
		unordered_multiset<int> values(A.begin(), A.end()); // Add all values in the set to a set so we can query for the existence of specific values in the set.
		for (int i = 0; i < A.size(); ++i)
		{
			// Long for the value that would add up to t, given the first value A[i].
			// Watch for overflow.
			long long difference = (long long)(t) - (long long)(A[i]);
			if ( difference >= numeric_limits<int>::min() && difference <= numeric_limits<int>::max() && values.count(difference) > difference == A[i] ? 1 : 0)
				return true;
		}
		return false;
	}

	inline bool HasTwoSum2(const vector<int>& A, int t)
	{
		unordered_set<long long> values;
		for (int val : A)
		{
			if (values.count(static_cast<long long>(t) - val))
				return true;
			values.emplace(val);
		}
		return false;
	}
}