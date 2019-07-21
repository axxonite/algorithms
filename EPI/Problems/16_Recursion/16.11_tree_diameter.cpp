// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

struct TreeNode
{
	struct Edge
	{
		unique_ptr<TreeNode> root;
		double length;
	};
	vector<Edge> edges;
};

double ComputeDiameter(const unique_ptr<TreeNode>& t)
{
	return 0;
}

#pragma region Test

void ComputeDiameterTest()
{
#ifdef TEST
	unique_ptr<TreeNode> r = nullptr;
	assert(0.0 == ComputeDiameter(r));
	r = make_unique<TreeNode>(TreeNode());
	r->edges.emplace_back(TreeNode::Edge{ make_unique<TreeNode>(TreeNode()), 10 });
	r->edges[0].root->edges.emplace_back(TreeNode::Edge{ make_unique<TreeNode>(TreeNode()), 50 });
	r->edges.emplace_back(TreeNode::Edge{ make_unique<TreeNode>(TreeNode()), 20 });
	assert(80 == ComputeDiameter(r));
	cout << ComputeDiameter(r) << endl;
	r->edges[0].root->edges.emplace_back(TreeNode::Edge{ make_unique<TreeNode>(TreeNode()), 100 });
	assert(150 == ComputeDiameter(r));
	cout << ComputeDiameter(r) << endl;
#endif
}

#pragma endregion Test
