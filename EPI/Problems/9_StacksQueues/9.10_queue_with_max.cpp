// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Solutions/9_StacksQueues/9.1_stack_with_max_solution.h"

#define TEST 0

class QueueWithMax 
{
public:
	void Enqueue(int x)
	{
	}

	int Dequeue() 
	{
		return 0;
	}

	int Max() const 
	{
		return 0;
	}

private:

	// Don't forget to remove the private variables when re-initializing the problem.
};

#pragma region Test

void SimpleTestQueueWithMax() {
	QueueWithMax Q;
	Q.Enqueue(11);
	Q.Enqueue(2);
	assert(11 == Q.Max());
	assert(11 == Q.Dequeue());
	assert(2 == Q.Max());
	assert(2 == Q.Dequeue());
	Q.Enqueue(3);
	assert(3 == Q.Max());
	assert(3 == Q.Dequeue());
	Q.Enqueue(numeric_limits<int>::max() - 1);
	Q.Enqueue(numeric_limits<int>::max());
	Q.Enqueue(-2);
	Q.Enqueue(-1);
	Q.Enqueue(-1);
	Q.Enqueue(numeric_limits<int>::min());
	assert(numeric_limits<int>::max() == Q.Max());
	assert(numeric_limits<int>::max() - 1 == Q.Dequeue());
	assert(numeric_limits<int>::max() == Q.Max());
	assert(numeric_limits<int>::max() == Q.Dequeue());
	assert(-1 == Q.Max());
	assert(-2 == Q.Dequeue());
	assert(-1 == Q.Max());
	assert(-1 == Q.Dequeue());
	assert(-1 == Q.Dequeue());
	assert(numeric_limits<int>::min() == Q.Max());
	assert(numeric_limits<int>::min() == Q.Dequeue());
	try {
		cout << "Q is empty, Max() call should except = " << Q.Max();
		assert(false);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

void QueueWithMaxTest() {
#if TEST
	SimpleTestQueueWithMax();
	QueueWithMax Q;
	Q.Enqueue(1);
	Q.Enqueue(2);
	assert(2 == Q.Max());
	assert(1 == Q.Dequeue());
	assert(2 == Q.Max());
	assert(2 == Q.Dequeue());
	Q.Enqueue(3);
	assert(3 == Q.Max());
	assert(3 == Q.Dequeue());
	try {
		Q.Max();
		assert(false);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	try {
		Q.Dequeue();
		assert(false);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
#endif
}

#pragma endregion Test