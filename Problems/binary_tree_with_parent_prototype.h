#pragma once

template <typename T>
struct BinaryTreeNodeP
{
	T data;
	unique_ptr<BinaryTreeNodeP<T>> left, right;
	BinaryTreeNodeP<T>* parent;
};