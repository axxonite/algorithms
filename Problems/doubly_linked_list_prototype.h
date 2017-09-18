#pragma once

#include <memory>

using namespace std;

template <typename T>
struct ListNode 
{
  T data;
  shared_ptr<ListNode<T>> prev, next;
};