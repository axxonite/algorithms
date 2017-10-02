// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Input nodes are not nonempty and the key at a is less than or equal to that at b.
	BSTNode<int>* FindLCA(const unique_ptr<BSTNode<int>>& tree, const unique_ptr<BSTNode<int>>& a, const unique_ptr<BSTNode<int>>& b)
	{
		auto* p = tree.get();
		while (p->data < a->data || p->data > b->data)
		{
			// Keep searching since p is outside of [a, b].
			while (p->data < a->data)
				p = p->right.get(); // LCA must be in p'a right child.
			while (p->data > b->data)
				p = p->left.get(); // LCA must be in p'a left child.
		}
		// Now, a->data <= p->data && p->data <= b->data.
		return p;
	}
}
