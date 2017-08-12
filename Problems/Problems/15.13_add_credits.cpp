// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include <cassert>
#include <string>

using namespace std;

class ClientsCreditsInfo 
{
public:
	void Insert(const string& client_id, int c) 
	{
	}

	bool Remove(const string& client_id) 
	{
		return false;
	}

	int Lookup(const string& client_id) const 
	{
		return 0;
	}

	void AddAll(int C) {}

	string Max() const 
	{
		return "";
	}

private:
};

#pragma region Test

void AddCreditsTest() 
{
	ClientsCreditsInfo a;
	assert(a.Max() == "");
	assert(!a.Remove("foo"));
	a.Insert("foo", 10);
	a.Insert("foo", 1);
	a.Insert("bar", 2);
	a.AddAll(5);
	a.Insert("widget", 3);
	a.AddAll(5);
	a.Insert("dothis", 4);
	assert(11 == a.Lookup("foo"));
	assert(12 == a.Lookup("bar"));
	assert(8 == a.Lookup("widget"));
	assert(4 == a.Lookup("dothis"));
	assert(a.Remove("foo"));
	assert(-1 == a.Lookup("foo"));
	assert(a.Max().compare("bar") == 0);
	a.Insert("xyz", 13);
	assert(a.Max().compare("xyz") == 0);
	a.Insert("dd", 15);
	assert(a.Max().compare("dd") == 0);
}

#pragma endregion Test