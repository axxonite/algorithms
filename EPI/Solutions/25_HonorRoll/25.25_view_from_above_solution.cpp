#include "stdafx.h"

namespace Solutions
{
	struct LineSegment
	{
		int left, right; // Specifies the interval.
		int color;
		int height;
	};

	class Endpoint
	{
	public:
		bool operator<(const Endpoint& that) const
		{
			return Value() < that.Value();
		}

		int Value() const
		{
			return isLeft ? line->left : line->right;
		}

		bool isLeft;
		const LineSegment* line;
	};

	vector<LineSegment> CalculateViewFromAbove(const vector<LineSegment>& A)
	{
		vector<Endpoint> sortedEndpoints;
		for (const LineSegment& a : A)
		{
			sortedEndpoints.emplace_back(Endpoint{true, &a});
			sortedEndpoints.emplace_back(Endpoint{false, &a});
		}
		sort(sortedEndpoints.begin(), sortedEndpoints.end());

		vector<LineSegment> result;
		int prevXAxis = sortedEndpoints.front().Value(); // Leftmost end point.
		unique_ptr<LineSegment> prev = nullptr;
		map<int, const LineSegment*> activeSegments;
		for (const Endpoint& endpoint : sortedEndpoints)
		{
			const LineSegment* topSegment = activeSegments.crbegin()->second;
			if (!activeSegments.empty() && prevXAxis != endpoint.Value())
			{
				if (prev)
				{
					if (prev->height == topSegment->height && prev->color == topSegment->color && prevXAxis == prev->right)
						prev->right = endpoint.Value();
					else
					{
						result.emplace_back(*prev);
						*prev = {prevXAxis, endpoint.Value(), topSegment->color, topSegment->height};
					}
				}
				else
				{
					// Found first segment.
					prev = make_unique<LineSegment>(LineSegment{ prevXAxis, endpoint.Value(), topSegment->color, topSegment->height });
				}
			}
			prevXAxis = endpoint.Value();

			if (endpoint.isLeft == true)
				activeSegments.emplace(endpoint.line->height, endpoint.line); // Left end point.
			else
				activeSegments.erase(endpoint.line->height); // Right end point.
		}

		// Output the remaining segment(if any).
		if (prev)
			result.emplace_back(*prev);
		return result;
	}
	
}
