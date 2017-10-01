// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Item
	{
		int weight, value;
	};

	// Returns the optimum value when we choose from items[0, chosenItems] and have a
	// capacity of availableCapacity.
	int OptimumSubjectToItemAndCapacity(const vector<Item>& items, int chosenItems, int availableCapacity, vector<vector<int>>& v)
	{
		if (chosenItems < 0)
			return 0; // No items can be chosen.

		if (v[chosenItems][availableCapacity] == -1)
		{
			int withoutItem = OptimumSubjectToItemAndCapacity(items, chosenItems - 1, availableCapacity, v);
			int withItem = availableCapacity < items[chosenItems].weight ? 0 : items[chosenItems].value + OptimumSubjectToItemAndCapacity(items, chosenItems - 1, availableCapacity - items[chosenItems].weight, v);
			v[chosenItems][availableCapacity] = max(withoutItem, withItem);
		}
		return v[chosenItems][availableCapacity];
	}

	int OptimumSubjecToCapacity(const vector<Item>& items, int capacity)
	{
		// V[i][j] holds the optimum value when we choose from items[0, i] and have a capacity of j.
		vector<vector<int>> v(items.size(), vector<int>(capacity + 1, -1));
		return OptimumSubjectToItemAndCapacity(items, items.size() - 1, capacity, v);
	}
}
