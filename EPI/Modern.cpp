#include "stdafx.h"

int value = 40;
int& ReturnReference()
{
  return value;
}

int ReturnValue()
{
  return value;
}

void Overload(int& x)
{
}

void Overload(int&& x)
{
}

template <class T>
void SwapByMove(T& a, T& b )
{
   T tmp(std::move(a));
   a = std::move(b);
   b = std::move(tmp);
}

template <class T>
void SwapByCopy(T& a, T& b)
{
  T tmp(a);
  a = b;
  b = tmp;
}
class BaseObject
{
protected:
  BaseObject()
  {
  }

  BaseObject(const BaseObject& rhs )
  {
  }

  BaseObject(BaseObject&& rhs) noexcept
  {
  }
};

class LargeObject : BaseObject
{
public :
  int* data;
  const int Size = 1024;

  LargeObject()
  {
    data = new int[Size];
  }

  LargeObject( LargeObject const & rhs) : BaseObject(rhs)
  {
    data = new int[Size];
    memcpy(data, rhs.data, Size * sizeof(int));
  }

  LargeObject(LargeObject&& rhs) noexcept : 
    BaseObject( std::move(rhs) )
  {
    data = rhs.data;
    rhs.data = nullptr;
  }

  ~LargeObject()
  {
    delete[] data;
  }

  void operator = (const LargeObject& rhs )
  {
    memcpy(data, rhs.data, Size * sizeof(int));  
  }

  void operator = (LargeObject&& rhs ) noexcept
  {
    swap( data, rhs.data);
    rhs.data = nullptr;
  }
};

template<typename T, typename Arg>
shared_ptr<T> factory(Arg&& arg)
{
  return shared_ptr<T>(new T(std::forward<Arg>(arg)));
}

template <typename First, typename... Args> // Args is a parameter pack - what if we have two?
auto sum (const First first, const Args... args ) -> decltype (first) // explicit type for the return value.
{
  const vector<int> values = {first, args...};
  return std::accumulate(values.begin(), values.end(), First{0});
}

bool TestModern()
{
  ReturnReference() = 42;
  //int&& test = ReturnReference();
  // ReturnValue() = 42;
  int&& test = ReturnValue();
  LargeObject a;
  LargeObject b;
  a.data[0] = 0;
  b.data[0] = 1;

  auto s = sum(1, 2, 3, 4, 5);


  factory<LargeObject>(LargeObject());
  factory<LargeObject>(a);
  //SwapByCopy(a, b);
  SwapByMove(a, b); // assembly shows no copies.
  return a.data[1] == 42;
}