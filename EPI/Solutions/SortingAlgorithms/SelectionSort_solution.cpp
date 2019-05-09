#include "stdafx.h"

namespace Solutions
{
	void SelectionSort(vector<int>& a)
	{
		for (size_t i = 0; i < a.size(); ++i)
		{
			int min = i;
			for (size_t j = i + 1; j < a.size(); ++j)
				if (a[j] < a[min])
					min = j;
			swap(a[i], a[min]);
		}
	}

	void SelectionSort2(vector<int>& a)
	{
		for (auto it = a.begin(); it != a.end(); ++it)
			iter_swap(it, min_element(it, a.end()));
	}
}

#pragma endregion Test