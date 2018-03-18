// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Name
	{
		bool operator==(const Name& that) const
		{
			return first_name == that.first_name;
		}

		bool operator<(const Name& that) const
		{
			return first_name != that.first_name ? first_name < that.first_name : last_name < that.last_name;
		}

		string first_name, last_name;
	};

	void EliminateDuplicate(vector<Name>& a)
	{
		sort(a.begin(), a.end());
		for (int i = 1; i < a.size(); ++i)
		{
			if (a[i].first_name == a[i - 1].first_name)
				a.erase(a.begin() + i), --i;
		}
	}
}
