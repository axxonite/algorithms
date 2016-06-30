#include "stdafx.h"
#include "PrimitiveTypes.h"

using namespace std;

// ----------------------------------------------------------
// 5.1 COMPUTING THE PARITY OF A WORD
// Compute the parity of a very large number of 64-bit words.
void ComputeParity(int count, uint64_t* input, int* output)
{
	// The major insight here is that the parity of a binary value is equal to the XOR of the parity of each of its halves. 
	// Using a simple form of divide and conquer will return the parity of the whole from the parity of its smaller parts.
	short parityLookupTable[0xFFFF];
	for (auto i = 0; i < 0xFFFF; i++)
	{
		auto parity = i;
		parity = parity ^ parity >> 8;
		parity = parity ^ parity >> 4;
		parity = parity ^ parity >> 2;
		parity = parity ^ parity >> 1;
		parityLookupTable[i] = parity & 0x01;
	}
	for (auto i = 0; i < count; i++)
		output[i] = parityLookupTable[input[i] & 0xFFFF] ^ parityLookupTable[input[i] >> 16 & 0xFFFF] ^ parityLookupTable[(input[i] >> 32 & 0xFFFF)] ^ parityLookupTable[input[i] >> 48 & 0xFFFF];
}

void TestParity()
{
	default_random_engine rnd;
	uniform_int_distribution<uint64_t> dis(0, numeric_limits<uint64_t>::max());
	uint64_t input[1000];
	int output[1000];
	for (auto i = 0; i < 1000; i++)
		input[i] = dis(rnd);
	ComputeParity(1000, input, output);
	for (auto i = 0; i < 1000; i++)
	{
		auto count = 0;
		for (auto j = 0; j < 64; j++)
		{
			auto value = uint64_t(1) << j;
			if (input[i] & value)
				count++;
		}
		auto referenceParity = count % 2 == 0 ? 0 : 1;
		assert(referenceParity == output[i]);
	}
}

// ----------------------------------------------------------
// 5.2 SWAP BITS
// Implement code that takes an input a 64-bit integer and swaps the bits at indices i and j.
uint64_t SwapBits(uint64_t value, int i, int j)
{
	// The main takeaway is that the XOR of a value with a mask will flip the value bits where the mask bits are 1.
	// To be noted however, using a conditional statement is probably slower than simply extracting the bit values and swapping them without checking if they are the same.
	// I think this is a case of them being too clever for their own good.
	if ((value >> i & 0x01) != (value >> j & 0x01))
		value ^= 1ull << i | 1ull << j;
	return value;
}

void TestSwapBits()
{
	auto value = 0b1010101010101010101010101010101010101010101010101010101010101010ull;
	auto result = SwapBits(value, 0, 63);
	assert(result == 0b0010101010101010101010101010101010101010101010101010101010101011ull);
}

// ----------------------------------------------------------
// 5.3 REVERSE BITS
// Write a program that takes a 64-bit word and returns the 64-bit word consisting of the bits of the input in reverse order.
uint64_t ReverseBits(uint64_t value)
{
	short table[0xFFFF];
	for (auto i = 0; i < 0xFFFF; i++)
	{
		table[i] = 0;
		for (auto j = 0; j < 16; j++)
		// ReSharper disable CppRedundantParentheses
			table[i] |= (i >> j & 0x01) << (15 - j);
		// ReSharper restore CppRedundantParentheses
	}
	return uint64_t(table[value & 0xFFFF]) << 48 | uint64_t(table[value >> 16 & 0xFFFF]) << 32 |
		uint64_t(table[value >> 32 & 0xFFFF]) << 16 | uint64_t(table[value >> 48 & 0xFFFF]);
}

void TestReverseBits()
{
	auto result = ReverseBits(0b1111111100000000111111110000000011111111000000001111111100000000ull);
	assert(result == 0b0000000011111111000000001111111100000000111111110000000011111111ull);
}

// ----------------------------------------------------------
// 5.4 FIND CLOSEST INTEGER WITH SAME WEIGHT
// Write a program which takes as input a nonnegative integer x, and returns a number y which is not equal to x, but has the same weight and their difference |y - x| is as small as possible.
unsigned FindClosestIntegerWithSameWeight(unsigned int x)
{
	// If we flip the bit at index k1 and the bit at index k2 where k1 > k2, then the absolute value of the difference between the original integer and the new one is 2^k1 - 2^k2.
	// To minimize this, we should make k1 as small as possible and keep k2 as close to k1 as possible. Since we must preserve the weight, the index bit at index k1 must be different from the bit at index k2. 
	// Thus, the smallest possible k1 can be is the rightmost bit that's different from the LSB, and k2 must be the very next bit.
	// In summary, look for the rightmost consecutive bits that differ, and flip those bits.
	for (auto i = 0; i < 31; i++)
	{
		auto maskK2 = 1 << i;
		auto maskK1 = maskK2 << 1;
		if ((x & maskK1) >> 1 != (x & maskK2)) // Find first two consecutive bits that differ.
			return x ^ (maskK2 | maskK1); // Flip them.
	}
	throw invalid_argument("All bits are 0 or 1.");
}

