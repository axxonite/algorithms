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
	BuyAndSellStockTwiceTest();
	TestGeneratePrimes();
	NextPermutationTest();
	OnlineRandomSampleTest();
	ComputeRandomPermutationTest();
	RandomSubsetTest();
	NonuniformRandomNumberGenerationTest();
	IsValidSudokuTest();
	MatrixInSpiralOrderTest();
	RotateMatrixTest();

	// 7. Strings
	InterconvertStringIntTest();
	ConvertBaseTest();
	SpreadsheetEncodingTest();
	ReplaceAndRemoveTest();
	IsPalindromeTest();
	ReverseWordsTest();
	PhoneMnemonicTest();
	LookAndSayTest();
	RomanToIntegerTest();
	GetValidIPAddressTest();
	SnakeStringTest();
	RLEEncodingTest();
	RabinKarpTest();

	// 8. Lists
	ReverseSublistTest();
	OverlappingListsTest();
	DeletionFromListTest();
	RemoveKthLastTest();
	RemoveDuplicatesTest();
	CyclicallyRightShiftListTest();
	EvenOddMergeTest();
	IsLinkedListAPalindromeTest();
	ListPivotingTest();
	AddTwoNumbersTest();

	// 9. Stacks & Queues
	StackTest();
	EvalRPNTest();
	IsWellFormedTest();
	ShortestEquivalentPathTest();
	SetJumpOrderTest();
	ExamineBuildingsWithSunsetTest();
	BinaryTreeDepthOrderTest();
	CircularQueueTest();
	QueueTest();
	QueueWithMaxTest();

	// 10. Binary Trees
	IsBalancedTest();
	CheckSymmetricTest();
	LCATest();
	LCAParentTest();
	SumRootToLeafTest();
	HasPathSumTest();
	BSTInSortedOrderTest();
	PreorderTraversalTest();
	FindKthNodeBinaryTreeTest();
	FindSuccessorTest();
	InorderTraversalTest();
	BinaryTreeFromPreorderInorderTest();
	CreateListOfLeavesTest();
	ExteriorBinaryTreeTest();
	ConstructRightSiblingTest();
	BinaryTreeNodeLockableTest();

	// 11. Heaps
	SortKIncreasingDecreasingArrayTest();
	SortApproximatelySortedDataTest();
	FindClosestKStarsTest();
	OnlineMedianTest();
	KLargestInBinaryHeapTest();
	StackQueueHeapTest();

	// 12. Searching
	SearchFirstOfKTest();
	SearchEntryEqualToItsIndexTest();
	SearchSmallestTest();
	SquareRootTest();
	SquareRootFloatTest();
	MatrixSearchTest();
	FindMinMaxTest();
	FindKthTest();
	FindMissingElementTest();
	FindDuplicateMissingTest();

	// 13. Hash Tables
	IsLetterConstructibleFromMagazineTest();
	LRUCacheTest();
	LCA2Test();
	KMostFrequentEntriesTest();
	FindNearestRepetitionTest();
	FindSmallestSubarrayCoveringSetTest();
	FindSmallestSequentiallyCoveringSubsetTest();
	LongestSubarrayWithDistinctEntriesTest();
	LongestContainedRangeTest();
	FindStudentWithHighestBestOfThreeScoresTest();
	FindAllSubstringsTest();
	TestCollatzConjectureTest();
	ChessHashTest();

	// 14. Sorting
	MergeTwoSortedArraysTest();
	EliminateDuplicateTest();
	FindMaxSimultaneousEventsTest();
	AddIntervalTest();
	UnionOfIntervalsTest();
	GroupByAgeTest();
	TeamPhotoTest();
	StableSortListTest();
	FindSalaryCapTest();
	
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

	// 17. Dynamic Programming
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
