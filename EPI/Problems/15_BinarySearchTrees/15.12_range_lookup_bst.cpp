// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

struct Interval
{
	int left, right;
};

vector<int> RangeLookupInBST(const unique_ptr<BSTNode<int>>& tree, const Interval& interval)
{
	vector<int> result;
	return result;
}

#pragma region Test

void RangeLookupInBSTTest()
{
#ifdef TEST
	//          19
	//     7          43
	//   3   11    23   47
	// 2  5    17   37    53
	//        13  29  41
	//             31	
	unique_ptr<BSTNode<int>> tree = make_unique<BSTNode<int>>(BSTNode<int>{19});
	tree->left = make_unique<BSTNode<int>>(BSTNode<int>{7});
	tree->left->left = make_unique<BSTNode<int>>(BSTNode<int>{3});
	tree->left->left->left = make_unique<BSTNode<int>>(BSTNode<int>{2});
	tree->left->left->right = make_unique<BSTNode<int>>(BSTNode<int>{5});
	tree->left->right = make_unique<BSTNode<int>>(BSTNode<int>{11});
	tree->left->right->right = make_unique<BSTNode<int>>(BSTNode<int>{17});
	tree->left->right->right->left =
		make_unique<BSTNode<int>>(BSTNode<int>{13});
	tree->right = make_unique<BSTNode<int>>(BSTNode<int>{43});
	tree->right->left = make_unique<BSTNode<int>>(BSTNode<int>{23});
	tree->right->left->right = make_unique<BSTNode<int>>(BSTNode<int>{37});
	tree->right->left->right->left =
		make_unique<BSTNode<int>>(BSTNode<int>{29});
	tree->right->left->right->left->right =
		make_unique<BSTNode<int>>(BSTNode<int>{31});
	tree->right->left->right->right =
		make_unique<BSTNode<int>>(BSTNode<int>{41});
	tree->right->right = make_unique<BSTNode<int>>(BSTNode<int>{47});
	tree->right->right->right = make_unique<BSTNode<int>>(BSTNode<int>{53});
	auto result = RangeLookupInBST(tree, {16, 31});
	sort(result.begin(), result.end());
	vector<int> golden_result = {17, 19, 23, 29, 31};
	assert(equal(result.begin(), result.end(), golden_result.begin(),
		golden_result.end()));

	result = RangeLookupInBST(tree, {38, 39});
	assert(result.empty());

	result = RangeLookupInBST(tree, {38, 42});
	assert((1 == result.size()) && (41 == result[0]));

	result = RangeLookupInBST(tree, {-1, 1});
	assert(result.empty());

	result = RangeLookupInBST(
		tree, {numeric_limits<int>::max() - 1, numeric_limits<int>::max()});
	assert(0 == result.size());
#endif
}

#pragma endregion Test
