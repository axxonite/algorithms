#include "stdafx.h"
#include "PrimitiveTypes.h"

int parityLookupTable[0xFFFF];

int ComputeParity(long in)
{
	auto parity = ((in >> 8) & 0xFF) ^ (in & 0xFF);
	parity = ((parity >> 4) & 0xF) ^ (parity & 0xF);
	parity = ((parity >> 2) & 0x3) ^ (parity & 0x3);
	return ((parity >> 1) & 0x1) ^ (parity & 0x1);
}

void ComputeParity(int count, uint64_t* input, int* output)
{
	for ( auto i = 0; i < 0xFFFF; i++)
		parityLookupTable[i] = ComputeParity(i);
	for ( auto i = 0; i < count; i++)
		output[i] = ComputeParity(parityLookupTable[input[i] & 0xFFFF] ^ parityLookupTable[(input[i] >> 16) & 0xFFFF]);
}

double ComputePower(double x, int y)
{
	// I don't have a very clear idea of what to do here. I would need to study this problem further. I need to study the math proof and its properties.
	auto val = x; 
	while ( y  > 0)
	{
		auto result = val * val;
		if (y & 1)
			result *= x;
	}

	return 0;
}

int ReverseDigits(int x)
{
	auto result = 0;
	auto neg = x < 0;
	x = abs(x);
	while ( x > 0)
	{
		result = result * 10 + x % 10;
		x = x / 10;
	}
	return result * (neg ? -1 : 1);
}

void PrimitiveTypeTests()
{
	auto parity = ComputeParity(0b1011);
	assert(parity == 1);
	parity = ComputeParity(0b10001000);
	assert(parity == 0);
	// todo do I need all this stuff here??? I'm going to mess it up during an interview.
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int<uint64_t> dis(0, std::numeric_limits<long>::max());
	uint64_t input[1000];
	int output[1000];
	for (auto i = 0; i < 1000; i++)
		input[i] = dis(gen);
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

	auto reversed = ReverseDigits(42);
	assert(reversed == 24);
	reversed = ReverseDigits(-314);
	assert(reversed == -413);
}