// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

class HeapStack 
{
public:
	void Push( int x ) 
	{
	}

	int Pop() 
	{
		return 0;
	}

	int Peek() const 
	{
		return 0;
	}

private:
};

class HeapQueue 
{
public:
	void Enqueue( int x ) 
	{
	}

	int Dequeue() 
	{
		return 0;
	}

	int Head() const 
	{ 
		return 0;
	}

private:
};


#pragma region Test

void StackQueueHeapTest()
{
#if TEST
	HeapStack s;
	s.Push( 1 );
	s.Push( 2 );
	s.Push( 3 );
	assert( s.Peek() == 3 );
	s.Pop();
	assert( s.Peek() == 2 );
	s.Pop();
	s.Push( 4 );
	assert( s.Peek() == 4 );
	s.Pop();
	s.Pop();
	try {
		s.Pop();
		assert( false );
	}
	catch ( const exception& e ) {
		cout << "empty stack" << endl;
		cout << e.what() << endl;
	}

	s.Push( 0 );
	s.Push( -1 );
	s.Push( numeric_limits<int>::max() );
	assert( s.Peek() == numeric_limits<int>::max() );
	s.Pop();
	assert( s.Peek() == -1 );
	s.Pop();
	assert( s.Peek() == 0 );
	s.Pop();
	try {
		s.Pop();
		assert( false );
	}
	catch ( const exception& e ) {
		cout << "empty stack" << endl;
		cout << e.what() << endl;
	}
	s.Push( 0 );
	assert( s.Peek() == 0 );

	HeapQueue q;
	q.Enqueue( 1 );
	q.Enqueue( 2 );
	assert( q.Head() == 1 );
	q.Dequeue();
	assert( q.Head() == 2 );
	q.Dequeue();
	try {
		q.Dequeue();
		assert( false );
	}
	catch ( const exception& e ) {
		cout << "empty queue" << endl;
		cout << e.what() << endl;
	}
#endif
}

#pragma endregion
