// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void RotateArray( int shift, vector<int>& a )
	{
		int valuesMoved = 0;
		int i;
		// per the book, the number of cycles is the GCD of shift and a.size(). This is only conjecture, and the book doesn't give a proof as to why.
		// however, if we don't know the cycles, but we know the cycles all have the same length, and that they are all shifted by one...
		// then all we have to do is count how many values we've moved until we've moved them all. No need to compute a GCD.
		for ( i = 0; valuesMoved < a.size(); ++i )
		{
			int cur = i, srcValue = a[i];
			do
			{
				int dstIndex = ( cur + shift ) % a.size();
				swap( srcValue, a[dstIndex] );
				valuesMoved++, cur = dstIndex;
			} while ( cur != i );
		}
	}

	void RotateArray2( int shift, vector<int>& a )
	{
		shift %= a.size();
		reverse( a.begin(), a.end() ); // reverse whole array.
		reverse( a.begin(), a.begin() + shift ); // [start..shift] is now last shift elements of array
		reverse( a.begin() + shift, a.end() ); // [shift..end] now maps last (which used to be first) to the shift position element, and so forth. Magic.
	}
}