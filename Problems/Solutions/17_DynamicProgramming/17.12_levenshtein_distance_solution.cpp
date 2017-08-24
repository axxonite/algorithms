// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int ComputeDistanceBetweenPrefixes(const string& A, int A_idx, const string& B, int B_idx, vector<vector<int>>* distance_between_prefixes_ptr)
	{
		vector<vector<int>>& distance_between_prefixes = *distance_between_prefixes_ptr;
		if (A_idx < 0)
			return B_idx + 1; // A is empty so add all of B's characters.
		if (B_idx < 0)
			return A_idx + 1; // B is empty so delete all of A's characters.
		if (distance_between_prefixes[A_idx][B_idx] == -1)
		{
			if (A[A_idx] == B[B_idx])
				distance_between_prefixes[A_idx][B_idx] = ComputeDistanceBetweenPrefixes(A, A_idx - 1, B, B_idx - 1, distance_between_prefixes_ptr);
			else
			{
				int substitute_last = ComputeDistanceBetweenPrefixes(A, A_idx - 1, B, B_idx - 1, distance_between_prefixes_ptr);
				int add_last = ComputeDistanceBetweenPrefixes(A, A_idx - 1, B, B_idx, distance_between_prefixes_ptr);
				int delete_last = ComputeDistanceBetweenPrefixes(A, A_idx, B, B_idx - 1, distance_between_prefixes_ptr);
				distance_between_prefixes[A_idx][B_idx] = 1 + min({ substitute_last, add_last, delete_last });
			}
		}
		return distance_between_prefixes[A_idx][B_idx];
	}

	int LevenshteinDistance(const string& A, const string& B)
	{
		vector<vector<int>> distance_between_prefixes(A.size(), vector<int>(B.size(), -1));
		return ComputeDistanceBetweenPrefixes(A, A.size() - 1, B, B.size() - 1, &distance_between_prefixes);
	}
}
