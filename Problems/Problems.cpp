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
	PowerTest();

	// 6. Arrays
	DutchFlagPartitionTest();
	RotateMatrixTest();
	TestGeneratePrimes();
	NextPermutationTest();

	// 7. Strings
	InterconvertStringIntTest();
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
	BinaryTreeFromPreorderInorderTest();

	// 12. Searching
	SquareRootTest();
	FindDuplicateMissingTest();

	// 14. Sorting
	UnionOfIntervalsTest();
	
	// 15. Binary Search Trees
	AddCreditsTest();
	FindClosestElementsInSortedArraysTest();

	// 16. Recursion
	SolveNQueensTest();
	CombinationsTest();
	PermutationsTest();
	PalindromePartitioningTest();

	// 17. Dynamic Progamming
	NumCombinationsForFinalScoreTest();
	LevenshteinDistanceTest();
	ComputeMaximumRevenueForRangeTest();
	LongestNondecreasingSubsequenceLengthTest();
	MinimumMessinessTest();
	MinimumPathWeightTest();
	ComputeBinomialCoefficientTest();

	// 18. Greedy Algorithms
	HasThreeSumTest();
	OptimumTaskAssignmentTest();
	MinimumTotalWaitingTimeTest();
	MajoritySearchTest();
	CalculateLargestRectangleTest();

	// 19. Graphs
	IsAnyPlacementFeasibleTest();

	// 25. Honor Roll
	ComputeSkylineTest();
	GetHeightTest();
	IsMatchTest();
	SearchFrequentItemsTest();
	FindLongestSubarrayLessEqualKTest();
	IsArbitrageExistTest();
	CountInversionsTest();
	FindPairSumKTest();
}