void TestFindClosestInteferWithSameWeight()
{
	auto result = FindClosestIntegerWithSameWeight(6);
	assert(result == 5);
}

// ----------------------------------------------------------
// 5.5 COMPUTE X * Y WITHOUT ARITHMETICAL OPERATORS
// Write a program that multiplies two non negative integers using only bitwise operations.
uint64_t Add(uint64_t x, uint64_t y)
{
	auto result = 0ull;
	for (auto c = 0ull, x2 = x, y2 = y, mask = 1ull; x2 || y2 || c; mask <<= 1 , x2 >>= 1 , y2 >>= 1)
	{
		auto bx = x & mask, by = y & mask;
		result |= bx ^ by ^ c;
		c = (bx & by | bx & c | by & c) << 1;
	}
	return result;
}

uint64_t MultiplyIntegers(unsigned int x, unsigned int y)
{
	auto result = 0ull;
	for (auto x64 = uint64_t(x), y64 = uint64_t(y); y; y >>= 1 , y64 <<= 1 , x64 <<= 1)
		if (y & 1)
			result = Add(result, x64);
	return result;
}

void TestMultiplyIntegers()
{
	default_random_engine rnd;
	uniform_int_distribution<uint64_t> dis(0, numeric_limits<int>::max());
	for (auto i = 0; i < 1000; i++)
	{
		auto x = dis(rnd);
		auto y = dis(rnd);
		auto addResult = Add(x, y);
		auto addRef = x + y;
		auto result = MultiplyIntegers(int(x), int(y));
		auto ref = x * y;
		assert(addResult == addRef);
		assert(result == ref);
	}
}

// ----------------------------------------------------------
// 5.6 COMPUTE X / Y
// GIven two positive integers, compute their quotient, using only the addition, subtraction and shifting operators.
int Divide(unsigned int x, unsigned int y)
{
	auto result = 0;
	while (y < x)
	{
		auto z = uint64_t(y) << 31;
		auto q = 1u << 31;
		while (z > x)
		{
			z >>= 1;
			q >>= 1;
		}
		result += q;
		x -= unsigned int(z);
	}
	return result;
}

void TestDivide()
{
	default_random_engine rnd;
	uniform_int_distribution<int> dis(0, numeric_limits<int>::max());
	for (auto i = 0; i < 1000; i++)
	{
		auto x = dis(rnd);
		auto y = dis(rnd);
		auto result = Divide(x, y);
		auto ref = x / y;
		assert(result == ref);
	}
}

// ----------------------------------------------------------
// 5.7 COMPUTE X ^ Y
// Write a program that takes a double x and an integer y and return x^y. You can ignore overflow and underflow.
double ComputePower(double x, int y)
{
	// So the basic equation that we are basing this on is pow(x,y1+y2)=pow(x,y1)*pow(x,y2)
	// Each bit in the number corresponds to a doubled power.
	auto bitvalue = x;
	auto result = 1.0;
	while (y > 0)
	{
		if (y & 1)
			result *= bitvalue;
		bitvalue *= bitvalue;
		y >>= 1;
	}
	return result;
}

void TestComputePower()
{
	default_random_engine rnd;
	uniform_int_distribution<int> disx(0, 100);
	uniform_int_distribution<int> disy(1, 8);
	for (auto i = 0; i < 1000; i++)
	{
		auto x = disx(rnd);
		auto y = disy(rnd);
		auto result = ComputePower(x, y);
		auto ref = pow(x, y);
		assert(fabs(result - ref) <= 0.001);
	}
}

// ----------------------------------------------------------
// 5.8 REVERSE DIGITS
// Write a program which takes an integer and returns the integer corresponding to the digits of the input written in reverse order.
int ReverseDigits(int x)
{
	auto result = 0;
	auto neg = x < 0;
	x = abs(x);
	while (x > 0)
	{
		result = result * 10 + x % 10;
		x = x / 10;
	}
	return result * (neg ? -1 : 1);
}

void TestReverseDigits()
{
	auto reversed = ReverseDigits(42);
	assert(reversed == 24);
	reversed = ReverseDigits(-314);
	assert(reversed == -413);
}

// ----------------------------------------------------------
// 5.9 CHECK IF A DECIMAL INTEGER IS A PALINDROME
// Write a program that takes an integer and determines if that integer's representation as a decimal string is a palindrome.
bool IsPalindrome(int x)
{
	if (x < 0)
		return false;
	//auto p = 1;
	//while (p * 10 < x)
	//	p *= 10;
	// We can use a log10. Remember log10 means thew power to which 10 must be raised to reach x. Technically, I wonder if the simple loop iteration above wouldn't be faster.
	auto p = int(pow(10, floor(log10(x))));
	while (x >= 10)
	{
		if (x % 10 != x / p)
			return false;
		x = (x % p)  / 10;
		p /= 100;
	}
	return true;
}

