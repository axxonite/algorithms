// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Wrote both working implementations here in 47 minutes.

	// Given a binary search tree's preorder traversal value, reconstruct the binary search tree.

	// O(n lg n) - this is exactly like the version from EPI.
	unique_ptr<BSTNode<int>> ReconstructBSTPreorder( const vector<int>& a, int index, int end )
	{
		if ( index < end )
		{
			int key = a[index++];
			// Do a linear seach of values to find the first value > the key. We use end as the upper bound for our linear search.
			int rightStart = index;
			while ( rightStart < end && a[rightStart] < key )
				++rightStart;
			auto left = ReconstructBSTPreorder( a, index, rightStart );
			auto right = ReconstructBSTPreorder( a, rightStart, end );
			return make_unique<BSTNode<int>>( BSTNode<int>{key, move( left ), move( right )} );
		}
		else return nullptr;
	}

	// O(n)
	unique_ptr<BSTNode<int>> ReconstructBSTPreorder2( const vector<int>& a, int& index, int max )
	{
		// A better approach.
		int key = a[index++];

		unique_ptr<BSTNode<int>> left = nullptr, right = nullptr;
		if ( index < a.size() && a[index] < key )
			left = ReconstructBSTPreorder2( a, index, key );
		if ( index < a.size() && a[index] < max )
			right = ReconstructBSTPreorder2( a, index, max );
		return make_unique<BSTNode<int>>( BSTNode<int>{key, move( left ), move( right )} );
	}

	// From EPI, O(n).
	unique_ptr<BSTNode<int>> ReconstructBSTPreorder3( const vector<int>& a, int min, int max, int& index )
	{
		// Cleanest approach.
		if ( index == a.size() )
			return nullptr;

		// this is cleaner.
		int key = a[index];
		if ( key < min || key > max )
			return nullptr;

		++index;
		auto left = ReconstructBSTPreorder3( a, min, key, index );
		auto right = ReconstructBSTPreorder3( a, key, max, index );
		return make_unique<BSTNode<int>>( BSTNode<int>{key, move( left ), move( right )} ); // this is the same as my version.
	}

}