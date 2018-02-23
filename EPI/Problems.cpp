#include "stdafx.h"
#include "Problems/Problems.h"

int main()
{
	BubbleSortTest();
	QuicksortTest();
	MergeSortTest();
	
	// 5. Primitives
	ReverseBitsTest();
	MultiplyShiftAddTest();
	DivideTest();
	IsPalindromeNumberTest();
	RectangleIntersectionTest();
	PowerTest();
	ClosestIntSameBitCountTest();
	UniformRandomTest();

	// 6. Arrays
	DutchFlagPartitionTest();
	PlusOneTest();
	MultiplyTest();
	CanReachEndTest();
	DeleteDuplicatesTest();
	BuyAndSellStockOnceTest();
	RotateMatrixTest();
	TestGeneratePrimes();
	NextPermutationTest(); 
	BuyAndSellStockTwiceTest();
	ComputeRandomPermutationTest();
	RandomSubsetTest();
	NonuniformRandomNumberGenerationTest();
	OnlineRandomSampleTest();
	IsValidSudokuTest();
	MatrixInSpiralOrderTest();

	// 7. Strings
	InterconvertStringIntTest();
	SpreadsheetEncodingTest();
	RomanToIntegerTest();
	ReverseWordsTest();

	// 8. Lists
	OverlappingListsTest();
	CyclicallyRightShiftListTest();
	RemoveKthLastTest();
	ReverseSublistTest();

	// 9. Stacks & Queues
	StackTest();
	TestQueueWithMax();
	ExamineBuildingsWithSunsetTest();
	BinaryTreeDepthOrderTest();
	CircularQueueTest();
	QueueTest();

	// 10. Binary Trees
	FindSuccessorTest();
	BSTInSortedOrderTest();
	ExteriorBinaryTreeTest();
	BinaryTreeFromPreorderInorderTest();
	LCATest();

	// 11. Heaps
	KLargestInBinaryHeapTest();
	OnlineMedianTest();
	SortApproximatelySortedDataTest();

	// 12. Searching
	SquareRootTest();
	FindDuplicateMissingTest();
	FindMissingElementTest();
	SquareRootFloatTest();
	FindKthTest();

	// 13. Hash Tables
	LongestContainedRangeTest();
	FindAllSubstringsTest();
	LCA2Test();
	LongestSubarrayWithDistinctEntriesTest();

	// 14. Sorting
	UnionOfIntervalsTest();
	FindSalaryCapTest();
	StableSortListTest();
	MergeTwoSortedArraysTest();
	
	// 15. Binary Search Trees
	AddCreditsTest();
	FindClosestElementsInSortedArraysTest();
	FindLCATest();
	BSTInsertDeleteTest();
	ReconstructBSTPreorderTest();

	// 16. Recursion
	SolveNQueensTest();
	CombinationsTest();
	PermutationsTest();
	GeneratePowerSetTest();
	PalindromePartitioningTest();
	GenerateAllBinaryTreesTest();
	ComputeDiameterTest();
	ComputeTowerHanoiTest();
	SolveSudokuTest();

	// 17. Dynamic Progamming
	NumCombinationsForFinalScoreTest();
	LevenshteinDistanceTest();
	ComputeMaximumRevenueForRangeTest();
	LongestNondecreasingSubsequenceLengthTest();
	MinimumMessinessTest();
	MinimumPathWeightTest();
	ComputeBinomialCoefficientTest();
	OptimumSubjectToCapacityTest();
	DecomposeIntoDictionaryWordsTest();
	NumberOfWaysTest();
	IsPatternContainedInGridTest();
	NumberOfWaysToTopTest();

	// 18. Greedy Algorithms
	HasThreeSumTest();
	OptimumTaskAssignmentTest();
	MinimumTotalWaitingTimeTest();
	MajoritySearchTest();
	CalculateLargestRectangleTest();
	GetMaxTrappedWaterTest();

	// 19. Graphs
	IsAnyPlacementFeasibleTest();
	IsDeadlockedTest();
	TransformStringTest();

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

	CalcContainedWaterTest();
	ComputeSunShadowingTest();
	IsContainedTest();
}
