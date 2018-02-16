#include "stdafx.h"

#define TEST 1

unique_ptr<BSTNode<int>> ReconstructBSTPreorder( const vector<int>& a )
{
	return nullptr;
}

#pragma region Test

void TestBST( unique_ptr<BSTNode<int>>& node )
{
	if ( !node )
		return;
	assert( !node->left || node->left->data < node->data );
	assert( !node->right || node->right->data > node->data );
	TestBST( node->left );
	TestBST( node->right );
}

void ReconstructBSTPreorderTest()
{
	vector<int> values = { 10, 5, 2, 7, 6, 15, 12, 18, 17 };
	auto root = ReconstructBSTPreorder( values );
	TestBST( root );
}

#pragma endregion Test
