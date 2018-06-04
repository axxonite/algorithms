#pragma once

#include "LinkedListPrototype.h"
#include "doubly_linked_list_prototype.h"

using namespace std;

namespace Solutions
{
	shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2);
	shared_ptr<BSTNodeShared<int>> MergeTwoSortedLists(shared_ptr<BSTNodeShared<int>> l1, shared_ptr<BSTNodeShared<int>> l2, int& length);
}
