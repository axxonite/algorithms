#pragma once
#include <memory>

using namespace std;

template <class T>
struct TreeNode
{
	T value;
	shared_ptr<TreeNode<T>> left;
	shared_ptr<TreeNode<T>> right;
};

typedef shared_ptr<TreeNode<int>> TreeNodePtr;