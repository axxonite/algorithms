#include "stdafx.h"

namespace Solutions
{
	void CountingSort(vector<int>& a, int maxValue)
	{
		vector<int> counts(maxValue + 1);
		for (int i = 0; i < a.size(); i++)
			counts[a[i]]++;
		int k = 0;
		for (int i = 0; i < counts.size(); ++i)
			for (int j = 0; j < counts[i]; ++j)
				a[k++] = i;
	}
}