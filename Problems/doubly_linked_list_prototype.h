#pragma once

#include <memory>

using namespace std;

template <typename T>
struct ListNodeDbl 
{
  T data;
  shared_ptr<ListNodeDbl<T>> prev, next;
};