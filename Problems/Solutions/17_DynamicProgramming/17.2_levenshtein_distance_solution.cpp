// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int ComputeDistanceBetweenPrefixes(const string& a, int indexA, const string& b, int indexB, vector<vector<int>>& distance)
	{
		if (indexA < 0)
			return indexB + 1; // a is empty so add all of b's characters.
		if (indexB < 0)
			return indexA + 1; // b is empty so delete all of a's characters.
		if (distance[indexA][indexB] == -1)
		{
			if (a[indexA] == b[indexB])
				distance[indexA][indexB] = ComputeDistanceBetweenPrefixes(a, indexA - 1, b, indexB - 1, distance);
			else
			{
				int substituteLastAB = ComputeDistanceBetweenPrefixes(a, indexA - 1, b, indexB - 1, distance);
				int keepLastB = ComputeDistanceBetweenPrefixes(a, indexA, b, indexB - 1, distance); // Transform a to b - 1 and keep b's last character
				int deleteLastA = ComputeDistanceBetweenPrefixes(a, indexA - 1, b, indexB, distance); // Delete a's last character and transform a - 1 to b, 
				distance[indexA][indexB] = 1 + min({substituteLastAB, keepLastB, deleteLastA});
			}
		}
		return distance[indexA][indexB];
	}

	int LevenshteinDistance(const string& a, const string& b)
	{
		vector<vector<int>> distanceBetweenPrefixes(a.size(), vector<int>(b.size(), -1));
		return ComputeDistanceBetweenPrefixes(a, a.size() - 1, b, b.size() - 1, distanceBetweenPrefixes);
	}
}
