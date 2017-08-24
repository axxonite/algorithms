// Copyright (c) 2016 Elements of Programming Interviews. All rights reserved.

#pragma once
#include <memory>
#include <vector>
#include "./Binary_tree_prototype.h"
#include "Solutions/10_BinaryTrees/10.13_reconstruct_preorder_with_null_solution.h"

using namespace std;

inline unique_ptr<BinaryTreeNode<int>> ReconstructPreorder(const vector<int*>& preorder)
{
	return Solutions::ReconstructPreorder(preorder);
}