// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<string> JustifyText(const vector<string>& words, size_t l)
{
	return {};
}

#pragma region Test

void JustifyTextTestCase(const vector<string>& words, size_t L, const vector<string>& golden)
{
	auto result = JustifyText(words, L);
	for (const string& s : result)
	{
		cout << "\"" << s << "\"" << endl;
	}
	cout << endl;
	assert(equal(result.begin(), result.end(), golden.begin(), golden.end()));
}

void JustifyTextTest()
{
#if TEST
	vector<string> words = {"Text", "justification", "is", "trickier", "than",
		"it", "seems!"};
	vector<string> golden = {"Text          ", "justification ",
		"is    trickier", "than it seems!"};
	size_t L = 14;
	cout << "L = " << L << endl;
	JustifyTextTestCase(words, L, golden);
	words = {"Listen", "to", "many,", "speak", "to", "a", "few."};
	golden = {"Listen", "to    ", "many, ", "speak ", "to   a", "few.  "};
	L = 6;
	cout << "L = " << L << endl;
	JustifyTextTestCase(words, L, golden);
	words = {"The", "quick", "brown", "fox", "jumped",
		"over", "the", "lazy", "dogs."};
	golden = {"The   quick", "brown   fox", "jumped over", "the    lazy",
		"dogs.      "};
	L = 11;
	cout << "L = " << L << endl;
	JustifyTextTestCase(words, L, golden);
	golden = {"The  quick brown", "fox  jumped over", "the lazy dogs.  "};
	L = 16;
	cout << "L = " << L << endl;
	JustifyTextTestCase(words, L, golden);
	golden = {"The  quick  brown", "fox  jumped  over", "the lazy dogs.   "};
	L = 17;
	cout << "L = " << L << endl;
	JustifyTextTestCase(words, L, golden);
	words = {"Hello", "World"};
	golden = {"Hello World   "};
	L = 14;
	JustifyTextTestCase(words, L, golden);
#endif
}

#pragma endregion Test
