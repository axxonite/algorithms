// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	class QueueWithStacks
	{
	public:
		void Enqueue(int x) { enqueue.emplace(x); }

		int Dequeue()
		{
			if (dequeue.empty())
			{
				// Transfers the elements in enqueue to dequeue.
				while (!enqueue.empty())
				{
					dequeue.emplace(enqueue.top());
					enqueue.pop();
				}
			}

			if (dequeue.empty())
				throw length_error("empty queue"); // dequeue is still empty!
			int ret = dequeue.top();
			dequeue.pop();
			return ret;
		}

	private:
		stack<int> enqueue, dequeue;
	};
}
