// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct LineSegment 
{
	int left, right;  // Specifies the interval.
	int color;
	int height;
};

vector<LineSegment> CalculateViewFromAbove( const vector<LineSegment>& A )
{
	return {};
}

#pragma region Test

void CalculateViewFromAboveSimpleTest() {
	vector<LineSegment> A = { LineSegment{ 1, 2, 0, 1 }, LineSegment{ 3, 4, 0, 1 } };
	auto result = CalculateViewFromAbove( A );
	vector<LineSegment> golden_result = { LineSegment{ 1, 2, 0, 1 },
		LineSegment{ 3, 4, 0, 1 } };
	assert( equal( result.begin(), result.end(), golden_result.begin(),
		golden_result.end(),
		[]( const LineSegment& a, const LineSegment& b ) {
		return a.left == b.left && a.right == b.right &&
			a.color == b.color && a.height == b.height;
	} ) );
}

void CalculateViewFromAboveTest()
{
#if TEST
	CalculateViewFromAboveSimpleTest();
	vector<LineSegment> A = {
		LineSegment{ 0, 4, 0, 0 },     ( LineSegment{ 1, 3, 1, 2 } ),
		( LineSegment{ 2, 7, 2, 1 } ),   ( LineSegment{ 4, 5, 3, 3 } ),
		( LineSegment{ 5, 7, 3, 0 } ),   ( LineSegment{ 6, 10, 0, 2 } ),
		( LineSegment{ 8, 9, 0, 1 } ),   ( LineSegment{ 9, 18, 4, 0 } ),
		( LineSegment{ 11, 13, 3, 2 } ), ( LineSegment{ 12, 15, 4, 1 } ),
		( LineSegment{ 14, 15, 2, 2 } ), ( LineSegment{ 16, 17, 3, 2 } ) };
	auto result = CalculateViewFromAbove( A );
	vector<LineSegment> golden_result = {
		LineSegment{ 0, 1, 0, 0 },   LineSegment{ 1, 3, 1, 2 },
		LineSegment{ 3, 4, 2, 1 },   LineSegment{ 4, 5, 3, 3 },
		LineSegment{ 5, 6, 2, 1 },   LineSegment{ 6, 10, 0, 2 },
		LineSegment{ 10, 11, 4, 0 }, LineSegment{ 11, 13, 3, 2 },
		LineSegment{ 13, 14, 4, 1 }, LineSegment{ 14, 15, 2, 2 },
		LineSegment{ 15, 16, 4, 0 }, LineSegment{ 16, 17, 3, 2 },
		LineSegment{ 17, 18, 4, 0 } };
	assert( equal( result.begin(), result.end(), golden_result.begin(),
		golden_result.end(),
		[]( const LineSegment& a, const LineSegment& b ) {
		return a.left == b.left && a.right == b.right &&
			a.color == b.color && a.height == b.height;
	} ) );
#endif
}

#pragma endregion
