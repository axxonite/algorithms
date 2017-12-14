// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "9.1_stack_with_max_solution.h"

namespace Solutions
{
	bool Stack::Empty() const { return element_.empty(); }

	int Stack::Max() const
	{
		if (Empty())
			// DO NOT put in a new here.
			throw length_error("Max(): empty stack");
		return cached_max_with_count_.top().max;
	}

	int Stack::Pop()
	{
		if (Empty())
			// DO NOT put in a new here.
			throw length_error("Pop(): empty stack");
		int pop_element = element_.top();
		element_.pop();
		const int current_max = cached_max_with_count_.top().max;
		if (pop_element == current_max)
		{
			int& max_frequency = cached_max_with_count_.top().count;
			--max_frequency;
			if (max_frequency == 0)
			{
				cached_max_with_count_.pop();
			}
		}
		return pop_element;
	}

	void Stack::Push(int x)
	{
		element_.emplace(x);
		if (cached_max_with_count_.empty())
			cached_max_with_count_.emplace(MaxWithCount{x, 1});
		else
		{
			const int current_max = cached_max_with_count_.top().max;
			if (x == current_max)
			{
				int& max_frequency = cached_max_with_count_.top().count;
				++max_frequency;
			}
			else if (x > current_max)
				cached_max_with_count_.emplace(MaxWithCount{x, 1});
		}
	}
	
}
