// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Shared.h"

// #define TEST

void ReverseWords(string& s)
{
}

#pragma region Test

void ReverseWordsCheckAnswer(const string& ori, string& str)
{
	ReverseWords(str);
	assert(ori == str);
}

void ReverseWordsSimpleTest()
{
	string input = "a cat and dog";
	ReverseWords(input);
	assert(input.compare("dog and cat a") == 0);
	input = "dog";
	ReverseWords(input);
	assert(input.compare("dog") == 0);
	input = "a  bbb cc";
	ReverseWords(input);
	cout << input << endl;
}

void ReverseWordsTest()
{
#ifdef TEST
	ReverseWordsSimpleTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		string str;
		uniform_int_distribution<int> dis(0, 9999);
		str = RandString(dis(gen));
		string original_str(str);
		//cout << str << endl;
		ReverseWords(str);
		//cout << str << endl;
		ReverseWordsCheckAnswer(original_str, str);
	}
#endif
}

#pragma endregion Test
