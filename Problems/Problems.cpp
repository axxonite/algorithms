#include "stdafx.h"
#include "Problems/Problems.h"

int main()
{
	BubbleSortTest();
	QuicksortTest();
	
	// 5. Primitives
	MultiplyShiftAddTest();
	DivideTest();
	BuyAndSellStockTwiceTest();
	IsPalindromeNumberTest();
	RectangleIntersectionTest();
	
	// 7. Strings
	SpreadsheetEncodingTest();

	// 8. Lists
	OverlappingListsTest();
	CyclicallyRightShiftListTest();

	// 9. Stacks & Queues
	StackTest();
	TestQueueWithMax();
	ExamineBuildingsWithSunsetTest();

	// 10. Binary Trees
	BSTInSortedOrderTest();
	ExteriorBinaryTreeTest();

	// 12. Searching
	FindDuplicateMissingTest();

	// 14. Sorting
	UnionOfIntervalsTest();
	
	// 15. Binary Search Trees
	AddCreditsTest();

	// 16. Recursion
	CombinationsTest();
	PermutationsTest();

	// 17. Dynamic Progamming
	NumCombinationsForFinalScoreTest();
	LevenshteinDistanceTest();
	ComputeMaximumRevenueForRangeTest();
	LongestNondecreasingSubsequenceLengthTest();
	MinimumMessinessTest();

	// 18. Greedy Algorithms
	HasThreeSumTest();
	OptimumTaskAssignmentTest();
	MinimumTotalWaitingTimeTest();
	MajoritySearchTest();
	CalculateLargestRectangleTest();

	// 25. Honor Roll
	ComputeSkylineTest();
	GetHeightTest();
	IsMatchTest();
	SearchFrequentItemsTest();
	FindLongestSubarrayLessEqualKTest();
}
