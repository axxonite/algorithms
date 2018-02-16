#pragma once

#include "stdafx.h"
#include "5.2_swap_bits_solution.h"

namespace Solution
{
	vector<long long> precomputedReverse;

	long long ReverseX( long long x, int n )
	{
		for ( int i = 0, j = n; i < j; ++i, --j )
			x = SwapBits( x, i, j );
		return x;
	}

	void CreatePrecomputedTable()
	{
		for ( int i = 0; i < ( 1 << 16 ); ++i )
			precomputedReverse.emplace_back( ReverseX( i, 15 ) );
	}

	long long ReverseBits( long long x )
	{
		const int kMaskSize = 16;
		const int kBitMask = 0xFFFF;
		return precomputedReverse[x & kBitMask] << ( 3 * kMaskSize ) | 
			precomputedReverse[( x >> kMaskSize ) & kBitMask] << ( 2 * kMaskSize ) |
			precomputedReverse[( x >> ( 2 * kMaskSize ) ) & kBitMask] << kMaskSize | 
			precomputedReverse[( x >> ( 3 * kMaskSize ) ) & kBitMask];
	}
}