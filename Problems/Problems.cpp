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
	CyclicallyRightShiftListTest();

	// 9. Stacks & Queues
	StackTest();
	TestQueueWithMax();

	// 10. Binary Trees
	BSTInSortedOrderTest();

	// 12. Searching
	FindDuplicateMissingTest();
	
	// 15. Binary Search Trees
	AddCreditsTest();

	// 16. Recursion
	CombinationsTest();
	PermutationsTest();

	// 17. Dynamic Progamming
	ComputeMaximumRevenueForRangeTest();
	LongestNondecreasingSubsequenceLengthTest();
	MinimumMessinessTest();

	// 18. Greedy Algorithms
	OptimumTaskAssignmentTest();
	MinimumTotalWaitingTimeTest();
	MajoritySearchTest();

	// 25. Honor Roll
	GetHeightTest();
	IsMatchTest();
	SearchFrequentItemsTest();
	FindLongestSubarrayLessEqualKTest();
}
