// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

//#define TEST

void ReadFileLine(const string& line)
{
}

vector<string> FindKMostVisited(int k)
{
	vector<string> result;
	return result;
}

#pragma region Test

void FindKMostVisitedTest()
{
#ifdef TEST
	ReadFileLine( "g" );
	ReadFileLine( "a" );
	ReadFileLine( "t" );
	ReadFileLine( "t" );
	ReadFileLine( "a" );
	ReadFileLine( "a" );
	ReadFileLine( "a" );
	ReadFileLine( "g" );
	ReadFileLine( "t" );	
	ReadFileLine( "c" );
	auto result = FindKMostVisited(2);
	assert( result == vector<string>({"a", "t"}) );
	ReadFileLine( "t" );
	ReadFileLine( "a" );
	ReadFileLine( "t" );
#endif
}

#pragma endregion Test
