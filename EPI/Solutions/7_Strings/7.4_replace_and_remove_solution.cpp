// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

namespace Solutions
{
	int ReplaceAndRemove( int size, char s[] )
	{
		// remove each b
		// replace each a by two d's
		int packedSize = 0, finalSize = 0;
		for ( int i = 0; i < size; ++i )
		{
			if ( s[i] != 'b' )
			{
				s[packedSize++] = s[i];
				finalSize += s[i] == 'a' ? 2 : 1;
			}
		}
		int dst = finalSize - 1;
		for ( int i = packedSize - 1; i >= 0; --i )
		{
			if ( s[i] == 'a' )
				s[dst--] = 'd', s[dst--] = 'd';
			else s[dst--] = s[i];
		}
		return finalSize;
	}
}