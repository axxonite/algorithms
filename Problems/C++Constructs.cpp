#include "stdafx.h"

struct Foo
{
	int a;
	int b;
};

void function()
{
	auto p = make_shared<Foo>(Foo{ 0, 0 });
} 