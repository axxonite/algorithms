#include "stdafx.h"

struct Foo
{
	int a;
	int b;
};

void function()
{
	vector<int> src, dest;
	dest.insert(src.begin(), src.end(), dest.end());
} 