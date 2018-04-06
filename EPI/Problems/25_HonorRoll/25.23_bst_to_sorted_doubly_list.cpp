// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

void BSTToDoublyLinkedListHelper( const shared_ptr<BSTNodeShared<int>>& tree, BSTNodeShared<int>*& last )
{
	if ( !tree )
		return;
	BSTToDoublyLinkedListHelper( tree->left, last );
	tree->left = make_shared<BSTNodeShared<int>>( *last );
	last->right = tree;
	// Here we have a proper link between tree and last. If there is no last, tree->left is null.
	last = tree.get();
	// Last is now our current node, tree.
	auto right = tree->right;
	tree->right = nullptr;
	BSTToDoublyLinkedListHelper( right, last );
	// After this point, tree->right would be assigned to whatever was on the right of that subtree.
}

shared_ptr<BSTNodeShared<int>> BSTToDoublyLinkedList( const shared_ptr<BSTNodeShared<int>>& tree )
{
	BSTNodeShared<int> dummyNode{0, nullptr, nullptr};
	BSTNodeShared<int>* last = &dummyNode;
	BSTToDoublyLinkedListHelper(tree, last);
	return dummyNode.right;
}

#pragma region Test

void BSTToDoublyLinkedListTest()
{
#if TEST
	//    3
	//  2   5
	// 1   4 6
	auto root = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{3} );
	root->left = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{2} );
	root->left->left = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{1} );
	root->right = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{5} );
	root->right->left = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{4} );
	root->right->right = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{6} );
	shared_ptr<BSTNodeShared<int>> L = BSTToDoublyLinkedList( root );
	shared_ptr<BSTNodeShared<int>> curr = L;
	int pre = numeric_limits<int>::min();
	do {
		assert( pre <= curr->data );
		cout << curr->data << endl;
		pre = curr->data;
		curr = curr->right;
	} while ( curr );
#endif
}

#pragma endregion
