#include "stdafx.h"
#include <cstdio>
#include "BinarySearchTree.h"

// The BST property is: If y is a node in the left subtree of x, then y.key <= x.key. If y is a node in the right subtree of x, then y.key >= x.key.
template <class T>
class CBinarySearchTree
{
	struct SNode
	{
	public :

		T key;
		SNode* left;
		SNode* right;
		SNode* parent;

		SNode()
		{
			left = right = parent = nullptr;
		}

		void Print()
		{
			stdout << key;
		}
	};


public:

	static SNode Nil;
	SNode* mRoot;

	// O(n)
	void InOrderTreeWalk(SNode& node)
	{
		if (node == Nil)
			return;
		InOrderTreeWalk(node.left);
		node.Print();
		InOrderTreeWalk(node.right);
	}

	// O(h)
	SNode& TreeSearch(SNode& node, T key)
	{
		if (node == Nil || key == node.key)
			return node;
		if (key < node.key)
			return TreeSearch(node.left, key);
		return TreeSearch(node.right, key);
	}

	// O(h)
	SNode& TreeSearchIterative(SNode& node, T key)
	{
		while (node != Nil && node.key != key)
		{
			if (key < node.Key)
				node = node.left;
			else node = node.right;
		}
		return node;
	}

	// O(h)
	T Min(SNode& node)
	{
		while (node.left != Nil)
			node = node.left;
		return node;
	}

	// O(h)
	T Max(SNode& node)
	{
		while (node.right != Nil)
			node = node.right;
		return node;
	}

	// O(h)
	T Successor(SNode& node)
	{
		if (node.right != Nil)
			return Min(node.right);
		auto parent = node.parent;
		// Walk up until we're the left child of a parent, or we get back to the root node
		while (parent != Nil && node == parent.right)
		{
			node = parent;
			parent = parent.parent;
		}
		return parent;
	}

	// O(h)
	void Insert(T key)
	{
		auto newNode = new SNode();
		newNode->key = key;
		auto parent = Nil;
		auto node = mRoot;
		// Walk down until we find an empty child slot to hook unto. This will be our parent.
		while (node != Nil)
		{
			parent = node;
			if (newNode.key < node.key)
				node = node.left;
			else node = node.right;
		}
		// Update the parent link on the node.
		newNode.parent = parent;

		// Update the child link on the parent.
		if (parent == Nil)
			mRoot = newNode; // Tree was empty, since we don't have a parent.
		else if (newNode.key < parent.key)
			parent.left = newNode;
		else parent.right = newNode;
	}

	// O(h)
	void Delete(SNode& node)
	{
		// Case 1 : No left child, replace this node with its right child.
		if (node.left == Nil)
			Transplant(node, node.right);
		// Case 2 : No right child, replace this node with its left child.
		else if (node.right == Nil)
			Transplant(node, node.left);
		else
		{
			// Case 3 : We have two children.
			auto successor = Min(node.right);
			if (successor.parent != node)
			{
				// The successor is further down the subtree. Put the succesor's right child (x), where the successor used to be (at the y slot).
				Transplant(successor, successor.right);
				// Now hook the deleted node's right child (r) to the successor (y).
				successor.right = node.right;
				successor.right.parent = successor;
			}

			// Hook the successor (y) where the node used to be.
			Transplant(node, successor);

			// Hook our left child (l) unto the new node's left branch. The successor had no left child by definition.
			successor.left = node.left;
			successor.left.parent = successor;

			delete &node;
		}
	}

private :

	// O(1)
	void Transplant(SNode& u, SNode& v)
	{
		if (u.parent == Nil)
			mRoot = v;
		else if (u == u.parent.left)
			u.p.left = v;
		else u.p.right = v;
		if (v != Nil)
			v.parent = u.parent;
	}
};
