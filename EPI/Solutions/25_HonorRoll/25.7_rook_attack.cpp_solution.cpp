#include "stdafx.h"

namespace Solutions
{
	void RookAttack( vector<vector<int>>& a )
	{
		// four loops will short circuit the loops if we get a low of empty squares - two loops looks a lot more elegant though.
		// Book solution has six loops... they don't seem to take advantage of the fact we can just place fake root in the edge rows and columns
		// to achieve the same result.
		for ( int x = 0; x < a.size(); ++x )
		{
			for ( int y = 0; y < a[0].size(); ++y )
			{
				if ( !a[x][y] )
				{
					a[0][y] = 0;
					break;
				}
			}
		}
		for ( int y = 0; y < a[0].size(); ++y )
		{
			for ( int x = 0; x < a.size(); ++x )
			{
				if ( !a[x][y] )
				{
					a[x][0] = 0;
					break;
				}
			}
		}
		for ( int x = 0; x < a.size(); ++x )
		{
			if ( !a[x][0] )
			{
				for ( int y = 0; y < a[0].size(); ++y )
					a[x][y] = 0;
			}
		}
		for ( int y = 0; y < a[0].size(); ++y )
		{
			if ( !a[0][y] )
			{
				for ( int x = 0; x < a.size(); ++x )
					a[x][y] = 0;
			}
		}
	}
}