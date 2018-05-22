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
		int dst = 1;
		for (int i = 1; i < a.size(); ++i)
		{
			if (a[i].first_name != a[dst - 1].first_name)
				a[dst++] = a[i];
		}
		a.resize(dst);
	}
}
