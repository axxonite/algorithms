// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Solutions\5_Primitives\5.2_swap_bits_solution.h"

#define TEST 0

void InitReverseBits()
{
}

long long ReverseBits( long long x )
{
	return 0;
}

#pragma region Test

long long ReverseX2( long long x, int n )
{
	for ( int i = 0, j = n; i < j; ++i, --j )
		x = Solutions::SwapBits( x, i, j );
	return x;
}
void ReverseBitsTest()
{
#if TEST
	InitReverseBits();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times ) 
	{
		uniform_int_distribution<long> dis( 0, numeric_limits<long>::max() );
		long x = dis( gen );
		cout << "x = " << x << ", reverse x = " << ReverseBits( x ) << endl;
		assert( ReverseBits( x ) == ReverseX2( x, 63 ) );
	}
#endif
}

#pragma endregion Test