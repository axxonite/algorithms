// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

long long GCD( long long x, long long y );

struct Point 
{
	bool operator==( const Point& that ) const 
	{
		return x == that.x && y == that.y;
	}

	int x = 0, y = 0;
};

struct HashPoint
{
	size_t operator() (const Point& p) const
	{
		return hash<int>()(p.x) ^ hash<int>()(p.y);
	}
};

struct Line 
{
	Line() {}

	// Equal function for Line.
	bool operator==( const Line& that ) const 
	{
		return false;
	}
};

int FindLineWithMostPoints( const vector<Point>& p, Line& result )
{
	return 0;
}

#pragma region Test

#if TEST

// n^3 checking
int FindLineWithMostPointsCheck( const vector<Point>& P ) 
{
	int max_count = 0;
	for ( int i = 0; i < P.size(); ++i ) 
	{
		for ( int j = i + 1; j < P.size(); ++j ) 
		{
			int count = 2;
			Line temp( P[i], P[j] );
			for ( int k = j + 1; k < P.size(); ++k )
			{
				if ( Line( P[i], P[k] ) == temp ) 
					++count;
			}
			max_count = max( max_count, count );
		}
	}

	return max_count;
}
#endif

void FindLineWithMostPointsTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 10; ++times ) 
	{
		cout << times << endl;
		int n;
		// Needs at least two points to form a line.
		uniform_int_distribution<int> dis( 2, 100 );
		n = dis( gen );
		vector<Point> points;
		unordered_set<Point, HashPoint> t;
		do {
			uniform_int_distribution<int> dis( 0, 999 );
			Point p{ dis( gen ), dis( gen ) };
			if ( t.find( p ) == t.cend() )
			{
				points.push_back( p );
				t.emplace( p );
			}
		} while ( t.size() < n );
		/*
		for (int i = 0; i < points.size(); ++i) {
		cout << points[i].x << ", " << points[i].y << endl;
		}
		*/
		Line l;
		int count = FindLineWithMostPoints(points, l);
		int count2 = FindLineWithMostPointsCheck(points);
		assert(count == count2);
		cout << l.slope.numerator << " " << l.slope.denominator << " "
			<< l.intercept.numerator << " " << l.intercept.denominator << endl;
	}
#endif
}

#pragma endregion
