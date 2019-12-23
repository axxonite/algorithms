// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

class PostingListNode
{
public:
	int order;
	shared_ptr<PostingListNode> next, jump;
};

shared_ptr<PostingListNode> CopyPostingsList(const shared_ptr<PostingListNode> L)
{
  return nullptr;
}

#pragma region Test

template <typename T>
void CheckPostingsListEqual(shared_ptr<PostingListNode> a, shared_ptr<PostingListNode> b)
{
	while (a && b)
	{
		cout << a->order << ' ';
		assert(a->order == b->order);
		assert((a->jump == shared_ptr<PostingListNode>(nullptr) &&
			b->jump == shared_ptr<PostingListNode>(nullptr)) ||
			(a->jump && b->jump && a->jump->order == b->jump->order));
		if ( a->jump )
			cout << a->jump->order;
		cout << endl;
		a = a->next , b = b->next;
	}
	assert(a == shared_ptr<PostingListNode>(nullptr) && b == shared_ptr<PostingListNode>(nullptr));
}

void CopyPostingsListTest()
{
#ifdef TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 20; ++times)
	{
		uniform_int_distribution<int> n_dis(1, 1000);
		int n = n_dis(gen);
		shared_ptr<PostingListNode> L = nullptr;
		shared_ptr<PostingListNode> curr = L;
		for (int i = 0; i < n; ++i)
		{
			auto temp = make_shared<PostingListNode>(PostingListNode{i, nullptr});
			if (L)
			{
				curr->next = temp;
				curr = temp;
			}
			else
				curr = L = temp;
			// Randomly assigned a jump node.
			uniform_int_distribution<int> dis(0, i + 1);
			int jump_num = dis(gen);
			shared_ptr<PostingListNode> jump = L;
			while (jump_num--)
				jump = jump->next;
			temp->jump = jump;
		}
		shared_ptr<PostingListNode> copied = CopyPostingsList(L);
		CheckPostingsListEqual<int>(L, copied);
	}
#endif
}

#pragma endregion Test
