// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

#define TEST 0

class BinarySearchTree
{
public:
	bool Empty() const { return !root.get(); }

	bool Insert(int key)
	{
		return true;
	}

	bool Delete(int key)
	{
		return true;
	}

	int GetRootVal() const { return root->data; }

private:
	unique_ptr<BinaryTreeNode<int>> root = nullptr;
};

#pragma region Test

void BSTInsertDeleteTest()
{
#if TEST
	BinarySearchTree BST;
	assert(BST.Empty() == true);
	assert(BST.Insert(7) == true);
	assert(BST.Insert(8) == true);
	assert(BST.Insert(9) == true);
	assert(BST.Insert(4) == true);
	assert(BST.Insert(3) == true);
	assert(BST.Empty() == false);
	assert(BST.Insert(2) == true);
	assert(BST.Insert(5) == true);
	assert(BST.Delete(7) == true);
	assert(BST.Delete(9) == true);
	// should output 8
	assert(BST.GetRootVal() == 8);
	cout << BST.GetRootVal() << endl;
	assert(BST.Delete(4) == true);
	// should output 8
	assert(BST.GetRootVal() == 8);
	cout << BST.GetRootVal() << endl;
	assert(BST.Delete(8) == true);
	// should output 5
	assert(BST.GetRootVal() == 5);
	cout << BST.GetRootVal() << endl;
	assert(BST.Delete(5) == true);
	assert(BST.Delete(3) == true);
	// should output 2
	assert(BST.GetRootVal() == 2);
	cout << BST.GetRootVal() << endl;
	assert(BST.Delete(2) == true);
	assert(BST.Delete(1) == false);
	assert(BST.Empty() == true);
	BST.Insert(7);
	assert(BST.GetRootVal() == 7);
	BST.Insert(9);
	assert(BST.GetRootVal() == 7);
	BST.Delete(7);
	assert(BST.GetRootVal() == 9);
#endif
}

#pragma endregion Test
