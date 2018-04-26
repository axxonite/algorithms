// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

vector<unique_ptr<BinaryTreeNode<int>>> GenerateAllBinaryTrees( int nodeCount )
{
	vector<unique_ptr<BinaryTreeNode<int>>> result;
	return result;
}

#pragma region Test

void GenerateAllBinaryTreesSmallTest()
{
	assert(GenerateAllBinaryTrees(1).size() == 1);
	assert(GenerateAllBinaryTrees(2).size() == 2);
	assert(GenerateAllBinaryTrees(3).size() == 5);
	assert(GenerateAllBinaryTrees(4).size() == 14);
	assert(GenerateAllBinaryTrees(5).size() == 42);
	assert(GenerateAllBinaryTrees(10).size() == 16796);
}

// This isn't really a test.

void GenerateAllBinaryTreesTest()
{
#if TEST
	GenerateAllBinaryTreesSmallTest();
	default_random_engine gen((random_device())());
	int n;
	uniform_int_distribution<int> dis(1, 10);
	n = dis(gen);
	//cout << "n = " << n << endl;
	GenerateAllBinaryTrees(n);
#endif
}

#pragma endregion Test
