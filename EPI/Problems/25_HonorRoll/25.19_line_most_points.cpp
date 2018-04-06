// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

long long GCD( long long x, long long y );

struct Point 
{
	// Equal function for hash.
	bool operator==( const Point& that ) const 
	{
		return x == that.x && y == that.y;
	}

	int x, y;
};


struct Rational 
{
	bool operator==( const Rational& that ) const 
	{
		return numerator == that.numerator && denominator == that.denominator;
	}

	int numerator, denominator;
};

struct Line 
{
	// Equal function for Line.
	bool operator==( const Line& that ) const 
	{
		return slope == that.slope && intercept == that.intercept;
	}

	// slope is a rational number. Note that if the line is parallel to y-axis that we store 1/0.
	Rational slope;
	// intercept is a rational number for the y-intercept unless the line is parallel to y-axis in which case it is the x-intercept.
	Rational intercept;
};

// The bulk of the difficulty here is defining all the auxiliary structures above to ensure we can convert the lines and points into hashes.
// We find the line between each pair of points and create a hash to disambiguate identical lines (same slope and intercept).
// To each line, we add the set of points that are on the line, again using a set so as to avoid counting the same point twice.
// We then simply return the line with the most points.
Line FindLineWithMostPoints( const vector<Point>& p )
{
	return Line();
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
	for ( int times = 0; times < 20; ++times ) 
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
		Line l = FindLineWithMostPoints( points );
		cout << l.slope.numerator << " " << l.slope.denominator << " "
			<< l.intercept.numerator << " " << l.intercept.denominator << endl;
	}
#endif
}

#pragma endregion
