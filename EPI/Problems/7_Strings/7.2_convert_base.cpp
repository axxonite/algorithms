// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

// #define TEST

string ConvertBase( const string& num, int b1, int b2 ) 
{
  return "";
}

#pragma region Test

void ConvertBaseTest()
{
#ifdef TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times ) {
		uniform_int_distribution<int> len_dis( 1, 9 );
		string input = RandIntString( len_dis( gen ) );
		uniform_int_distribution<int> base_dis( 2, 16 );
		int base = base_dis( gen );
		base = 16;
		cout << "input is " << input << ", base1 = 10, base2 = " << base << ", result = " << ConvertBase( input, 10, base ) << endl;
		string result = ConvertBase( input, 10, base );
		string src = ConvertBase( result, base, 10 );
		assert( input == src );
	}
#endif
}

#pragma endregion
