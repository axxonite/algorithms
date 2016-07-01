#include "stdafx.h"
#include "Lists.h"
#include <memory>

using namespace std;

template <class T>
struct Node
{
	T value;
	Node* next;
};

typedef shared_ptr<Node<int>> NodePtr;

// ----------------------------------------------------------
// 8.1 MERGE TWO SORTED LISTS
NodePtr MergeTwoSortedLists(NodePtr l1, NodePtr l2)
{
	// Walk both lists, comparing each node. Start with a head sentinel node, and attach the smaller node to the resulting list. When one list has reached the end, attach the other list and exit out since there is nothing left 
	// to compare.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.2 REVERSE A SINGLE SUBLIST
NodePtr ReverseList(NodePtr l, int s, int f)
{
	// Walk the list to the sth node. Keep track of node s-1. Then reverse the links in the nodes starting from s, attaching s to s+1, until node f is reached. Then attach f to the s-1 node tracked before.
	// After the solution, a simpler approach is to keep reattaching the start of the sublist to the end of the prefix list on each iteration.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.3 TEST FOR CYCLICITY
NodePtr TestCycle(NodePtr l)
{
	// The best method for finding a cycle is to run two iterators, a slow and fast one, with one that advances by one step per iteration, and the other that advances by two steps. The two will eventually meet if there is a
	// cycle. The key in understanding why that works is that if the fast iterators jumps over the slow iterator, the slow iterator will equal the fast iterator in the next step. Working out this example on paper helps.
	// So essentially there is no way for the fast iterator to loop over the slow one without meeting it.
	// Once we've identified a cycle, we can find its length C by running through the cycle to figure out exactly how many nodes we encounter before running into the same node again.
	// Then finding the first node in the cycle is simply a matter or running through the list with two iterators again, one C steps ahead of the other. The start of the cycle is where these two iterators meet.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.4 TEST FOR OVERLAPPING LISTS - LISTS ARE CYCLE FREE
NodePtr TestListOverlap(NodePtr l1, NodePtr l2)
{
	// If the lists overlap, they must share the tail node; once the lists converge at a node, they cannot diverge at a later point, thus finding the overlap consists of finding all overlapping tail nodes.
	// By computing the length of each list, we can then advance through the longer by their difference in length so that both iterators are now at the same distance to the tail node. We can then advance through both lists
	// in tandem until we find a match.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.5 TEST FOR OVERLAPPING LISTS - LISTS ARE CYCLE FREE
NodePtr TestListOverlapWithCycles(NodePtr l1, NodePtr l2)
{
	// Check for the presence of cycles in both lists using solution 8.3. If no cycles are present, use solution 8.4. If one list has a cycle but the either doesn't, then there is no overlap.
	// If both have cycles, the cycles need to be identical to overlap. Running through one cycle we should expect to encounter the start of the other cycle if they are the same.
	// There are two sub-cases when the cycles are identical, for finding the node that first appears in the overlap when there's matching cycles.
	// First find the distance of the cycle from the beginning of each list, then advance the longer by the difference in links, and traverse both lists in tandem (this is similar to the last part of 8.3)
	// If we encounter matching nodes before we encounter the start of the cycle on either lists, then we have a unique start node shared by both lists, that we can return.
	// If we encounter either cycle before, then the lists converge at different points within the cycle, and returning either node that starts a cycle will provide a valid answer.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.6 DELETE A NODE FROM A SINGLE LINKED LIST
NodePtr DeleteNodeFromSingleLinkedList(NodePtr l, NodePtr n)
{
	// Copy the value of the node to delete to the successor node, then delete the successor node instead.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.7 REMOVE THE KTH LAST ELEMENT FROM A LIST
NodePtr DeleteKthLastElement(NodePtr l, int k)
{
	// Advance through the list by k elements, then start another iterator and advance them both. Once reach the end of the list, the previously started iterator is a the correct position.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.8 REMOVE DUPLICATES FROM A SORTED LIST
void RemoveDuplicates(NodePtr l)
{
	// Run through the list, keeping track of the last value encountered (and the node v it came from) and comparing with the current node. When a an identical value is found, relink the node v to the successor of the current node.
}

// ----------------------------------------------------------
// 8.9 IMPLEMENT CYCLIC RIGHT SHIFT FOR SINGLY LINKED LISTS
NodePtr CyclicRightShift(NodePtr l, int k)
{
	// The new head will be n - k, so find the kth last node, detach it from the node before and make it the new head. Keep going to the end of the list and attach the old tail to the old head.
	// Pay attention to the case when k > n - in which case the right shift is equivalent to k mod n, and we can use that instead.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.10 IMPLEMENT EVEN-OD MERGE
NodePtr EvenOddMerge(NodePtr l)
{
	// Traverse the list and link up two separate lists for the even and odd components. Append the odd list to the even list at the end.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.11 TEST WHETHER A SINGLY LINKED LIST IS PALINDROMIC
bool IsListPalindromic(NodePtr l)
{
	// Find the half of the list by using a slow and a fast iterator; the slow iterator has reached the half the list when the fast iterator has reached the end of the list.
	// Then reverse the nodes in the first node, and perform a comparison with the second half to test if the list is palindromic. The list can be reversed back after the test is done.
	return false;
}

// ----------------------------------------------------------
// 8.12 IMPLEMENT LIST PIVOTING
NodePtr ImplementListPivoting(NodePtr l, int k)
{
	// Reassign the nodes to three lists according to their relationship with k. Then splice the three lists back together.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.13 ADD LIST-BASED INTEGERS
NodePtr AddListIntegers(NodePtr l1, NodePtr l2)
{
	// Walk through the lists in tandem to add the numbers. Keep a carry, and add an extra node at then if we end up with a carry.
	return NodePtr();
}