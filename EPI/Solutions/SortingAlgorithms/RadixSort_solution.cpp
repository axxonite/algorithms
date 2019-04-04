#include "stdafx.h"

namespace Solutions
{
	vector<int> RadixSort(vector<int> values, int maxDigits)
	{
		vector<int> result(values.size());
		auto divider = 1;
		for (auto d = 0; d < maxDigits; d++)
		{
			vector<int> counts(11);
			for (auto i = 0; i < values.size(); i++)
				counts[(values[i] / divider) % 10]++;
			for (auto i = 1; i < counts.size(); i++)
				counts[i] = counts[i] + counts[i - 1];
			// counts now contains the number of elements less than or equal to i for each possible value.
			for (int i = values.size() - 1; i >= 0; i--)
			{
				auto digit = (values[i] / divider) % 10;
				result[counts[digit] - 1] = values[i]; // Subtract one, because when there is only one occurrence of the lowest value left, it must be inserted at position 0.
				counts[digit]--;
			}
			values = result;
			divider *= 10;
		}
		return result;
	}
}