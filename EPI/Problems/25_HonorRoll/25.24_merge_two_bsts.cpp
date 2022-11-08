// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

shared_ptr<BSTNodeShared<int>> MergeTwoBSTs( shared_ptr<BSTNodeShared<int>> A, shared_ptr<BSTNodeShared<int>> B )
{
  return nullptr;
}

#pragma region Test

template <typename T>
void PrintBSTInorder( shared_ptr<BSTNodeShared<T>> n, const T& pre ) {
	if ( n ) {
		PrintBSTInorder( n->left, pre );
		assert( pre <= n->data );
		cout << n->data << ' ';
		PrintBSTInorder( n->right, n->data );
	}
}

// Note: there is no actual test here, it just prints out the tree values.
void MergeTwoBSTsTest()
{
#ifdef TEST
	//      3
	//    2   5
	//  1    4 6
	auto L = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{3} );
	L->left = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{2} );
	L->left->left = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{1} );
	L->right = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{5} );
	L->right->left = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{4} );
	L->right->right = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{6} );
	//     7
	//   2   8
	// 0
	auto R = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{7} );
	R->left = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{2} );
	R->left->left = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{0} );
	R->right = make_shared<BSTNodeShared<int>>( BSTNodeShared<int>{8} );
	shared_ptr<BSTNodeShared<int>> root = MergeTwoBSTs( L, R );
	// should output 0 1 2 2 3 4 5 6 7 8
	PrintBSTInorder( root, numeric_limits<int>::min() );
#endif
}

#pragma endregion
