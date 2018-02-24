// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

#define TEST 0

vector<string> PhoneMnemonic( const string& phone_number ) 
{
	return {};
}

#pragma region Test

void PhoneMnemonicTest()
{
#if TEST
	string num;
	num = RandString( 10 );
	auto result = PhoneMnemonic( num );
	cout << "number = " << num << endl;
	for ( const string& str : result ) {
		cout << str << endl;
	}
#endif
}

#pragma endregion
