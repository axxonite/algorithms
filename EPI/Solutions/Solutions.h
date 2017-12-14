#pragma once

#include <vector>

using namespace std;

namespace Solutions
{
	// 5. Primitives.
	struct Rectangle
	{
		int x, y, width, height;
		int x2, y2;
		Rectangle();
		Rectangle(int x1, int y1, int _x2, int _y2);
		void print(string s) const;
	};	
	
	unsigned Multiply(unsigned x, unsigned y);
	double BuyAndSellStockTwice(const vector<double>& prices);
	Rectangle IntersectRectangle(const Rectangle& R1, const Rectangle& R2);

	// 7. Strings
	int SSDecodeColID(const string& col);
}