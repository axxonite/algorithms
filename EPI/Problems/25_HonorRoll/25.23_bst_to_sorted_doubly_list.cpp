// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

shared_ptr<BSTNodeShared<int>> BSTToDoublyLinkedList( const shared_ptr<BSTNodeShared<int>>& tree )
{
	return nullptr;
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
