// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "9.1_stack_with_max_solution.h"

namespace Solutions
{
	class QueueWithMax
	{
	public:
		void Enqueue(int x) { enqueue_.Push(x); }

		int Dequeue()
		{
			if (dequeue_.Empty())
			{
				while (!enqueue_.Empty())
					dequeue_.Push(enqueue_.Pop());
			}
			if (!dequeue_.Empty())
				return dequeue_.Pop();
			throw length_error("empty queue");
		}

		int Max() const
		{
			if (!enqueue_.Empty())
				return dequeue_.Empty() ? enqueue_.Max() : max(enqueue_.Max(), dequeue_.Max());
			if (!dequeue_.Empty())
				return dequeue_.Max();
			throw length_error("empty queue");
		}

	private:
		Solutions::Stack enqueue_, dequeue_;
	};
}
