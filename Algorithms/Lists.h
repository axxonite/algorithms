#pragma once
#include <memory>

using namespace std;

template <class T>
struct Node
{
	T value;
	shared_ptr<Node<int>> next;
};

typedef shared_ptr<Node<int>> NodePtr;

void TestLists();