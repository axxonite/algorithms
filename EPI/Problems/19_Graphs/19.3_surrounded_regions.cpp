// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

void FillSurroundedRegions( vector<vector<char>>& board ) 
{
}

#pragma region Test

void FillSurroundedRegionsSimpleTest() 
{
	vector<vector<char>> A = { { 'B', 'B', 'B', 'B' },
	{ 'W', 'B', 'W', 'B' },
	{ 'B', 'W', 'W', 'B' },
	{ 'B', 'B', 'B', 'B' } };
	FillSurroundedRegions( A );
	vector<vector<char>> golden = { { 'B', 'B', 'B', 'B' },
	{ 'W', 'B', 'B', 'B' },
	{ 'B', 'B', 'B', 'B' },
	{ 'B', 'B', 'B', 'B' } };
	assert( equal( A.begin(), A.end(), golden.begin(), golden.end() ) );
}

void FillSurroundedRegionsTest()
{
#if TEST
	FillSurroundedRegionsSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	uniform_int_distribution<int> dis( 1, 1000 );
	int n, m;
	n = dis( gen ), m = dis( gen );
	vector<vector<char>> board( n, vector<char>( m ) );
	uniform_int_distribution<int> zero_or_one( 0, 1 );
	for ( int i = 0; i < n; ++i ) 
	{
		for ( int j = 0; j < m; ++j ) 
		{
			board[i][j] = zero_or_one( gen ) ? 'B' : 'W';
		}
	}
	for ( int i = 0; i < board.size(); ++i ) 
	{
		for ( int j = 0; j < board[i].size(); ++j ) 
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	FillSurroundedRegions( board );
	//cout << endl;
	//for ( int i = 0; i < board.size(); ++i ) 
	//{
	//	for ( int j = 0; j < board[i].size(); ++j ) 
	//	{
	//		cout << board[i][j];
	//	}
	//	cout << endl;
	//}
#endif
}

#pragma endregion
