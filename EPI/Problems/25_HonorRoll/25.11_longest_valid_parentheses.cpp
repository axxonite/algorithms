// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

#define TEST 0

int LongestValidParentheses( const string& s )
{
	return 0;
}

#pragma region Test

template <typename IterType>
int ParseFromSide( char paren, IterType begin, IterType end ) 
{
	int max_length = 0, num_parens_so_far = 0, length = 0;
	for ( IterType i = begin; i < end; ++i ) {
		if ( *i == paren ) {
			++num_parens_so_far, ++length;
		}
		else {  // *i != paren
			if ( num_parens_so_far <= 0 ) {
				num_parens_so_far = length = 0;
			}
			else {
				--num_parens_so_far, ++length;
				if ( num_parens_so_far == 0 ) {
					max_length = max( max_length, length );
				}
			}
		}
	}
	return max_length;
}

int LongestValidParenthesesConstantSpace( const string& s ) 
{
	return max( ParseFromSide( '(', begin( s ), end( s ) ), ParseFromSide( ')', s.rbegin(), s.rend() ) );
}

void LongestValidParenthesesSmallTest() {
	assert( LongestValidParentheses( ")(((())()(()(" ) == 6 );
	assert( LongestValidParentheses( "((())()(()(" ) == 6 );
	assert( LongestValidParentheses( ")(" ) == 0 );
	assert( LongestValidParentheses( "()" ) == 2 );
	assert( LongestValidParentheses( "" ) == 0 );
	assert( LongestValidParentheses( "()()())" ) == 6 );
	assert( LongestValidParenthesesConstantSpace( ")(((())()(()(" ) == 6 );
	assert( LongestValidParenthesesConstantSpace( "((())()(()(" ) == 6 );
	assert( LongestValidParenthesesConstantSpace( ")(" ) == 0 );
	assert( LongestValidParenthesesConstantSpace( "()" ) == 2 );
	assert( LongestValidParenthesesConstantSpace( "" ) == 0 );
	assert( LongestValidParenthesesConstantSpace( "()()())" ) == 6 );
}

void LongestValidParenthesesTest()
{
#if TEST
	LongestValidParenthesesSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	uniform_int_distribution<int> dis( 0, 100000 );
	for ( int times = 0; times < 1000; ++times ) 
	{
		string s = RandString( dis( gen ) );
		assert( LongestValidParenthesesConstantSpace( s ) == LongestValidParentheses( s ) );
	}
#endif
}

#pragma endregion
