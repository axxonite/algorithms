#include "stdafx.h"
#include "BinaryTrees.h"
#include <memory>
#include <list>

using namespace std;

int Bina;

template <class T>
struct TreeNode
{
	T value;
	shared_ptr<TreeNode<T>> left;
	shared_ptr<TreeNode<T>> right;
};

typedef shared_ptr<TreeNode<int>> TreeNodePtr;

// ----------------------------------------------------------
// 10.1 TEST IF A BINARY TREE IS HEIGHT BALANCED
bool TestIsHeightBalanced(TreeNodePtr root)
{
	// Do a post-order traversal. From the traversal, return the height of the subtree, and where the subtree is height balanced. Terminate early if a subtree is not height balanced. Pay attention to the base case.
	return false;
}

// ----------------------------------------------------------
// 10.2 TEST IF A BINARY TREE IS SYMMETRIC
bool TestIsSymmetric(TreeNodePtr root)
{
	// Do a pre-order traversal, passing in both sides of the tree. At each node, check that the nodes have the same values, then walk down the tree, passing in the left side of subtree A and the right side of side of subtree
	// B, then the right side of subtree A with the left side of subtree B.
	return false;
}

// ----------------------------------------------------------
// 10.3 COMPUTE THE LOWEST COMMON ANCESTOR IN A BINARY TREE *
TreeNodePtr ComputeLCA(TreeNodePtr root, TreeNodePtr a, TreeNodePtr b)
{
	// It helps to relate the problem to a sought status of the subtree we are searching. In this case, the status we are looking for is a subtree with both nodes present. Do a pre-order traversal, returning how many of the
	// nodes were found within the subtree. When that number is two, we have found the LCA and can terminate early, storing the LCA in the status structure.
	return nullptr;
}

// ----------------------------------------------------------
// 10.4 COMPUTE THE LCA WHEN NODES HAVE PARENT POINTERS
TreeNodePtr ComputeLCAWithParentPointers(TreeNodePtr root, TreeNodePtr a, TreeNodePtr b)
{
	// The parent chains of both nodes are effectively linked lists, so this is the same as finding common nodes between linked list. Find the height of each node, then walk up from the longer chain until we are at the same
	// height as the shorter chain, then walk up both chains in tandem until we find the common node.
	return nullptr;
}

// ----------------------------------------------------------
// 10.5 SUM THE ROOT TO LEAD PATHS IN A BINARY TREE
int SumRootToLeafPaths(TreeNodePtr root)
{
	// The encoding for a child is p << 1 | c where p is the encoding for the parent and c is the child bit value. Walk down the tree, computing the encoding for each node from its parents value. When a leaf is reached, add
	// its encoding to the total sum.
	return 0;
}

// ----------------------------------------------------------
// 10.6 FIND A ROOT TO LEAF PATH WITH SPECIFIED SUM
TreeNodePtr FindRootToLeafPath(TreeNodePtr root)
{
	// Compute the path sum during tree traversal, adding the child's value to the parent value. Terminate early when a matching path value is found.
	return nullptr;
}

// ----------------------------------------------------------
// 10.7 IMPLEMENT AN IN-ORDER TRAVERSAL WITHOUT RECURSION
vector<int> InOrderTraversal(TreeNodePtr root)
{
	// Simply use a stack. Push node on stack then go left. If left node is null, pop node from stack, add that node to the result, and go right.
	return vector<int>();
}

// ----------------------------------------------------------
// 10.8 IMPLEMENT A PRE-ORDER TRAVERSAL WITHOUT RECURSION
vector<int> PreOrderTraversal(TreeNodePtr root)
{
	// Use a stack. Initialize stack with root. Pop stack, add node at the BACK of the result, push right THEN left, so that we pop left first.
	return vector<int>();
}

// ----------------------------------------------------------
// 10.9 COMPUTE THE KTH NODE IN AN INORDER TRAVERSAL
TreeNodePtr ComputeKthNodeInTraversal(int k)
{
	// Since we have the number of nodes in each subtree, we can figure out the range of node indices within each subtree. Walk the tree, splitting each node in three regions, one for left, one for the current node, one for
	// right. Pass in the range for each child node as we walk the tree, choosing to walk ranges that encompass the target value k. We will eventually reach node k, at which point we can return it. This can be implemented
	// succinctly without using recursion.
	return nullptr;
}

