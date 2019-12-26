// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	double FindSalaryCap(double targetPayroll, vector<double> currentSalaries)
	{
		sort(currentSalaries.begin(), currentSalaries.end());
		double uncappedPayroll = 0.0;
		for (int i = 0; i < currentSalaries.size(); ++i)
		{
			// start by adjusting everyone to the lowest salary, then adjust to the 2nd lowest, etc.
			double salaryCap = currentSalaries[i];
			const int peopleAtCap = currentSalaries.size() - i;
			const double cappedPayroll = salaryCap * peopleAtCap;
			if (uncappedPayroll + cappedPayroll >= targetPayroll)
				// above target payroll, divide remainder of target people between all adjusted people.
				return (targetPayroll - uncappedPayroll) / peopleAtCap;
			// we are still below target payroll, add the current salary to the unadjusted sum.
			uncappedPayroll += salaryCap;
		}
		// No solution, since targetPayroll > existing payroll.
		return -1.0;
	}

  double FindSalaryCap2(double targetPayroll, vector<double> salaries)
  {
    sort(salaries.begin(), salaries.end());
    double uncappedPayroll = 0.0;
    for (int i = 0; i < salaries.size(); ++i)
    {
      double cappedPay = (targetPayroll - uncappedPayroll) / (salaries.size() - i);
      if (cappedPay <= salaries[i])
        return cappedPay;
      uncappedPayroll += salaries[i];
    }
    return -1;
  }
}

