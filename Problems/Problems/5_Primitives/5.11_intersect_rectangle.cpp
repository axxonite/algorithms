// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct Rectangle
{
	int left, top, width, height;
	int right, bottom;

	Rectangle()
	{
	}

	Rectangle(int _x1, int _y1, int _x2, int _y2)
	{
		left = _x1;
		top = _y1;
		right = _x2;
		bottom = _y2;
		width = right - left;
		height = bottom - top;
	}

	void print(string s) const { cout << s << this->left << ' ' << this->top << ' ' << this->width << ' ' << this->height << endl; }
};

bool IsIntersect(const Rectangle& a, const Rectangle& b)
{
	return true;
}

// return {0, 0, -1, -1} if there is no intersection.
Rectangle IntersectRectangle(const Rectangle& a, const Rectangle& b)
{
	return Rectangle{ 0, 0, 0, 0 };
}

#pragma region Test

void SmallTest()
{
	Rectangle R1 = {0, 0, 2, 2}, R2 = {1, 1, 3, 3};
	auto result = IntersectRectangle(R1, R2);
	assert(result.left == 1 && result.top == 1 && result.width == 1 &&
		result.height == 1);
	R1 = {0, 0, 1, 1} , R2 = {1, 1, 3, 3};
	result = IntersectRectangle(R1, R2);
	assert(result.left == 1 && result.top == 1 && result.width == 0 &&
		result.height == 0);
	R1 = {0, 0, 1, 1} , R2 = {2, 2, 3, 3};
	result = IntersectRectangle(R1, R2);
	assert(result.left == 0 && result.top == 0 && result.width == -1 &&
		result.height == -1);
}

void RectangleIntersectionTest()
{
#if TEST
	SmallTest();
	for (int times = 0; times < 10000; ++times) {
		Rectangle R1, R2;
	//if (argc == 9) {
	//	R1.x = atoi(argv[1]), R1.y = atoi(argv[2]), R1.width = atoi(argv[3]),
	//		R1.height = atoi(argv[4]);
	//	R2.x = atoi(argv[5]), R2.y = atoi(argv[6]), R2.width = atoi(argv[7]),
	//		R2.height = atoi(argv[8]);
	//}
	//else 
		{
			default_random_engine gen((random_device())());
			uniform_int_distribution<int> dis(1, 100);
			R1.left = dis(gen), R1.top = dis(gen), R1.width = dis(gen),
				R1.height = dis(gen);
			R2.left = dis(gen), R2.top = dis(gen), R2.width = dis(gen),
				R2.height = dis(gen);
		}
	// Intersect rectangle.
		bool res = IsIntersect(R1, R2);
		//cout << boolalpha << IsIntersect(R1, R2) << endl;
		Rectangle ans = IntersectRectangle(R1, R2);
		//ans.print("ans: ");
		assert(res == false || (ans.width >= 0 && ans.height >= 0));
	}
#endif
}

#pragma endregion
