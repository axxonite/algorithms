// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 1

string IntToString(int x)
{
	return to_string(x);
}

int StringToInt(const string& s)
{
	return stoi(s);
}

#pragma region Test

string RandIntString(int len)
{
	default_random_engine gen((random_device())());
	string ret;
	if (len == 0)
		return {"0"};
	uniform_int_distribution<int> pos_or_neg(0, 1);
	if (pos_or_neg(gen))
		ret.push_back('-');
	uniform_int_distribution<int> num_dis('1', '9');
	ret.push_back(num_dis(gen));
	while (--len)
	{
		uniform_int_distribution<int> dis('0', '9');
		ret.push_back(dis(gen));
	}
	return ret;
}

void DirectedTests()
{
	assert("0" == IntToString(0));
	assert("-1" == IntToString(-1));
	assert("1" == IntToString(1));
	assert("2" == IntToString(2));
	assert("-2" == IntToString(-2));
	assert("9" == IntToString(9));
	assert("10" == IntToString(10));
	assert("123" == IntToString(123));
	assert(to_string(numeric_limits<int>::max() - 1) == IntToString(numeric_limits<int>::max() - 1));
	assert(to_string(numeric_limits<int>::max()) == IntToString(numeric_limits<int>::max()));
	assert(to_string(numeric_limits<int>::min() + 1) == IntToString(numeric_limits<int>::min() + 1));
	assert(to_string(numeric_limits<int>::min()) == IntToString(numeric_limits<int>::min()));
	assert(0 == StringToInt("0"));
	assert(-1 == StringToInt("-1"));
	assert(1 == StringToInt("1"));
	assert(2 == StringToInt("2"));
	assert(-2 == StringToInt("-2"));
	assert(9 == StringToInt("9"));
	assert(10 == StringToInt("10"));
	assert(123 == StringToInt("123"));
	assert(2147483646 == StringToInt("2147483646"));
	assert(2147483647 == StringToInt("2147483647"));
	assert(-2147483648 == StringToInt("-2147483648"));
	assert(-2147483647 == StringToInt("-2147483647"));
}

void InterconvertStringIntTest()
{
#if TEST
	DirectedTests();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 10000; ++times)
	{
		uniform_int_distribution<int> dis(numeric_limits<int>::min(),
		                                  numeric_limits<int>::max());
		int x = dis(gen);
		string str = IntToString(x);
		//cout << x << " " << str << endl;
		assert(x == stoi(str));
		uniform_int_distribution<int> len_dis(0, 9);
		str = RandIntString(len_dis(gen));
		x = StringToInt(str);
		//cout << str << " " << x << endl;
		assert(x == stoi(str));
	}
#endif
}

#pragma endregion Test
