// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

namespace Solutions
{
	struct TrieNode
	{
		unordered_map<char, unique_ptr<TrieNode>> children;
	};

	string FindShortestPrefix( const string& s, const unordered_set<string>& d )
	{
		TrieNode root;
		for ( auto& w : d )
		{
			TrieNode* cur = &root;
			for ( int i = 0; i < w.size(); ++i )
			{
				if ( !cur->children.count( w[i] ) )
					cur->children[w[i]] = make_unique<TrieNode>();
				cur = cur->children[w[i]].get();
			}
		}

		TrieNode* cur = &root;
		for ( int i = 0; i < s.size(); ++i )
		{
			auto it = cur->children.find( s[i] );
			if ( it == cur->children.end() )
				return s.substr( 0, i + 1 );
			cur = it->second.get();
		}
		return "";
	}
}