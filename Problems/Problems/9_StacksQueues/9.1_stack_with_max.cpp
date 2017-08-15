// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "9.1_stack_with_max.h"

#define TEST 0

bool Stack::Empty() const
{
	return false;
}

int Stack::Max() const
{
	return 0;
}

int Stack::Pop()
{
	return 0;
}

void Stack::Push(int x)
{
}

#pragma region Test
void StackTest()
{
#if TEST
  	Stack s;
	s.Push(1);
	s.Push(2);
	assert(s.Max() == 2);
	cout << s.Max() << endl; // 2
	cout << s.Pop() << endl; // 2
	assert(s.Max() == 1);
	cout << s.Max() << endl; // 1
	s.Push(3);
	s.Push(2);
	assert(s.Max() == 3);
	cout << s.Max() << endl; // 3
	s.Pop();
	assert(s.Max() == 3);
	cout << s.Max() << endl; // 3
	s.Pop();
	assert(s.Max() == 1);
	cout << s.Max() << endl; // 1
	s.Pop();
	try
	{
		s.Max();
		s.Pop();
		s.Pop();
		s.Pop();
		s.Pop();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
#endif

}

#pragma endregion Test
