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
			auto value = static_cast<uint64_t>(1) << j;
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
		value ^= 1ull  << i | 1ull << j;
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
	for ( auto i = 0; i < 0xFFFF; i++)
	{
		table[i] = 0;
		for (auto j = 0; j < 16; j++)
			// ReSharper disable CppRedundantParentheses
			table[i] |= (i >> j & 0x01) << (15 - j);
			// ReSharper restore CppRedundantParentheses
	}
	return static_cast<uint64_t>(table[value & 0xFFFF]) << 48 | static_cast<uint64_t>(table[value >> 16 & 0xFFFF]) << 32 |
		static_cast<uint64_t>(table[value >> 32 & 0xFFFF]) << 16 | static_cast<uint64_t>(table[value >> 48 & 0xFFFF]);
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
	for ( auto i = 0; i < 31; i++)
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
	auto result = ComputePower(10, 0);
	assert(result == 1);
	result = ComputePower(10, 1);
	assert(result == 10);
	result = ComputePower(10, 2);
	assert(result == 100);
	result = ComputePower(10, 4);
	assert(result == 10000);
	result = ComputePower(10, 5);
	assert(result == 100000);
	result = ComputePower(11, 17);
	assert(result == 505447028499293771);
}

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

void PrimitiveTypeTests()
{
	TestParity();
	TestSwapBits();
	TestReverseBits();
	TestFindClosestInteferWithSameWeight();
	TestComputePower();
	TestReverseDigits();
}
