// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

#define TEST 1

bool IsDigit( char digit )
{
	return digit >= '0';
}

string ConvertBase( const string& num, int b1, int b2 ) 
{
	long long value = 0;
	bool neg = num.front() == '-';
	for ( int i = num[0] == '-' ? 1 : 0; i < num.size(); ++i )
		value = value * b1 + (IsDigit(num[i]) ? (num[i] - '0') : (num[i] - 'a' + 10));
	string result;
	while ( value )
	{
		int digit = value % b2;
		result += digit < 10 ? digit + '0' : digit - 10 + 'a';
		value /= b2;
	}
	return (neg ? "-" : "") + string(result.rbegin(), result.rend());
}

#pragma region Test

void ConvertBaseTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times ) {
		uniform_int_distribution<int> len_dis( 1, 9 );
		string input = RandIntString( len_dis( gen ) );
		uniform_int_distribution<int> base_dis( 2, 16 );
		int base = base_dis( gen );
		cout << "input is " << input << ", base1 = 10, base2 = " << base << ", result = " << ConvertBase( input, 10, base ) << endl;
		string result = ConvertBase( input, 10, base );
		string src = ConvertBase( result, base, 10 );
		assert( input == src );
	}
#endif
}

#pragma endregion
