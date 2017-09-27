// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	static int num_steps = 0;
	const int kNumPegs = 3;

	void ComputeTowerHanoiSteps(int ringsToMove, array<stack<int>, kNumPegs>& pegs, int fromPeg, int toPeg, int usePeg)
	{
		if (ringsToMove > 0)
		{
			ComputeTowerHanoiSteps(ringsToMove - 1, pegs, fromPeg, usePeg, toPeg);
			pegs[toPeg].push(pegs[fromPeg].top());
			pegs[fromPeg].pop();
			num_steps++;
			ComputeTowerHanoiSteps(ringsToMove - 1, pegs, usePeg, toPeg, fromPeg);
		}
	}

	void ComputeTowerHanoi(int num_rings)
	{
		array<stack<int>, kNumPegs> pegs;
		for (int i = num_rings; i >= 1; --i)
			pegs[0].push(i);
		ComputeTowerHanoiSteps(num_rings, pegs, 0, 1, 2);
	}
	
}
