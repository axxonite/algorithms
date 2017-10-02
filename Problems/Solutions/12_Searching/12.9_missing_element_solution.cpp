// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindMissingElement(ifstream* ifs)
	{
		const int kNumBucket = 1 << 16;
		vector<size_t> counter(kNumBucket, 0);
		unsigned int x;
		while (*ifs >> x)
		{
			int upperPartX = x >> 16;
			++counter[upperPartX];
		}

		// Look for a bucket that contains less than (1 << 16) elements.
		const int kBucketCapacity = 1 << 16;
		int candidateBucket = 0;
		for (int i = 0; i < kNumBucket; ++i)
		{
			if (counter[i] < kBucketCapacity)
			{
				candidateBucket = i;
				break;
			}
		}

		// Finds all IP addresses in the stream whose first 16 bits
		// are equal to candidate_bucket.
		ifs->clear();
		ifs->seekg(0, ios::beg);
		bitset<kBucketCapacity> bitVec;
		while (*ifs >> x)
		{
			int upperPartX = x >> 16;
			if (candidateBucket == upperPartX)
			{
				// Records the presence of 16 LSB of x.
				int lowerPartX = ((1 << 16) - 1) & x;
				bitVec.set(lowerPartX);
			}
		}
		ifs->close();

		// At least one of the LSB combinations is absent, find it.
		for (int i = 0; i < kBucketCapacity; ++i)
			if (bitVec[i] == 0)
				return (candidateBucket << 16) | i;
		throw invalid_argument("no missing element");
	}
}
