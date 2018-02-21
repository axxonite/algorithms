// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<int> Multiply( vector<int> num1, vector<int> num2 )
{
	vector<int> result;
	return result;
}

#pragma region Test

bool EqualVector( const vector<int>& A, const vector<int>& B )
{
	return equal( A.begin(), A.end(), B.begin(), B.end() );
}

void MultiplySimpleTest()
{
	assert( EqualVector( Multiply( { 0 }, { -1, 0, 0, 0 } ), { 0 } ) );
	assert( EqualVector( Multiply( { 0 }, { 1, 0, 0, 0 } ), { 0 } ) );
	assert( EqualVector( Multiply( { 9 }, { 9 } ), { 8, 1 } ) );
	assert( EqualVector( Multiply( { 9 }, { 9, 9, 9, 9 } ), { 8, 9, 9, 9, 1 } ) );
	assert( EqualVector( Multiply( { 1, 3, 1, 4, 1, 2 }, { -1, 3, 1, 3, 3, 3, 2 } ),
		{ -1, 7, 2, 5, 8, 7, 5, 8, 4, 7, 8, 4 } ) );
	assert( EqualVector( Multiply( { 7, 3 }, { -3 } ), { -2, 1, 9 } ) );
}

string VectorToString( const vector<int>& A )
{
	stringstream converter;
	copy( A.begin(), A.end(), ostream_iterator<int>( converter, "" ) );
	return converter.str();
}

void MultiplyTest()
{
#if TEST
	MultiplySimpleTest();
#endif
}

#pragma endregion Test
