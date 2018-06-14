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
			return Coord() < that.Coord();
		}

		int Coord() const
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
			sortedEndpoints.emplace_back(Endpoint{ true, &a });
			sortedEndpoints.emplace_back(Endpoint{ false, &a });
		}
		sort(sortedEndpoints.begin(), sortedEndpoints.end());

		vector<LineSegment> result;
		map<int, const LineSegment*> activeSegments;
		for (int i = 0; i < sortedEndpoints.size(); ++i)
		{
			const Endpoint& endpoint = sortedEndpoints[i];
			// Note how we don't do any processing when we encounter two endpoints at the same coordinate.
			if (!activeSegments.empty() && sortedEndpoints[i - 1].Coord() != endpoint.Coord())
			{
				int prevEndpointCoord = sortedEndpoints[i - 1].Coord();
				const LineSegment* topSegment = activeSegments.crbegin()->second;
				// Segments are mergeable if:
				// * this is not the very first endpoint, in which case the result array is empty
				// * the endpoint's segment has the same height and color as the top segment
				// * the last endpoint we processed was the right side of the last segment we added to the result.
				// If our last endpoint was on the left side, then that endpoint's segment isn't in the result array yet so there is nothing to merge with.
				if (!result.empty() && result.back().height == topSegment->height && result.back().color == topSegment->color && prevEndpointCoord == result.back().right)
					result.back().right = endpoint.Coord();
				else
				{
					// Add a new segment.
					result.emplace_back(LineSegment{ prevEndpointCoord, endpoint.Coord(), topSegment->color, topSegment->height });
				}
			}

			// update active segments.
			if (endpoint.isLeft == true)
				activeSegments.emplace(endpoint.line->height, endpoint.line); // Left end point.
			else
				activeSegments.erase(endpoint.line->height); // Right end point.
		}

		return result;
	}
}
