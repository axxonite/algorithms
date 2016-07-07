#pragma once
#include <memory>

template <class T>
struct Node
{
	T value;
	Node* next;
};

typedef std::shared_ptr<Node<int>> NodePtr;