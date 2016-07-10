#include "stdafx.h"
#include "BinarySearchTrees.h"
#include "BinaryTrees.h"

using namespace std;

// ----------------------------------------------------------
// 15.1* TEST IF A BINARY TREE SATISFIES THE BST PROPERTY
bool IsBinaryTreeBST(TreeNodePtr node)
{
	// There are several approaches: recursively pass a valid bound and check the tree against it, do an in-order traversal and check that all nodes are in order, or do a BFS with a queue and store the constraint in the queue.
	return false;
}

// ----------------------------------------------------------
// 15.2 FIND THE FIRST KEY GREATER THAN GIVEN VALUE IN A BST
TreeNodePtr FindFirstKeyGreaterThanValue(TreeNodePtr tree, int k)
{
	// If node value is < k, than search right, otherwise search left and keep going till the end of the tree. Keep a min, and if no min is found at the end of a left side traversal, go back up and check the right side of the tree.
	return TreeNodePtr();
}

// ----------------------------------------------------------
// 15.3 FIND THE LARGEST ELEMENTS IN A BST*
vector<int> FindKLargestElements(TreeNodePtr tree)
{
	// Do a reversed in-order traversal, visiting right children before left children, stopping once we have k elements.
	return vector<int>();
}

// ----------------------------------------------------------
// 15.4 COMPUTE THE LCA IN A BST
TreeNodePtr FindLCA(TreeNodePtr tree, TreeNodePtr s, TreeNodePtr b)
{
	// Note that s is smaller. If current node is s or b, then this is LCA; if s < current node and b > current node then this is LCA, if both are larger than current node than LCA is on the right, if both are smaller 
	// then LCA is on the left.
	return TreeNodePtr();
}

// ----------------------------------------------------------
// 15.5 RECONSTRUCT A BST FROM TRAVERSAL DATA*
TreeNodePtr ReconstructBST(const vector<int> preorder)
{
	// Root is first in the pre-order, then left entries are all < root and right entries are all > right. Left entries and right entries are subtrees which form the basis for another root recursively.
	return TreeNodePtr();
}

// ----------------------------------------------------------
// 15.6 FIND THE CLOSEST ENTRIES IN THREE SORTED ARRAYS**
int FindClosestEntriesInSortedArrays(const vector<vector<int>> arrays)
{
	// Start with the first element from each array and let their interval be [s, t]. [s, t] is by definition the smallest interval starting at s; then replace s with the next entry from that array. For the smallest element s, 
	// the other two are the smallest elements from the other arrays that are >= s. No other elements from the other arrays would make the interval any smaller. Keep replacing the smallest value with the value from that array,
	// will iterate through all elements, and track the smallest interval.
	return 0;
}

// ----------------------------------------------------------
// 15.7 ENUMERATE NUMBERS OF THE FORM A + B * SQRT(2)
struct ABSqrt2
{
	int a, b;
	double val;
};

vector<ABSqrt2> GenerateFirstKABSqrt2(int k)
{
	// Add zero. Track two sets of condidates: x + 1, x + sqrt(2). Add whoever is smaller, and replace that candidate with the next value in that sequence. Keep going until you've enummerated k candidates.
	return vector<ABSqrt2>();
}

// ----------------------------------------------------------
// 15.8 THE MOST VISITED PAGES PROBLEM
//
// Use a hash table for the page counts and a BST tree for getting the k biggest elements. The hash table maps to nodes in the BST tree. The solution to problem 12.8 is also applicable.

// ----------------------------------------------------------
// 15.9 BUILD A MINIMUM HEIGHT BST FROM A SORTED ARRAY
TreeNodePtr BuildMinHeightBSTFromSortedArray(const vector<int>& a)
{
	// The root is n/2, then divide each side by half, and so forth.
	return TreeNodePtr();
}

// ----------------------------------------------------------
// 15.10 INSERTION AND DELETION IN A BST*
//
class BinarySearchTree
{
public :

	bool Insert(int key)
	{
		// Search for input key, if it exists, return false, otherwise add a node where the search ended.
		return false;
	}

	bool Delete(int key)
	{
		// If zero children, delete the leaf. If one child, delete the node and replace with its child. If two children, replace contents with successor node's contents and delete successor node. The successor node has to be
		// a right child of its parent and has no left child, so it is easy to delete it by removing it and replacing it with its right child, if any.
		return false;
	}

private :

	TreeNodePtr root;
};

// ----------------------------------------------------------
// 15.11 TEST IF THREE BST NODES ARE TOTALLY ORDERED
bool TestIfPairIncludesAncestorDescendantOfM(TreeNodePtr a, TreeNodePtr b, TreeNodePtr m)
{
	// Search for middle value and see if we encounter a or b. If not, then the test fails. If we do, see if the other node's key lies in the valid range to be a child of the middle node.
	// This differs from the book's solution which is to perform an interleaved search for both nodes until you encounter the middle from either search. Once middle is found starting from one node, search for other node from 
	// the middle.
	return false;
}

struct Interval
{
	int left, right;
};

// ----------------------------------------------------------
// 15.12 THE RANGE LOOKUP PROBLEM
vector<int> RangeLookupInBST(TreeNodePtr tree, const Interval& interval)
{
	// If value x < a, left children do not contain candidates, if x > b, left children do not contain candidates, otherwise walk both branches. O(m+h) for this is tricky.
	return vector<int>();
}

// ----------------------------------------------------------
// 15.3 ADD CREDITS
//
// Use a hash table to map clients to credits and a BST tree to keep clients sorted by credit. For the AddToAll() function, add the value to a global offset that is added to every returned result. If new clients are added or
// changed after the offset is zero, simply subtract the offset from the inserted credit for that client so that the resulting value ends up being the value being inserted when the global credit offset is added in.
class ClientsCreditsInfo
{
public :

	void Insert(const string& client, int c)
	{
	}

	bool Remove(const string& client)
	{
		return false;
	}

	int Lookup(const string& client)
	{
		return 0;
	}

	void AddToAll(int c)
	{
	}
};
