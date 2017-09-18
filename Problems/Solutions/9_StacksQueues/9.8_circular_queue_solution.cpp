// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	class Queue
	{
	public:
		explicit Queue(size_t capacity) : _entries(capacity)
		{
		}

		void Enqueue(int x)
		{
			if (_elementCount == _entries.size())
			{
				// Needs to resize.
				// Makes the queue elements appear consecutively.
				rotate(_entries.begin(), _entries.begin() + _head, _entries.end());
				_head = 0, _tail = _elementCount; // Resets head and tail.
				_entries.resize(_entries.size() * kScaleFactor);
			}

			_entries[_tail] = x;
			_tail = (_tail + 1) % _entries.size(), ++_elementCount;
		}

		int Dequeue()
		{
			if (!_elementCount)
				throw length_error("empty queue");
			--_elementCount;
			int ret = _entries[_head];
			_head = (_head + 1) % _entries.size();
			return ret;
		}

		size_t size() const { return _elementCount; }

	private:
		const int kScaleFactor = 2;
		size_t _head = 0, _tail = 0, _elementCount = 0;
		vector<int> _entries;
	};
}
