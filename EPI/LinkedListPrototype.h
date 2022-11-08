// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#pragma once

#include <memory>

using namespace std;

template <typename T>
struct ListNode
{
	T data;
	shared_ptr<ListNode<T>> next;
};