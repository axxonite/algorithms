// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 1

short parities[0xFFFF];

short Parity( unsigned long long x )
{
	x ^= x >> 32;
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	return short(x & 1);
}

vector<unsigned char> Parity( vector<long long int>& values )
{
	for ( int i = 0; i < 0xffff; ++i )
		parities[i] = Parity(i);
	vector<unsigned char> result;
	for ( auto value : values )
	{
		auto parity = (parities[value & 0xffff] ^
			parities[( value >> 16 ) & 0xffff] ^
			parities[( value >> 32 ) & 0xffff] ^
			parities[( value >> 48 )] );

		result.emplace_back( parity );
	}
	return result;
}

#pragma region Test


#pragma endregion Test
