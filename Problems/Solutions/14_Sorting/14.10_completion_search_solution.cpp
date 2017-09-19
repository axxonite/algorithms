// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	double FindSalaryCap(double targetPayroll, vector<double> current_salaries)
	{
		sort(current_salaries.begin(), current_salaries.end());
		double unadjustedSalarySum = 0.0;
		for (int i = 0; i < current_salaries.size(); ++i)
		{
			const int adjustedPeople = current_salaries.size() - i;
			const double adjustedSalarySum = current_salaries[i] * adjustedPeople;
			if (unadjustedSalarySum + adjustedSalarySum >= targetPayroll)
				return (targetPayroll - unadjustedSalarySum) / adjustedPeople;
			unadjustedSalarySum += current_salaries[i];
		}
		// No solution, since targetPayroll > existing payroll.
		return -1.0;
	}
}
