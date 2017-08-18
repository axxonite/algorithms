// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#pragma once

#include <stack>

using namespace std;

class Stack
{
public:
	bool Empty() const;
	int Max() const;
	int Pop();
	void Push(int x);

private:
	stack<int> elements;
	struct MaxWithCount
	{
		int max, count;
	};
	stack<MaxWithCount> maxes;
}; 