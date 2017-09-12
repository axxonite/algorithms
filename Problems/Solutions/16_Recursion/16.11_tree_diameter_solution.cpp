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
			if (h_d.height + e.length > heights[0])
				heights = { { h_d.height + e.length, heights[0] } };
			else if (h_d.height + e.length > heights[1])
				heights[1] = h_d.height + e.length;
			diameter = max(diameter, h_d.diameter);
		}
		return { heights[0], max(diameter, heights[0] + heights[1]) };
	}

	double ComputeDiameter(const unique_ptr<TreeNode>& T)
	{
		return T ? ComputeHeightAndDiameter(T).diameter : 0.0;
	}
}
