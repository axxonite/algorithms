// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct TreeNode
	{
		struct Edge
		{
			unique_ptr<TreeNode> root;
			double length;
		};

		vector<Edge> edges;
	};

	struct HeightAndDiameter
	{
		double height, diameter;
	};

	HeightAndDiameter ComputeHeightAndDiameter(const unique_ptr<TreeNode>& r)
	{
		double diameter = numeric_limits<double>::min();
		array<double, 2> heights = { { 0.0, 0.0 } }; // Stores the max two heights.
		for (const auto& e : r->edges)
		{
			HeightAndDiameter h_d = ComputeHeightAndDiameter(e.root);
			// Track two greatest heights from this node.
			if (h_d.height + e.length > heights[0])
				heights = { { h_d.height + e.length, heights[0] } }; // Replace top height and displace 2nd max height.
			else if (h_d.height + e.length > heights[1])
				heights[1] = h_d.height + e.length;
			diameter = max(diameter, h_d.diameter);
		}
		// The diameter is the maximum of the greatest diameter found in a subtree (meaning the path is found within that subtree), 
		// and the sum of the height of the two deepest subtrees (meaning the path goes through the current node and into each of the subtrees).
		return { heights[0], max(diameter, heights[0] + heights[1]) }; // Height is greatest height, diameter is sum of two greatest heights.
	}

	double ComputeDiameter(const unique_ptr<TreeNode>& T)
	{
		return T ? ComputeHeightAndDiameter(T).diameter : 0.0;
	}
}
