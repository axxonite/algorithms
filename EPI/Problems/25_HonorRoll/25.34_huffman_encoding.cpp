// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct CharWithFrequency
{
	char c;
	double freq;
};



unordered_map<char, string> HuffmanEncoding(vector<CharWithFrequency>& symbols )
{
	return {};
}

#pragma region Test

const double kEnglishFreq[] = 
{
	8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966,
	0.153, 0.772, 4.025, 2.406, 6.749,  7.507, 1.929, 0.095, 5.987,
	6.327, 9.056, 2.758, 0.978, 2.360,  0.150, 1.974, 0.074 
};

// There is no test here, it just lists the values.
void HuffmanEncodingTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	vector<CharWithFrequency> symbols;
	int sum = 0;

	for ( int i = 0; i < 26; ++i ) {
		CharWithFrequency t;
		t.c = 'a' + i;
		t.freq = kEnglishFreq[i];
		symbols.emplace_back( t );
	}
	auto result = HuffmanEncoding( symbols );
	double avg = 0.0;
	for ( const auto& symbol : symbols ) {
		cout << symbol.c << " " << symbol.freq << " " << result[symbol.c] << endl;
		avg += symbol.freq / 100 * result[symbol.c].size();
	}
	cout << "average huffman code length = " << avg << endl;
#endif
}

#pragma endregion
