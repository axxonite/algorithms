// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// For this one, it helps to write out relevant examples, such as /123/456, ../../local, empty string, /..
	string ShortestEquivalentPath( const string& path )
	{
		stringstream ss( path );
		string token;
		vector<string> pathParts;
		if ( path.empty() )
			throw invalid_argument( "" ); // An empty path is considered invalid.
		if ( path[0] == '/' )
			pathParts.emplace_back( "/" ); // A leading / means the root - keep around.
		while ( getline( ss, token, '/' ) )
		{
			if ( token == "." || token == "" ) // Explicitly skip ./ or empty token (meaning //)
				continue;
			if ( token == ".." )
			{
				if ( pathParts.empty() || pathParts.back() == ".." ) // TRICKY! add the .. if there is not path part to pop OR if another .. is at the top of the stack.
					pathParts.emplace_back( ".." );
				else if ( pathParts.back() == "/" ) // Watch for invalid case where we try to back out from root.
					throw invalid_argument( "" );
				else pathParts.pop_back();
			}
			else
				pathParts.emplace_back( token );
		}

		string result = pathParts.front();
		for ( int i = 1; i < pathParts.size(); ++i )
		{
			if ( result != "/" )
				result += "/";
			result += pathParts[i];
		}
		return result;
	}
}