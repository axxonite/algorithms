#include "stdafx.h"

namespace Solutions 
{
	void InsertionSort(vector<int>& a)
	{
		// Skip first value.
		for (auto i = 1; i < a.size(); i++)
		{
			auto key = a[i];
			// Insert into sorted sequence. We have to insert somewhere before i.
			int j;
			for (j = i - 1; j >= 0 && a[j] > key; --j)
				a[j + 1] = a[j]; // Push values forward until the insertion point is <= key
			a[j + 1] = key;
		}
	}
}

#pragma endregion Test