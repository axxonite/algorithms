// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Shared.h"

namespace Solutions
{
	bool IsDigit( char digit )
	{
		return digit <= '9';
	}

	string ConvertBase( const string& num, int b1, int b2 )
	{
		long long value = 0;
		bool neg = num.front() == '-'; // watch for negative sign.
									   // Note how we iterate from the beginning.
		for ( int i = num[0] == '-' ? 1 : 0; i < num.size(); ++i )
			value = value * b1 + ( IsDigit( num[i] ) ? num[i] - '0' : num[i] - 'a' + 10 ); // The ? must be enclosed to ensure correct order of operations - better yet, don't use ?
																						   // Catch special case with zero here.
		if ( value == 0 )
			return "0";
		string result;
		while ( value )
		{
			int digit = value % b2;
			result += digit < 10 ? digit + '0' : digit - 10 + 'a';
			value /= b2;
		}
		// don't forget to reverse string at the end.
		return ( neg ? "-" : "" ) + string( result.rbegin(), result.rend() );
	}

}