#include "stdafx.h"
#include "Arrays.h"

void IncrementIntegerArray(std::vector<int>& in)
{
	auto i = 0;
	for (i = static_cast<int>(in.size()) - 1; i >= 0; i--)
	{
		if (in[i] == 9)
			in[i] = 0;
		else
		{
			in[i]++;
			break;
		}
	}
	if (i == -1)
		in.insert(in.begin(), 1);
}

void TestIncrementArray()
{
	std::vector<int> in = {1, 0, 0};
	std::vector<int> out = {1, 0, 1};
	IncrementIntegerArray(in);
	assert(in == out);
	std::vector<int> in2 = {9, 9, 9};
	std::vector<int> out2 = {1, 0, 0, 0};
	IncrementIntegerArray(in2);
	assert(in2 == out2);
	std::vector<int> in3 = {1, 2, 9};
	std::vector<int> out3 = {1, 3, 0};
	IncrementIntegerArray(in3);
	assert(in3 == out3);
}

int BuyAndSellStockOnce(std::vector<int> prices)
{
	auto minPrice = std::numeric_limits<int>::max();
	auto result = 0;
	for (auto i = 0; i < prices.size(); i++)
	{
		auto dif = prices[i] - minPrice;
		if (dif > result)
			result = dif;
		if (prices[i] < minPrice)
			minPrice = prices[i];
	}
	return result;
}

void TestBuyAndSellStockOnce()
{
	std::vector<int> prices = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
	auto result = BuyAndSellStockOnce(prices);
	assert(result == 30);
}

void SampleOfflineData(std::vector<int>& values, int k)
{
	std::default_random_engine seed;
	for (auto i = 0; i < k; i++)
		std::swap(values[i], values[std::uniform_int_distribution<int>{i, static_cast<int>(values.size()) - 1}(seed)]);
}

void TestSampleOnlineData()
{
	std::vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> values2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	SampleOfflineData(values, 5);
	assert(values != values2);
}

bool SudokuCheckerProblem(std::vector<std::vector<int>> a)
{
	std::vector<int> subgridMask = {0, 0, 0,};
	std::vector<int> columnMask = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (auto y = 0; y < 9; y++)
	{
		auto rowMask = 0;
		if (y % 3 == 0)
			subgridMask = {0, 0, 0};
		for (auto x = 0; x < 9; x++)
		{
			auto valueFlag = 1 << a[y][x];
			if ((rowMask & valueFlag) != 0 || (columnMask[x] & valueFlag) != 0 || (subgridMask[x / 3] & valueFlag) != 0)
				return false;
			rowMask |= valueFlag;
			columnMask[x] |= valueFlag;
			subgridMask[x / 3] |= valueFlag;
		}
	}
	return true;
}

void TestSudokuCheckerProblem()
{
	std::vector<std::vector<int>> a = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, {6, 7, 2, 1, 9, 5, 3, 4, 8}, {1, 9, 8, 3, 4, 2, 5, 6, 7}, {8, 5, 9, 7, 6, 1, 4, 2, 3}, {4, 2, 6, 8, 5, 3, 7, 9, 1}, {7, 1, 3, 9, 2, 4, 8, 5, 6}, {9, 6, 1, 5, 3, 7, 2, 8, 4}, {2, 8, 7, 4, 1, 9, 6, 3, 5}, {3, 4, 5, 2, 8, 6, 1, 7, 9}};
	assert(SudokuCheckerProblem(a));
	std::vector<std::vector<int>> b = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, {6, 7, 2, 1, 9, 5, 3, 4, 8}, {1, 9, 8, 3, 8, 2, 5, 6, 7}, {8, 5, 9, 7, 6, 1, 4, 2, 3}, {4, 2, 6, 8, 5, 3, 7, 9, 1}, {7, 1, 3, 9, 2, 4, 8, 5, 6}, {9, 6, 1, 5, 3, 7, 2, 8, 4}, {2, 8, 7, 4, 1, 9, 6, 3, 5}, {3, 4, 5, 2, 8, 6, 1, 7, 9}};
	assert(SudokuCheckerProblem(b));
}

std::vector<int> ComputeSpiralOrder(std::vector<std::vector<int>> a)
{
	std::vector<int> result;
	std::vector<std::vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	auto x = 0, y = 0, curDir = 0, limit = 0;
	for (auto i = 0; i < a.size() * a.size(); i++)
	{
		result.push_back(a[y][x]);
		a[y][x] = 0; // Um, this is cheating.
		auto nextX = x + directions[curDir][0];
		auto nextY = y + directions[curDir][1];
		if (nextX < 0 || nextX >= a.size() || nextY < 0 || nextY >= a.size() || a[nextY][nextX] == 0)
		{
			curDir = (curDir + 1) % 4;
			nextX = x + directions[curDir][0];
			nextY = y + directions[curDir][1];
		}
		x = nextX;
		y = nextY;
	}
	return result;
}

void TestSpiralOrder()
{
	std::vector<std::vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	std::vector<int> out = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
	auto result = ComputeSpiralOrder(a);
	assert(result == out);
	std::vector<std::vector<int>> a2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	std::vector<int> out2 = {1, 2, 3, 6, 9, 8, 7, 4, 5};
	auto result2 = ComputeSpiralOrder(a2);
	assert(result2 == out2);
}

void TestArrays()
{
	TestSpiralOrder();
	TestSudokuCheckerProblem();
	TestSampleOnlineData();
	TestIncrementArray();
	TestBuyAndSellStockOnce();
}
