#include "stdafx.h"
#include "PrimitiveTypes.h"

using namespace std;

short parityLookupTable[0xFFFF];

// 5.1 COMPUTING THE PARITY OF A WORD
// Compute the parity of a very large number of 64-bit words.
void ComputeParity(int count, uint64_t* input, int* output)
{
	// The major insight here is that the parity of a binary value is equal to the XOR of the parity of each of its halves. Using a simple form of divide and conquer will return the parity of the whole from the parity of its smaller parts.
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
	uniform_int_distribution<uint64_t> dis(0, std::numeric_limits<uint64_t>::max());
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
	TestComputePower();
	TestParity();
	TestReverseDigits();
}
