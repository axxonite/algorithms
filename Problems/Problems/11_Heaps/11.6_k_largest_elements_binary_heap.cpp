// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<int> KLargestInBinaryHeap(const vector<int>& a, int k)
{
	vector<int> result;
	return result;
}
#pragma region Test

void KLargestInBinaryHeapTest()
{                           
#if TEST
	vector<int> max_heap = {10, 2, 9, 2, 2, 8, 8, 2, 2, 2, 2, 7, 7, 7, 7};
	auto result = KLargestInBinaryHeap(max_heap, 3);
	vector<int> expected_result = {10, 9, 8};
	assert(equal(result.begin(), result.end(), expected_result.begin(),
		expected_result.end()));
	result = KLargestInBinaryHeap(max_heap, 5);
	expected_result = {10, 9, 8, 8, 7};
	assert(equal(result.begin(), result.end(), expected_result.begin(),
		expected_result.end()));

	max_heap = {97, 84, 93, 83, 81, 90, 79, 83, 55, 42, 21, 73};
	result = KLargestInBinaryHeap(max_heap, 3);
	expected_result = {97, 93, 90};
	assert(equal(result.begin(), result.end(), expected_result.begin(),
		expected_result.end()));

	max_heap = {100, 1, 5, 0, 0};
	result = KLargestInBinaryHeap(max_heap, 1);
	expected_result = {100};
	assert(equal(result.begin(), result.end(), expected_result.begin(),
		expected_result.end()));
#endif
}

#pragma endregion Test
	