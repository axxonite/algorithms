// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Shared.h"

namespace Solutions
{
	string FindStudentWithHighestBestOfThreeScores( ifstream* nameScoreData )
	{
		unordered_map<string, priority_queue<int, vector<int>, greater<>>> students;
		string student;
		int score;
		while ( *nameScoreData >> student >> score )
		{
			students[student].emplace( score );
			if ( students[student].size() > 3 )
				students[student].pop();
		}
		string bestStudent;
		int bestScore = -1;
		for ( auto it = students.begin(); it != students.end(); ++it )
		{
			if ( it->second.size() == 3 )
			{
				int avg = 0;
				while ( !it->second.empty() )
				{
					avg += it->second.top();
					it->second.pop();
				}
				if ( avg > bestScore )
				{
					bestScore = avg;
					bestStudent = it->first;
				}
			}
		}

		return bestStudent;
	}
}