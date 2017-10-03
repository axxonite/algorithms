// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	class BinarySearchTree
	{
	public:
		bool Empty() const { return !root_.get(); }

		bool Insert(int key)
		{
			if (root_ == nullptr)
				root_ = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{key, nullptr, nullptr});
			else
			{
				BinaryTreeNode<int> *curr = root_.get(), *parent = nullptr;
				while (curr)
				{
					parent = curr;
					if (key == curr->data)
						return false; // key already present, no duplicates to be added.
					if (key < curr->data)
						curr = curr->left.get();
					else curr = curr->right.get();
				}

				// Inserts key according to key and parent.
				if (key < parent->data)
					parent->left.reset(new BinaryTreeNode<int>{ key });
				else parent->right.reset(new BinaryTreeNode<int>{ key });
			}
			return true;
		}

		bool Delete(int key)
		{
			// Find the node with key.
			BinaryTreeNode<int>* curr = root_.get(), *parent = nullptr;
			while (curr && curr->data != key)
			{
				parent = curr;
				curr = key < curr->data ? curr->left.get() : curr->right.get();
			}

			if (!curr)
				return false; // There's no node with key in this tree.

			BinaryTreeNode<int>* keyNode = curr;
			if (keyNode->right)
			{
				// Finds the minimum of the right subtree.
				BinaryTreeNode<int>* rKeyNode = keyNode->right.get(), *rParent = keyNode;
				while (rKeyNode->left)
				{
					rParent = rKeyNode;
					rKeyNode = rKeyNode->left.get();
				}
				keyNode->data = rKeyNode->data;
				// Moves links to erase the node.
				if (rParent->left.get() == rKeyNode)
					rParent->left.reset(rKeyNode->right.release());
				else rParent->right.reset(rKeyNode->right.release()); // r_parent->right.get() == r_key_node.
			}
			else
			{
				// Updates root_ link if needed.
				if (root_.get() == keyNode)
					root_.reset(keyNode->left.release());
				else
				{
					if (parent->left.get() == keyNode)
						parent->left.reset(keyNode->left.release());
					else parent->right.reset(keyNode->left.release()); // parent->right.get() == key_node.
				}
			}
			return true;
		}

		int GetRootVal() const { return root_->data; }

	private:
		unique_ptr<BinaryTreeNode<int>> root_ = nullptr;
	};
}
