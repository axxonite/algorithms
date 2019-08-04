// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	long long GCD( long long x, long long y )
	{
		return 0; // todo define this.
	}

	struct Point
	{
		// Equal function for hash.
		bool operator==( const Point& that ) const
		{
			return x == that.x && y == that.y;
		}

		int x, y;
	};

	struct HashPoint
	{
		size_t operator() ( const Point& p ) const
		{
			return hash<int>()( p.x ) ^ hash<int>()( p.y );
		}
	};

	struct Rational
	{
		bool operator==( const Rational& that ) const
		{
			return numerator == that.numerator && denominator == that.denominator;
		}

		int numerator, denominator;
	};

	Rational GetCanonicalForm( int a, int b )
	{
		int gcd = GCD( abs( a ), abs( b ) ); // note that we need to take absolute values for the GCD.
		a /= gcd, b /= gcd;
		return b < 0 ? Rational{ -a, -b } : Rational{ a, b };
	}

	struct Line
	{
		Line( const Point& a, const Point& b )
		{
			// Note the special cases for when the line is vertical.
			slope = a.x != b.x ? GetCanonicalForm( b.y - a.y, b.x - a.x ) : Rational{ 1, 0 };
			intercept = a.x != b.x ? GetCanonicalForm( b.x * a.y - a.x * b.y, b.x - a.x ) : Rational{ 0, a.y };
		}

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

	struct HashLine
	{
		size_t operator()( const Line& l ) const
		{
			return hash<int>()( l.slope.numerator ) ^ hash<int>() ( l.slope.denominator ) ^ hash<int>()( l.intercept.numerator ) ^ hash<int>()( l.intercept.denominator );
		}
	};

	// The bulk of the difficulty here is defining all the auxiliary structures above to ensure we can convert the lines and points into hashes.
	// We find the line between each pair of points and create a hash to disambiguate identical lines (same slope and intercept).
	// To each line, we add the set of points that are on the line, again using a set so as to avoid counting the same point twice.
	// We then simply return the line with the most points.
	Line FindLineWithMostPoints( const vector<Point>& p )
	{
		unordered_map<Line, unordered_set<Point, HashPoint>, HashLine> lines;
		for ( int i = 0; i < p.size(); ++i )
		{
			for ( int j = i + 1; j < p.size(); ++j )
			{
				Line l( p[i], p[j] );
				lines[l].emplace( p[i] ), lines[l].emplace( p[j] );
			}
		}
		return max_element( lines.cbegin(), lines.cend(), []( const auto& a, const auto& b ) { return a.second.size() < b.second.size(); } )->first;
	}
}