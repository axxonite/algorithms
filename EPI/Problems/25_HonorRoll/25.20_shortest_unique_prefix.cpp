// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

#define TEST 0

string FindShortestPrefix( const string& s, const unordered_set<string>& d )
{
	return "";
}

#pragma region Test

string FindShortestPrefixCheckAns( const string& s, unordered_set<string>& D )
{
	int len = 0;
	for ( auto iter = D.cbegin(); iter != D.cend(); ++iter ) 
	{
		int i;
		for ( i = 0; i < s.size() && i < ( *iter ).size(); ++i ) 
		{
			if ( s[i] != ( *iter )[i] ) 
				break;
		}
		if ( i > len ) 
			len = i;
	}
	if ( len == s.size() )
		return string();
	else 
		return s.substr( 0, len + 1 );
}

void FindShortestPrefixTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 10; ++times ) 
	{
		unordered_set<string> D;
		string s;
		uniform_int_distribution<int> dis( 1, 10 );
		s = RandString( dis( gen ) );
		uniform_int_distribution<int> dis2( 1, 10000 );
		int n = dis2( gen );
		while ( n-- ) 
		{
			uniform_int_distribution<int> dis( 1, 10 );
			D.emplace( RandString( dis( gen ) ) );
		}
		cout << s << ' ' << "shortest prefix = " << FindShortestPrefix( s, D )
			<< endl;
		auto a = FindShortestPrefix( s, D );
		auto b = FindShortestPrefixCheckAns( s, D );
		assert( a == b );
	}
#endif
}

#pragma endregion
