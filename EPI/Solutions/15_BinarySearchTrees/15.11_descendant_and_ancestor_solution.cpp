// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// This is trickier than it looks.
	bool PairIncludesAncestorAndDescendantOfM( const unique_ptr<BSTNode<int>>& possible_anc_or_desc_0, const unique_ptr<BSTNode<int>>& possible_anc_or_desc_1, const unique_ptr<BSTNode<int>>& middle )
	{
		if ( !possible_anc_or_desc_0 || !possible_anc_or_desc_1 || !middle )
			return false;
		if ( possible_anc_or_desc_0->data == possible_anc_or_desc_1->data || possible_anc_or_desc_0->data == middle->data || possible_anc_or_desc_1->data == middle->data )
			return false;
		BSTNode<int>* cur0 = possible_anc_or_desc_0.get(), *cur1 = possible_anc_or_desc_1.get();
		while ( ( cur0 || cur1 ) && ( cur0 != middle.get() && cur1 != middle.get() && cur0 != possible_anc_or_desc_1.get() && cur1 != possible_anc_or_desc_0.get() ) )
		{
			// Search down the tree with either node until we reach the middle node.
			if ( cur0 )
				cur0 = cur0->data < middle->data ? cur0->right.get() : cur0->left.get();
			if ( cur1 )
				cur1 = cur1->data < middle->data ? cur1->right.get() : cur1->left.get();
		}
		// Check if neither node reached the middle node.
		if ( (!cur0 && !cur1) || cur0 == possible_anc_or_desc_1.get() || cur1 == possible_anc_or_desc_0.get() )
			return false;

		// Given we found a node, search for the other. Note that we are searching for possible_anc_or_desc_x, not curx.
		auto targetNode = cur0 == middle.get() ? possible_anc_or_desc_1.get() : possible_anc_or_desc_0.get();
		auto curNode = middle.get();
		while ( curNode != targetNode )
		{
			curNode = curNode->data < targetNode->data ? curNode->right.get() : curNode->left.get();
			if ( !curNode )
				return false;
		}
		return true;
	}
}