// ----------------------------------------------------------
// 10.10 COMPUTE THE SUCCESSOR **
TreeNodePtr FindSuccessor(TreeNodePtr root, TreeNodePtr node)
{
	// When a node has a nonempty right subtree, the successor must lie within that subtree; furthermore, when a node has a nonempty right subtree, its successor is the first node visited when performing an in-order traversal
	// of that subtree. It is the "left-most" node of that subtree, and can be computed by following the left children exclusively, stopping when there is no left child to continue from.
	//
	// Things are trickier when we do not have a right subtree. If the node is its parent left child, the parent will be the successor.
	// ** If the node is its parent right child, then we can determine the next visited node by iteratively following parents, stopping when we move up from a left child. This is the tricky part. Moving up from a left child
	// means we are about to add that node in the result list.
	// Note that we may reach the root without ever moving up from the left child.
	//
	// The key is to view the algorithm as an in-order traversal where we are trying to find where in the code we would be adding the next node in the traversal, and seeing that there are three cases.
	// The observation that having a subtree means the successor is in that tree leads to performing a short-circuited traversal of that tree.
	return nullptr;
}

// ----------------------------------------------------------
// 10.11 IMPLEMENT AN IN-ORDER TRAVERSAL WITH O(1) SPACE
vector<int> InOrderTraversalO1(TreeNodePtr root)
{
	// Since we have the parent stored in each node, when we go back up the tree, we can simply compare the node we came from to the parent's left child. If we just came back from the left child, we need to complete the right
	// side of the tree, otherwise we're done and can go back up once again.
	return vector<int>();
}

// ----------------------------------------------------------
// 10.12 RECONSTRUCT A BINARY TREE FROM TRAVERSAL DATA *
TreeNodePtr ReconstructBinaryTreeFromTraversalData(const vector<int>& preorder, const vector<int>& inorder)
{
	// We know the root since it's the first element in the pre-order list. We can lookup the node in the in-order list; its left children are on the left in that list, and its right children are on its right, so we know how many
	// nodes are on each side. The left child is the first element after the root node in the pre-order list, and its the first element after the root node on the in-order list.
	// We then recurse on the subtree. If a subtree has n nodes, it will be the n nodes after the root node in the pre-order list and the nodes before the root node on the in-order list for the left side and after the root
	// node on the in-order list for the right side.
	return TreeNodePtr();
}

// ----------------------------------------------------------
// 10.13 RECONSTRUCT A BINARY TREE FROM A PRE-ORDER TRAVERSAL WITH MARKERS *
TreeNodePtr ReconstructBinaryTreeFromPreOrderWithMarkers(const vector<int>* preorder)
{
	// The pre-order list starts with the root node, and the left and right subtrees follow. We can't tell directly how many nodes are in the left subtree.
	// Visit the left child, and consume the nodes recursively. When we hit a leaf node (marked with nulls on both sides), we can go up the tree, and return how many node were found in the subtree at that level. This allows
	// the parent node to know where its right subtree begins, and perform the traversal on that side of that true, progressing recursively until the entire tree is built.
	return TreeNodePtr();
}

// ----------------------------------------------------------
// 10.14 FORM A LINKED LIST FROM THE TREE LEAVES OF A BINARY TREE
list<TreeNodePtr> FormLinkedListFromBinaryTree(TreeNodePtr root)
{
	// Simply walk through the tree, and record leaves incrementally.
	return list<TreeNodePtr>();
}

// ----------------------------------------------------------
// 10.15 COMPUTE THE EXTERIOR OF A BINARY TREE **
list<TreeNodePtr> ComputeBinaryTreeExterior(TreeNodePtr root)
{
	// This is trickier than it looks to get right. Walk the left subtree, collecting all left children, and right children when a child is not present (these count as a boundary as well). Wherever there are two children to a node
	// is where the boundary ends. Do the mirror process on the right side of the tree, colling all right children  and right children when no left child is present. The results have to be spliced in the right order.
	return list<TreeNodePtr>();	
}

// ----------------------------------------------------------
// 10.16 COMPUTE THR RIGTH SIBLING TREE *
template <class T>
struct TreeNodeWithSibling : TreeNode<T>
{
	shared_ptr<TreeNodeWithSibling<T>> sibling;
};

typedef shared_ptr<TreeNodeWithSibling<int>> TreeNodeWithSiblingPtr;

TreeNodeWithSiblingPtr ComputeRightSiblingTree(TreeNodeWithSiblingPtr root)
{
	// Start with the root. The sibling of the left child is the right child. We've now built one level from the tree (the base case). Now we can walk through in sibling order, linking the left child of a node to the right
	// child of a node as a sibling, and the right child of the node with the parent sibling's left child. The key insight is in reusing the information discovered from the higher levels in the tree, since ths siblings are
	// already stored in the nodes for processed levels.
	return TreeNodeWithSiblingPtr();
}

// ----------------------------------------------------------
// 10.17 IMPLEMENT LOCKING IN A BINARY TREE
//
// Keep a count of the number of locked nodes for each subtree. Checking if any descendants are locked is then simply a matter of locking at the count; checking if any ancestors are locked is done by examining the counts
// up the tree. Locking and unlocking nodes must increment and decrement lock counts up the tree.