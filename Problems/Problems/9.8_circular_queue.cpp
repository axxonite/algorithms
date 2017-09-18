// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

class Queue
{
public:
	explicit Queue(size_t capacity)
	{
	}

	void Enqueue(int x)
	{
	}

	int Dequeue()
	{
		return 0;
	}

	size_t size() const { return 0; }

private:
};

#pragma region Test

void CircularQueueSimpleTest()
{
	Queue q(8);
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	q.Enqueue(6);
	q.Enqueue(7);
	q.Enqueue(8);
	// Now head = 0 and tail = 0

	assert(1 == q.Dequeue());
	assert(2 == q.Dequeue());
	assert(3 == q.Dequeue());
	// Now head = 3 and tail = 0

	q.Enqueue(11);
	q.Enqueue(12);
	q.Enqueue(13);
	// Ok till here. Now head = 3 and tail = 3

	q.Enqueue(14); // now the vector (data) is resized; but the head and tail.
	// (or elements) does not change accordingly.
	q.Enqueue(15);
	q.Enqueue(16);
	q.Enqueue(17);
	q.Enqueue(18);
	// The elements starting from head=3 are over-written!

	assert(4 == q.Dequeue());
	assert(5 == q.Dequeue());
	assert(6 == q.Dequeue());
	assert(7 == q.Dequeue());
	assert(8 == q.Dequeue());
	assert(11 == q.Dequeue());
	assert(12 == q.Dequeue());
}

void CircularQueueTest()
{
#if TEST
	CircularQueueSimpleTest();
	Queue q(8);
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	assert(1 == q.Dequeue());
	q.Enqueue(4);
	assert(2 == q.Dequeue());
	assert(3 == q.Dequeue());
	assert(4 == q.Dequeue());
	try
	{
		q.Dequeue();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	// test resize().
	q.Enqueue(4);
	q.Enqueue(4);
	q.Enqueue(4);
	q.Enqueue(4);
	q.Enqueue(4);
	q.Enqueue(4);
	q.Enqueue(4);
	q.Enqueue(4);
	q.Enqueue(4);
	assert(q.size() == 9);
#endif
}

#pragma endregion Test
