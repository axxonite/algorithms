// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct CharWithFrequency
	{
		char c;
		double freq;
	};

	struct HuffmanNode
	{
		CharWithFrequency charFreq;
		shared_ptr<HuffmanNode> left, right;

	};

	struct FrequencyComparator
	{
		bool operator()( const shared_ptr<HuffmanNode>& lhs, const shared_ptr<HuffmanNode>& rhs ) const
		{
			return lhs->charFreq.freq > rhs->charFreq.freq;
		}
	};

	void AssignCodes( shared_ptr<HuffmanNode> node, string& code, unordered_map<char, string>& result )
	{
		if ( node->charFreq.c != '_' )
			result[node->charFreq.c] = code;
		else
		{
			code.push_back( '0' );
			AssignCodes( node->left, code, result );
			code.back() = '1';
			AssignCodes( node->right, code, result );
			code.pop_back();
		}
	}

	unordered_map<char, string> HuffmanEncoding( vector<CharWithFrequency>& symbols )
	{
		// first, we need to store the frequencies. Use a min-heap.
		priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, FrequencyComparator> heap;
		for ( auto s : symbols )
			heap.emplace( make_shared<HuffmanNode>( HuffmanNode{ { s.c, s.freq }, nullptr, nullptr } ) );

		// Distribute the nodes in a binary tree by frequency.
		while ( heap.size() > 1 )
		{
			auto left = heap.top();
			heap.pop();
			auto right = heap.top();
			heap.pop();
			heap.emplace( make_shared<HuffmanNode>( HuffmanNode{ '_', left->charFreq.freq + right->charFreq.freq, left, right } ) );
		}

		unordered_map<char, string> result;
		string code;
		AssignCodes( heap.top(), code, result );
		return result;
	}
}