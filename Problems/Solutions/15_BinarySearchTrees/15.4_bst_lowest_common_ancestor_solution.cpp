// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Input nodes are not nonempty and the key at a is less than or equal to that at b.
	BSTNode<int>* FindLCA(const unique_ptr<BSTNode<int>>& tree, const unique_ptr<BSTNode<int>>& a, const unique_ptr<BSTNode<int>>& b)
	{
		auto* p = tree.get();
		// if a < p < b then p is the LCA.
		while (p->data < a->data || p->data > b->data)
		{
			while (p->data < a->data)
				p = p->right.get(); // p < a so search to the right so we can find a < p < b
			while (p->data > b->data)
				p = p->left.get(); // p > b so search to the left so we can find a < p < b
		}
		return p;
	}
}
