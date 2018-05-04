#pragma once

namespace Solutions
{
	inline long long SwapBits( long long x, int i, int j ) 
	{
		if ((( x >> i) & 1) != (( x >> j) & 1))
			x ^= (1LL << i) | (1LL << j);
		return x;
	}
}