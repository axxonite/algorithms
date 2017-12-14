// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	static int numSteps = 0;
	const int kNumPegs = 3;

	void ComputeTowerHanoiSteps(int ringsToMove, array<stack<int>, kNumPegs>& pegs, int fromPeg, int toPeg, int usePeg)
	{
		if (ringsToMove > 0)
		{
			// Move n - 1 rings from FROM to USE through TO. Thus, we get access to the largest bottom ring on FROM while ensuring the TO peg has no rings on it.
			ComputeTowerHanoiSteps(ringsToMove - 1, pegs, fromPeg, usePeg, toPeg);
			// Move remaining ring on the FROM peg unto TO.
			pegs[toPeg].push(pegs[fromPeg].top());
			pegs[fromPeg].pop();
			numSteps++;
			// Move n - 1 rings from USE to TO through FROM. Now all the rings have been put on the TO peg.
			ComputeTowerHanoiSteps(ringsToMove - 1, pegs, usePeg, toPeg, fromPeg);
		}
	}

	void ComputeTowerHanoi(int ringCount)
	{
		array<stack<int>, kNumPegs> pegs;
		// Push the rings, starting from the largest, unto peg zero.
		for (int i = ringCount; i >= 1; --i)
			pegs[0].push(i);
		ComputeTowerHanoiSteps(ringCount, pegs, 0, 1, 2);
	}
	
}
