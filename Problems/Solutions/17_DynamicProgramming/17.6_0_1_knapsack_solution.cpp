// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Item
	{
		int weight, value;
	};

	// Returns the optimum value when we choose from items[0, k] and have a
	// capacity of availableCapacity.
	int OptimumSubjectToItemAndCapacity(const vector<Item>& items, int k, int availableCapacity, vector<vector<int>>& v)
	{
		if (k < 0)
			return 0; // No items can be chosen.

		if (v[k][availableCapacity] == -1)
		{
			int withoutCurrItem = OptimumSubjectToItemAndCapacity(items, k - 1, availableCapacity, v);
			int withCurrItem = availableCapacity < items[k].weight ? 0 : items[k].value + OptimumSubjectToItemAndCapacity(items, k - 1, availableCapacity - items[k].weight, v);
			v[k][availableCapacity] = max(withoutCurrItem, withCurrItem);
		}
		return v[k][availableCapacity];
	}

	int OptimumSubjecToCapacity(const vector<Item>& items, int capacity)
	{
		// V[i][j] holds the optimum value when we choose from items[0, i] and have a capacity of j.
		vector<vector<int>> v(items.size(), vector<int>(capacity + 1, -1));
		return OptimumSubjectToItemAndCapacity(items, items.size() - 1, capacity, v);
	}
}
