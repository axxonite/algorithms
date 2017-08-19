#include "stdafx.h"

struct Foo
{
	int a;
	int b;
};

void function()
{
	auto lambda = [](int a) -> int { return a; };
} 