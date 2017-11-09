// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "doubly_linked_list_prototype.h"
#include "binary_tree_prototype.h"

#define TEST 0

// Watch out, sometimes this fails the test even when it's the correct implementation, and a full rebuild is required.

shared_ptr<ListNodeDbl<int>> BuildBSTFromSortedDoublyList( shared_ptr<ListNodeDbl<int>> l, int length)
{
	return nullptr;
}

#pragma region Test

template <typename T>
void InorderTraversal(const shared_ptr<ListNodeDbl<T>>& node, const T& pre,
	int depth) {
	if (node) {
		InorderTraversal(node->prev, pre, depth + 1);
		assert(pre <= node->data);
		cout << node->data << ' ' << "; depth = " << depth << endl;
		InorderTraversal(node->next, node->data, depth + 1);
	}
}

void BuildBSTFromSortedDoublyListTest()
{
#if TEST
	shared_ptr<ListNodeDbl<int>> temp0 = make_shared<ListNodeDbl<int>>(ListNodeDbl<int>{0});
	shared_ptr<ListNodeDbl<int>> temp1 = make_shared<ListNodeDbl<int>>(ListNodeDbl<int>{1});
	shared_ptr<ListNodeDbl<int>> temp2 = make_shared<ListNodeDbl<int>>(ListNodeDbl<int>{2});
	shared_ptr<ListNodeDbl<int>> temp3 = make_shared<ListNodeDbl<int>>(ListNodeDbl<int>{3});
	temp0->next = temp1;
	temp1->next = temp2;
	temp2->next = temp3;
	temp3->next = nullptr;
	temp0->prev = nullptr;
	temp1->prev = temp0;
	temp2->prev = temp1;
	temp3->prev = temp2;

	shared_ptr<ListNodeDbl<int>> L = temp0;
	auto tree = BuildBSTFromSortedDoublyList(L, 4);
	InorderTraversal(tree, -1, 0);
	// Break the links of shared_ptr to prevent memory leak.
	temp1->prev = temp2->prev = temp3->prev = nullptr;
#endif
}

#pragma endregion Test
