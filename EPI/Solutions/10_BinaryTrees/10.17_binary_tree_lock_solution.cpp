// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	class BinaryTreeNodeLockable
	{
	public:
		bool IsLocked() const
		{
			return locked_;
		}

		bool Lock()
		{
			if ( lockedDescendants_ || locked_ )
				return false;
			for ( auto cur = parent_; cur; cur = cur->parent_ )
			{
				if ( cur->locked_ )
					return false;
			}
			for ( auto cur = parent_; cur; cur = cur->parent_ )
				cur->lockedDescendants_++;
			locked_ = true; // Missing a detail here... ugh. Checklist: verify that every variable is updated correctly. There's only two.
			return true;
		}

		void Unlock()
		{
			if ( locked_ )
			{
				locked_ = false;
				for ( auto cur = parent_; cur; cur = cur->parent_ )
					cur->lockedDescendants_--;
			}
		}

		shared_ptr<BinaryTreeNodeLockable>& left() { return left_; }
		shared_ptr<BinaryTreeNodeLockable>& right() { return right_; }
		shared_ptr<BinaryTreeNodeLockable>& parent() { return parent_; }
	private:

		bool locked_ = false;
		int lockedDescendants_ = 0;
		shared_ptr<BinaryTreeNodeLockable> left_, right_, parent_;
	};
}