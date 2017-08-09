#include "stdafx.h"
#include <queue>
#include <functional> // for greater<>
#include <vector>
#include <random>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> a = { 10, 10, 10 };

struct Foo
{
	int a;
	int b;
};

void function()
{
	shared_ptr<Foo> ptr = make_shared<Foo>(Foo{ 0, 1 });
}