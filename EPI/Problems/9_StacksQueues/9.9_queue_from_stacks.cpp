// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

class QueueWithStacks
{
public:
	void Enqueue(int x) { }

	int Dequeue()
	{
		return 0;
	}

private:
};

#pragma region Test

void QueueTest()
{
#if TEST
	QueueWithStacks Q;
	Q.Enqueue(1);
	Q.Enqueue(2);
	assert(1 == Q.Dequeue());
	assert(2 == Q.Dequeue());
	Q.Enqueue(3);
	assert(3 == Q.Dequeue());
	try
	{
		Q.Dequeue();
		assert(false);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	Q.Enqueue(-1);
	Q.Enqueue(123);
	Q.Enqueue(numeric_limits<int>::max());
	Q.Enqueue(numeric_limits<int>::min());
	Q.Enqueue(0);
	assert(-1 == Q.Dequeue());
	Q.Enqueue(0);
	assert(123 == Q.Dequeue());
	assert(numeric_limits<int>::max() == Q.Dequeue());
	assert(numeric_limits<int>::min() == Q.Dequeue());
	assert(0 == Q.Dequeue());
	assert(0 == Q.Dequeue());
	try
	{
		Q.Dequeue();
		assert(false);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
#endif
}

#pragma endregion Test