void TestIsPalindrome()
{
	auto result = IsPalindrome(0);
	assert(result);
	result = IsPalindrome(10);
	assert(!result);
	result = IsPalindrome(121);
	assert(result);
	result = IsPalindrome(333);
	assert(result);
	result = IsPalindrome(1234554321);
	assert(result);
	result = IsPalindrome(12344321);
	assert(result);
	result = IsPalindrome(12343421);
	assert(!result);
}

// ----------------------------------------------------------
// 5.10 GENERATE A UNIFORM RANDOM NUMBER
// Implement a random number generator that generates a random integer between a and b, inclusive given a random number generator that produces 0 or 1 with equal
// probability.
// Time complexity is O(lg(b - a + 1)
int GenerateUniformRandomNumber(int a, int b)
{
    default_random_engine rnd;
    uniform_int_distribution<int> dis(0, 1);
    // Test case 1: say this is a=1, b=2, then range=1, so valid values are 0 and 1.
    // Test case 2: say this is a=1, b=3, then range=2, so valid values are 0, 1, and 2.
    // Assume b > a, b and a could be swapped if they're not. The difference of b and a could overflow a signed int.
    auto range = uint32_t(int64_t(b) - int64_t(a)); 
    uint32_t result;
    do
    {
        auto curRange = 1ull; // Need at least 33 bits here to avoid a potential infinite loop.
        result = 0;
        // Test case 1: curRange will be 2 on 2nd iteration, so skip, and possible values are 0 and 1
        // Test case 2: curRange will be 2 on 2nd iteration, so pass, and possible values are 0, 1, 2 and 3; 3 will rejected by the while condition.         
        while ( curRange <= range ) // curRange will be 2 on 2nd iteration, so pass, and possible values are 0-3
        {
            result |= dis(rnd) * curRange;
            curRange <<= 1;
        }
    }
    while ( result > range );
    return a + result;
}

void TestGenerateUniformNumber()
{
	default_random_engine rnd;
	uniform_int_distribution<int> dis(numeric_limits<int>::min(), numeric_limits<int>::max());
	uniform_int_distribution<int> dis2(0, 100);
	for (auto i = 0; i < 1000; i++)
	{
		auto a = dis(rnd);
		auto b = a + dis2(rnd);
		auto result = GenerateUniformRandomNumber(a, b);
		assert(result >= a);
		assert(result <= b);
		b = dis(rnd);
		if (b < a)
			swap(a, b);
		result = GenerateUniformRandomNumber(a, b);
		assert(result >= a);
		assert(result <= b);
	}
}

// ----------------------------------------------------------
// 5.11 RECTANGLE INTERSECTION
// Write a program that tests if two rectangles have a nonempty intersection. If the intersection is nonempty, return the rectangle formed by their intersection.
struct Rect
{
	int x1, y1, x2, y2;
};

Rect RectangleIntersection(Rect a, Rect b)
{
	// The problem is unspecified, but the boundary is considered a part of the rectangle.
	// Focus on the conditions under which the rectangles are guaranteed to not intersect, which is when a rectangle's right edge is before the left edge of the other, or the rectangle's left edge is after the right edge 
	// of the other.
	// Thus, there is an intersection along an axis if a A.Min <= B.Max && A.Max >= B.Min. 
	// If the set of x-values for the rectangles intersect and the set of y-values for the rectangles intersect, then all points with those x- and y-values are common to both rectangles, and there is a non-empty intersection.
	// The intersection along an axis is Max(A.min, B.min), Min(A.max, B.max)
	Rect result;
	result.x1 = result.y1 = result.x2 = result.y2 = 0;
	return result;
}

// ----------------------------------------------------------
// 25.1 COMPUTE THE GREATEST COMMON DIVISOR
// The greatest common divisor  of positive integers x and y is the largest integer d such that d divides x evenly, and d divides y evenly, i.e. x mod d = 0 and y mod d = 0.
// Design an efficient algorithm for computing the GCD of two numbers without using multiplication, division or the modulus operators.

// If x=y, GDC(x,y) = x, otherwise assume x > y, in which case GCD(x,y) = GCD(x-y,y).

// ----------------------------------------------------------
void PrimitiveTypeTests()
{
	TestParity();
	TestSwapBits();
	TestReverseBits();
	TestFindClosestInteferWithSameWeight();
	TestMultiplyIntegers();
	TestDivide();
	TestComputePower();
	TestReverseDigits();
	TestIsPalindrome();
	TestGenerateUniformNumber();
}
