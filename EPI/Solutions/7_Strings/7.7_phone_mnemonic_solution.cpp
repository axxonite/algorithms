// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

namespace Solutions
{
	map<char, string> mappings = { { '0', "" },{ '1', "" },{ '2', "ABC" },{ '3', "DEF" },{ '4', "GHI" },{ '5', "JKL" },{ '6', "MNO" },{ '7', "PQRS" },{ '8', "TUV" },{ '9', "WXYZ" },{ '*', "" },{ '#', "" } };

	void PhoneMnemonic( const string& n, int index, int dstIndex, string& partialResult, vector<string>& result )
	{
		if ( index == n.size() )
		{
			result.emplace_back( partialResult );
			return;
		}

		string mapping = mappings[n[index]];
		if ( mapping.empty() )
			PhoneMnemonic( n, index + 1, dstIndex, partialResult, result );
		else
		{
			for ( auto c : mapping )
			{
				partialResult[dstIndex] = c;
				PhoneMnemonic( n, index + 1, dstIndex + 1, partialResult + c, result );
			}
		}
	}

	vector<string> PhoneMnemonic( const string& n )
	{
		string partialResult( n.size(), 0 ); // Trick - preallocate the string to avoid pushing and popping and all that.
		vector<string> result;
		PhoneMnemonic( n, 0, 0, partialResult, result );
		return result;
	}
}