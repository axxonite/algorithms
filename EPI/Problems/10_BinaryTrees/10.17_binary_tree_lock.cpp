// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

class BinaryTreeNodeLockable 
{
public:
	bool IsLocked() const { return false; }

	bool Lock() 
	{
		return true;
	}

	void Unlock() 
	{
	}

	shared_ptr<BinaryTreeNodeLockable>& left() { return left_; }
	shared_ptr<BinaryTreeNodeLockable>& right() { return right_; }
	shared_ptr<BinaryTreeNodeLockable>& parent() { return parent_; }
private:

	shared_ptr<BinaryTreeNodeLockable> left_, right_, parent_;
};

#pragma region Test

void BinaryTreeNodeLockableTest()
{
#if TEST
	auto root = make_shared<BinaryTreeNodeLockable>( BinaryTreeNodeLockable() );
	root->left() = make_shared<BinaryTreeNodeLockable>( BinaryTreeNodeLockable() );
	root->left()->parent() = root;
	root->right() = make_shared<BinaryTreeNodeLockable>( BinaryTreeNodeLockable() );
	root->right()->parent() = root;
	root->left()->left() = make_shared<BinaryTreeNodeLockable>( BinaryTreeNodeLockable() );
	root->left()->left()->parent() = root->left();
	root->left()->right() = make_shared<BinaryTreeNodeLockable>( BinaryTreeNodeLockable() );
	root->left()->right()->parent() = root->left();

	assert( !root->IsLocked() );
	cout << boolalpha << root->IsLocked() << endl;

	assert( root->Lock() );
	assert( root->IsLocked() );
	cout << boolalpha << root->IsLocked() << endl;
	assert( !root->left()->Lock() );
	assert( !root->left()->IsLocked() );
	assert( !root->right()->Lock() );
	assert( !root->right()->IsLocked() );
	assert( !root->left()->left()->Lock() );
	assert( !root->left()->left()->IsLocked() );
	assert( !root->left()->right()->Lock() );
	assert( !root->left()->right()->IsLocked() );

	root->Unlock();
	assert( root->left()->Lock() );
	assert( !root->Lock() );
	assert( !root->left()->left()->Lock() );
	assert( !root->IsLocked() );

	cout << boolalpha << root->IsLocked() << endl;
	assert( root->right()->Lock() );
	assert( root->right()->IsLocked() );
#endif
}

#pragma endregion