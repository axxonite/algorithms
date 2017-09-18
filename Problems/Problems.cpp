#include "stdafx.h"
#include "Problems/Problems.h"

int main()
{
	BubbleSortTest();
	QuicksortTest();
	
	// 5. Primitives
	MultiplyShiftAddTest();
	DivideTest();
	IsPalindromeNumberTest();
	RectangleIntersectionTest();
	PowerTest();
	ClosestIntSameBitCountTest();

	// 6. Arrays
	DutchFlagPartitionTest();
	RotateMatrixTest();
	TestGeneratePrimes();
	NextPermutationTest();
	BuyAndSellStockTwiceTest();
	ComputeRandomPermutationTest();
	RandomSubsetTest();
	OnlineRandomSampleTest();

	// 7. Strings
	InterconvertStringIntTest();
	SpreadsheetEncodingTest();
	RomanToIntegerTest();

	// 8. Lists
	OverlappingListsTest();
	CyclicallyRightShiftListTest();
	RemoveKthLastTest();

	// 9. Stacks & Queues
	StackTest();
	TestQueueWithMax();
	ExamineBuildingsWithSunsetTest();
	BinaryTreeDepthOrderTest();
	CircularQueueTest();
	QueueTest();

	// 10. Binary Trees
	BSTInSortedOrderTest();
	ExteriorBinaryTreeTest();
	BinaryTreeFromPreorderInorderTest();
	LCATest();

	// 11. Heaps
	KLargestInBinaryHeapTest();
	OnlineMedianTest();

	// 12. Searching
	SquareRootTest();
	FindDuplicateMissingTest();

	// 13. Hash Tables
	LongestContainedRangeTest();

	// 14. Sorting
	UnionOfIntervalsTest();
	
	// 15. Binary Search Trees
	AddCreditsTest();
	FindClosestElementsInSortedArraysTest();

	// 16. Recursion
	SolveNQueensTest();
	CombinationsTest();
	PermutationsTest();
	GeneratePowerSetTest();
	PalindromePartitioningTest();
	GenerateAllBinaryTreesTest();
	ComputeDiameterTest();

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
	GetMaxTrappedWaterTest();

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
	BuildBSTFromSortedDoublyListTest();
}
