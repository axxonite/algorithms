// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

string ShortestEquivalentPath(const string& path)
{
	return "";
}

#pragma region Test

void ShortestEquivalentPathTest()
{
#if TEST
	assert( ShortestEquivalentPath( "123/456" ) == string( "123/456" ) );
	assert( ShortestEquivalentPath( "/123/456" ) == string( "/123/456" ) );
	assert( ShortestEquivalentPath( "usr/lib/../bin/gcc" ) == string( "usr/bin/gcc" ) );
	assert( ShortestEquivalentPath( "./../" ) == string( ".." ) );
	assert( ShortestEquivalentPath( "../../local" ) == string( "../../local" ) );
	assert( ShortestEquivalentPath( "./.././../local" ) == string( "../../local" ) );
	assert( ShortestEquivalentPath( "/foo/../foo/./../" ) == string( "/" ) );
	try 
	{
		ShortestEquivalentPath( "/foo.txt" );
	}
	catch ( const exception& e ) 
	{
		cout << e.what() << endl;
	}
	try 
	{
		ShortestEquivalentPath( "" );
		assert( false );
	}
	catch ( const exception& e ) 
	{
		cout << e.what() << endl;
	}
	try 
	{
		ShortestEquivalentPath( "/.." );
	}
	catch ( const exception& e ) 
	{
		cout << e.what() << endl;
	}
	try 
	{
		ShortestEquivalentPath( "/cpp_name/bin/" );
	}
	catch ( const exception& e ) 
	{
		cout << e.what() << endl;
	}
	assert( ShortestEquivalentPath( "scripts//./../scripts/awkscripts/././" ) == string( "scripts/awkscripts" ) );
#endif
}

#pragma endregion
