#include "stdafx.h"
#include "Lists.h"
#include <vector>
#include <memory>

using namespace std;

// ----------------------------------------------------------
// 8.1 MERGE TWO SORTED LISTS
NodePtr MergeTwoSortedLists(NodePtr l1, NodePtr l2)
{
	// Walk both lists, comparing each node. Start with a head sentinel node, and attach the smaller node to the resulting list. When one list has reached the end, attach the other list and exit out since there is nothing left 
	// to compare.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.2 REVERSE A SINGLE SUBLIST*
NodePtr ReverseList(NodePtr l, int s, int f)
{
	// Walk the list to the sth node. Keep track of node s-1. Then reverse the links in the nodes starting from s, attaching s to s+1, until node f is reached. Then attach f to the s-1 node tracked before.
	// After the solution, a simpler approach is to keep reattaching the start of the sublist to the end of the prefix list on each iteration.
	if (s == f)
		return l;
	auto dummy_head = make_shared<Node<int>>(Node<int>{0, l}); // Note the use dummy nodes to simplify the boundary conditions.
	auto sublist_head = dummy_head;
	int i = 1; // note that the numbering begins at 1.
	while (i++ < s) // Note the use of the postfix operator.
		sublist_head = sublist_head->next;

	auto sublist_iter = sublist_head->next;
	while (s++ < f) // Notice the recycling of s.
	{
		auto temp = sublist_iter->next; // temp (i+1) is the value that will come first.
		sublist_iter->next = temp->next; // i is linked to i+2 
		temp->next = sublist_head->next; // i+1 is linked to head+1.
		sublist_head->next = temp; // head+1 is set to i+1.
	}
	return dummy_head->next; // Discard dummy head.}
}

NodePtr BuildList(int n)
{
	NodePtr prev = nullptr;
	for (int i = n - 1; i >= 0; i--)
	{
		auto node = make_shared<Node<int>>(Node<int>{i, prev});
		prev = node;
	}
	return prev;
}

void TestList(NodePtr l, const vector<int> values)
{
	int i = 0;
	for (auto n = l; n != nullptr; n = n->next , i++)
	{
		assert(n->value == values[i]);
	}
}

void TestReverseList()
{
	auto l = BuildList(10);
	auto r = ReverseList(l, 2, 4);
	TestList(r, {0, 3, 2, 1, 4, 5, 6, 7, 8, 9});
}

// ----------------------------------------------------------
// 8.3 TEST FOR CYCLICITY*
NodePtr TestCycle(NodePtr l)
{
	// The best method for finding a cycle is to run two iterators, a slow and fast one, with one that advances by one step per iteration, and the other that advances by two steps. The two will eventually meet if there is a
	// cycle. The key in understanding why that works is that if the fast iterators jumps over the slow iterator, the slow iterator will equal the fast iterator in the next step. Working out this example on paper helps.
	// So essentially there is no way for the fast iterator to loop over the slow one without meeting it.
	// Once we've identified a cycle, we can find its length C by running through the cycle to figure out exactly how many nodes we encounter before running into the same node again.
	// Then finding the first node in the cycle is simply a matter or running through the list with two iterators again, one C steps ahead of the other. The start of the cycle is where these two iterators meet.
	auto slow = l, fast = l;
	while (fast && fast->next) // Note that we're using a single outer loop.
	{
		slow = slow->next;
		fast = fast->next->next; // We don't check for an empty next link on fast.
		if (slow == fast)
		{
			int length = 0;
			do // Use a do loop, not a while.
			{
				slow = slow->next , length++;
			}
			while (slow != fast);

			auto ahead = l;
			while (length--) // Recycle length and decrement here.
				ahead = ahead->next;
			auto behind = l;
			while (behind != ahead)
				behind = behind->next , ahead = ahead->next;
			return behind;
		}
	}
	return nullptr;
}

NodePtr CreateCycle(NodePtr l)
{
	auto n = l;
	while (n->next)
		n = n->next;
	n->next = l;
	return l;
}

void TestTestCycle()
{
	auto l = BuildList(10);
	auto noCycle = TestCycle(l);
	assert(!noCycle);
	l = CreateCycle(l);
	auto hasCycle = TestCycle(l);
	assert(hasCycle);
}

// ----------------------------------------------------------
// 8.4 TEST FOR OVERLAPPING LISTS - LISTS ARE CYCLE FREE*
NodePtr TestListOverlap(NodePtr l1, NodePtr l2)
{
	// If the lists overlap, they must share the tail node; once the lists converge at a node, they cannot diverge at a later point, thus finding the overlap consists of finding all overlapping tail nodes.
	// By computing the length of each list, we can then advance through the longer by their difference in length so that both iterators are now at the same distance to the tail node. We can then advance through both lists
	// in tandem until we find a match.
	int length1 = 0, length2 = 0;
	auto it1 = l1, it2 = l2;
	while (it1)
		it1 = it1->next , length1++;
	while (it2)
		it2 = it2->next , length2++;
	auto diff = abs(length1 - length2);
	auto longer = length1 > length2 ? l1 : l2;
	auto shorter = length1 > length2 ? l2 : l1;
	while (diff--)
		longer = longer->next;
	while (longer && shorter && longer != shorter)
		longer = longer->next , shorter = shorter->next;
	return shorter;
}

NodePtr AdvanceList(NodePtr l, int k)
{
	for (int i = 0; i < k; i++)
		l = l->next;
	return l;
}

void TestTestListOverlap()
{
	auto l1 = BuildList(10);
	auto l2 = BuildList(10);
	auto noOverlap = TestListOverlap(l1, l2);
	auto l3 = AdvanceList(l1, 5);
	auto hasOverlap = TestListOverlap(l1, l3);
	assert(!noOverlap);
	assert(hasOverlap);
}

// ----------------------------------------------------------
// 8.5 TEST FOR OVERLAPPING LISTS - LISTS HAVE CYCLES**
NodePtr TestListOverlapWithCycles(NodePtr l1, NodePtr l2)
{
	// Check for the presence of cycles in both lists using solution 8.3. If no cycles are present, use solution 8.4. If one list has a cycle but the either doesn't, then there is no overlap.
	// If both have cycles, the cycles need to be identical to overlap. Running through one cycle we should expect to encounter the start of the other cycle if they are the same.
	// There are two sub-cases when the cycles are identical, for finding the node that first appears in the overlap when there's matching cycles.
	// First find the distance of the cycle from the beginning of each list, then advance the longer by the difference in links, and traverse both lists in tandem (this is similar to the last part of 8.3)
	// If we encounter matching nodes before we encounter the start of the cycle on either lists, then we have a unique start node shared by both lists, that we can return.
	// If we encounter either cycle before, then the lists converge at different points within the cycle, and returning either node that starts a cycle will provide a valid answer.
	auto cycle1 = TestCycle(l1);
	auto cycle2 = TestCycle(l2);
	if (cycle1 || cycle2)
	{
		if ((!cycle1 && cycle2) || (!cycle1 && cycle2))
			return nullptr;
		auto it = cycle1;
		do
		{
			it = it->next;
		}
		while (it != cycle2 && it != cycle1);
		if (it != cycle2)
			return nullptr;

		auto cycleStart1 = 0, cycleStart2 = 0;
		auto it1 = l1, it2 = l2;
		while (it1 != cycle1)
			it1 = it1->next , cycleStart1++;
		while (it2 != cycle2)
			it2 = it2->next , cycleStart2++;
		auto diff = abs(cycleStart1 - cycleStart2);
		if (cycleStart2 > cycleStart1)
		{
			swap(l1, l2);
			swap(cycle1, cycle2);
		}
		while (diff-- > 0)
			l1 = l1->next;
		while (l1 != l2 && l1 != cycle1 && l2 != cycle2)
			l1 = l1->next , l2 = l2->next;
		return l1;
	}
	return TestListOverlap(l1, l2);
}

void TestTestListOverlapWithCycles()
{
	auto l1 = BuildList(10);
	l1 = CreateCycle(l1);
	auto l2 = BuildList(10);
	l2 = CreateCycle(l2);
	auto noOverlap = TestListOverlapWithCycles(l1, l2);
	auto l3 = AdvanceList(l1, 5);
	auto hasOverlap = TestListOverlapWithCycles(l1, l3);
	assert(!noOverlap);
	assert(hasOverlap);
}

// ----------------------------------------------------------
// 8.6 DELETE A NODE FROM A SINGLE LINKED LIST*
NodePtr DeleteNodeFromSingleLinkedList(NodePtr l, NodePtr n)
{
	if (l == n)
		return nullptr;
	if (n->next)
	{
		n->value = n->next->value;
		n->next = n->next->next;
	}
	else
	{
		auto it = l;
		while (it->next != n)
			it = it->next;
		it->next = nullptr;
	}
	return l;
}

void TestDeleteNode()
{
	auto l = BuildList(5);
	auto d = AdvanceList(l, 2);
	auto r = DeleteNodeFromSingleLinkedList(l, d);
	TestList(r, {0, 1, 3, 4});
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
// 8.9 IMPLEMENT CYCLIC RIGHT SHIFT FOR SINGLY LINKED LISTS**
NodePtr CyclicRightShift(NodePtr l, int k)
{
	// *** Find tail node t. t's next is old head. The new head is the n - k node.
	// Pay attention to the case when k > n - in which case the right shift is equivalent to k mod n, and we can use that instead.
	if (l == nullptr)
		return l;
	auto tail = l;
	auto n = 1;
	while (tail->next)
		tail = tail->next , n++;
	k %= n;
	if (k == 0)
		return l;

	tail->next = l;
	int steps = n - k;
	auto newTail = tail;
	while (steps--)
		newTail = newTail->next;
	auto newHead = newTail->next;
	newTail->next = nullptr;
	return newHead;
}

void TestCyclicRightShift()
{
	auto l = BuildList(10);
	auto s = CyclicRightShift(l, 3);
	TestList(s, {7, 8, 9, 0, 1, 2, 3, 4, 5, 6});
}

// ----------------------------------------------------------
// 8.10 IMPLEMENT EVEN-ODD MERGE
NodePtr EvenOddMerge(NodePtr l)
{
	// Traverse the list and link up two separate lists for the even and odd components. Append the odd list to the even list at the end.
	return NodePtr();
}

// ----------------------------------------------------------
// 8.11 TEST WHETHER A SINGLY LINKED LIST IS PALINDROMIC*
NodePtr ReverseList(NodePtr s, NodePtr f)
{
	auto head = make_shared<Node<int>>(Node<int>{0, f}); // tricky
	while (s != f)
	{
		auto next = s->next;
		s->next = head->next;
		head->next = s;
		s = next;
	}
	return head->next;
}

bool IsListPalindromic(NodePtr l)
{
	// Find the half of the list by using a slow and a fast iterator; the slow iterator has reached the half the list when the fast iterator has reached the end of the list.
	// Then reverse the nodes in the first node, and perform a comparison with the second half to test if the list is palindromic. The list can be reversed back after the test is done.

	auto fast = l, slow = l;
	while (fast)
		slow = slow->next , fast = fast->next->next;
	auto reversedHead = ReverseList(l, slow);
	auto first = reversedHead;
	auto second = slow;
	while (second && first->value == second->value)
		first = first->next , second = second->next;
	ReverseList(reversedHead, slow); // Reverse back;
	return second == nullptr;
}

NodePtr BuildList(vector<int> values)
{
	NodePtr prev = nullptr;
	for (int i = values.size() - 1; i >= 0; i--)
	{
		auto node = make_shared<Node<int>>(Node<int>{values[i], prev});
		prev = node;
	}
	return prev;
}


void TestIsListPalindromic()
{
	auto l = BuildList(10);
	auto r = IsListPalindromic(l);
	assert(!r);
	auto l2 = BuildList({0, 1, 2, 3, 4, 4, 3, 2, 1, 0});
	auto r2 = IsListPalindromic(l2);
	assert(r2);
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

void TestLists()
{
	TestReverseList();
	TestTestCycle();
	TestTestListOverlap();
	TestTestListOverlapWithCycles();
	TestDeleteNode();
	TestCyclicRightShift();
	TestIsListPalindromic();
}
