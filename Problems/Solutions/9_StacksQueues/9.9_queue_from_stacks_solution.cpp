// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	class QueueWithStacks
	{
	public:
		void Enqueue(int x) { enqueue_.emplace(x); }

		int Dequeue()
		{
			if (dequeue_.empty())
			{
				// Transfers the elements in enqueue_ to dequeue_.
				while (!enqueue_.empty())
				{
					dequeue_.emplace(enqueue_.top());
					enqueue_.pop();
				}
			}

			if (dequeue_.empty())
				throw length_error("empty queue"); // dequeue_ is still empty!
			int ret = dequeue_.top();
			dequeue_.pop();
			return ret;
		}

	private:
		stack<int> enqueue_, dequeue_;
	};
}
