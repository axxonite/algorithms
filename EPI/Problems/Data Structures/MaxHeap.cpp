#include "stdafx.h"

using namespace std;

// #define TEST

class MaxHeap
{
public:

	MaxHeap(const vector<int>& values)
	{
	}

	int Max() const
	{
		return 0;
	}

	void Pop()
	{

	}

	int ExtractMax()
	{
		return 0;
	}

	void IncreaseKey(int i, int value)
	{
	}

	void InsertKey(int value)
	{
	}

private:

	vector<int> mHeap;

};

#pragma region Test

void MaxHeapTest()
{
#ifdef TEST
	MaxHeap h({});
	h.InsertKey(3);
	h.InsertKey(2);
	h.InsertKey(1);
	h.InsertKey(5);
	assert(h.Max() == 5);
	h.Pop();
	assert(h.Max() == 3);
	h.Pop();
	h.IncreaseKey(0, 100);
	assert(h.Max() == 102);
	h.Pop();
	h.Pop();
	try {
		h.Pop();
		assert(false);
	}
	catch (const exception& e) {
		cout << "empty heap" << endl;
		cout << e.what() << endl;
	}

	h.InsertKey(0);
	h.InsertKey(-1);
	h.InsertKey(numeric_limits<int>::max());
	assert(h.Max() == numeric_limits<int>::max());
	h.Pop();
	assert(h.Max() == 0);
	h.Pop();
	assert(h.Max() == -1);
	h.Pop();
	try {
		h.Pop();
		assert(false);
	}
	catch (const exception& e) {
		cout << "empty max heap" << endl;
		cout << e.what() << endl;
	}
#endif
}

#pragma endregion