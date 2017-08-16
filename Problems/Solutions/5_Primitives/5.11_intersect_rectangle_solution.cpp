// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Rectangle 
	{
		int x, y, width, height;
		int x2, y2;
		Rectangle()
		{
		}

		Rectangle(int x1, int y1, int _x2, int _y2)
		{
			x = x1;
			y = y1;
			x2 = _x2;
			y2 = _y2;
			width = x2 - x1;
			height = y2 - y1;
		}
		void print(string s) const { cout << s << this->x << ' ' << this->y << ' ' << this->width << ' ' << this->height << endl; }
	};

	bool IsIntersect(const Rectangle& R1, const Rectangle& R2)
	{
		return R1.x <= R2.x2 && R1.x2 >= R2.x && R1.y <= R2.y2 && R1.y2 >= R2.y;
	}

	Rectangle IntersectRectangle(const Rectangle& R1, const Rectangle& R2)
	{
		if (!IsIntersect(R1, R2))
			return Rectangle(0, 0, -1, -1);
		return Rectangle(max(R1.x, R2.x), max(R1.y, R2.y), min(R1.x2, R2.x2), min(R1.y2, R2.y2));
	}
}