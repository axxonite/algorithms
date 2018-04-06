// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#pragma once

#include <memory>

template <typename T>
struct BSTNode
{
	T data;
	std::unique_ptr<BSTNode<T>> left, right;
}; 

template <typename T>
struct BSTNodeShared
{
	T data;
	std::shared_ptr<BSTNodeShared<T>> left, right;
};