// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "binary_tree_prototype.h"

namespace Solutions
{
	class BinarySearchTree
	{
	public:
		bool Empty() const { return !root.get(); }

		bool Insert(int key)
		{
			// If there is no root, then make a new root with the new key.
			if (root == nullptr)
				root = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{key, nullptr, nullptr});
			else
			{
				BinaryTreeNode<int> *curr = root.get(), *parent = nullptr;
				// perform a binary search.
				while (curr)
				{
					parent = curr; // keep track of the last non-null node.
					if (key == curr->data)
						return false; // key already present, no duplicates to be added.
					if (key < curr->data)
						curr = curr->left.get();
					else curr = curr->right.get();
				}

				// Inserts key according to its value with respect to the last non-null node found.
				if (key < parent->data)
					parent->left.reset(new BinaryTreeNode<int>{ key });
				else parent->right.reset(new BinaryTreeNode<int>{ key });
			}
			return true;
		}

		bool Delete(int key)
		{
			// Find the node with key.
			BinaryTreeNode<int>* c = root.get(), *parent = nullptr;
			while (c && c->data != key)
			{
				parent = c;
				c = key < c->data ? c->left.get() : c->right.get();
			}

			if (!c)
				return false; // There's no node with key in this tree.

			BinaryTreeNode<int>* keyNode = c;
			if (keyNode->right)
			{
				// Find the successor.
				BinaryTreeNode<int>* successor = keyNode->right.get(), *sParent = keyNode;
				while (successor->left)
				{
					sParent = successor;
					successor = successor->left.get();
				}

				// Replace the key node data with the successor's data.
				keyNode->data = successor->data;
				// Moves links to erase the node. Whichever child path the successor is on gets released.
				// The successor always has only a right child.
				if (sParent->left.get() == successor)
					sParent->left.reset(successor->right.release());
				else sParent->right.reset(successor->right.release()); // r_parent->right.get() == r_key_node.
			}
			else
			{
				// Updates root link if needed.
				if (root.get() == keyNode)
					root.reset(keyNode->left.release());
				else
				{
					// No right child, delete the node directy since the parent only has one child.
					// Whichever child path the node is on gets released from the parent.
					if (parent->left.get() == keyNode)
						parent->left.reset(keyNode->left.release());
					else parent->right.reset(keyNode->left.release()); // parent->right.get() == key_node.
				}
			}
			return true;
		}

		int GetRootVal() const { return root->data; }

	private:
		unique_ptr<BinaryTreeNode<int>> root = nullptr;
	};
}
