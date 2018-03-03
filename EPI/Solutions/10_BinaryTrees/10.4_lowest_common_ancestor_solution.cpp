// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_with_parent_prototype.h"

namespace Solutions
{
	int Height( BinaryTreeNodeP<int>* node )
	{
		int height = 0;
		auto cur = node;
		while ( cur )
			height++, cur = cur->parent;
		return height;
	}

	BinaryTreeNodeP<int>* LCAParent( const unique_ptr<BinaryTreeNodeP<int>>& n0, const unique_ptr<BinaryTreeNodeP<int>>& n1 )
	{
		int height0 = Height( n0.get() ), height1 = Height( n1.get() );
		BinaryTreeNodeP<int>* taller = height0 > height1 ? n0.get() : n1.get();
		BinaryTreeNodeP<int>* shorter = height0 <= height1 ? n0.get() : n1.get();
		int diff = abs( height0 - height1 );
		while ( diff-- )
			taller = taller->parent;
		while ( taller != shorter )
			taller = taller->parent, shorter = shorter->parent;
		return taller;
	}
}