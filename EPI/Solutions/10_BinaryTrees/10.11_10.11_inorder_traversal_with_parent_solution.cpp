// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

namespace Solutions
{
	// TRICKY one here.
	vector<int> InorderTraversal( const unique_ptr<BinaryTreeNodeP<int>>& tree )
	{
		// to do this correctly, we must thoroughly think about all the possible ways a particular node might traversed:
		// going down, coming from the parent: 
		// happens once per node, and the correct behavior is to go the left node.
		// If there is no left node, then we won't have any other values < than the current node, so record the current node,
		// then go right, or back to the parent if there is no right child.
		//
		// going up, coming from the left child: record the node's value. Go to the right node if there is one, otherwise go to the parent.
		//
		// going up, coming from the right child: do NOT record the node's value again. Go back up to the next parent node.
		vector<int> result;
		BinaryTreeNodeP<int>* cur = tree.get(), *prev = nullptr;
		while ( cur )
		{
			auto newPrev = cur;
			if ( prev == cur->parent ) // downward phase
			{
				if ( cur->left )
					cur = cur->left.get();
				else
				{
					// We are done with left. Record the value of the node - we will only have larger values from now on.
					result.emplace_back( cur->data );
					cur = cur->right ? cur->right.get() : cur->parent;
				}
			}
			else
			{
				if ( prev == cur->left.get() )
					result.emplace_back( cur->data );
				if ( prev == cur->left.get() && cur->right )
					cur = cur->right.get();
				else cur = cur->parent;
			}
			prev = newPrev;
		}
		return result;
	}
}