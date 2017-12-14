// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindMissingElement(ifstream* ifs)
	{
		// Count how many elements there are in each bucket.
		const int kNumBucket = 1 << 16;
		vector<size_t> bucketCount(kNumBucket, 0);
		unsigned int x;
		while (*ifs >> x)
			++bucketCount[x >> 16];

		// Find a bucket that is not filled to capacity.
		const int kBucketCapacity = 1 << 16;
		int candidateBucket = 0;
		for (int i = 0; i < kNumBucket; ++i)
		{
			if (bucketCount[i] < kBucketCapacity)
			{
				candidateBucket = i;
				break;
			}
		}

		// Find all elements for the candidate bucket and record the presence of the 16 bit LSB.
		ifs->clear();
		ifs->seekg(0, ios::beg);
		bitset<kBucketCapacity> bitVec;
		while (*ifs >> x)
		{
			if (candidateBucket == (x >> 16))
				bitVec.set(((1 << 16) - 1) & x);
		}
		ifs->close();

		// Find which 16 bit value is missing.
		for (int i = 0; i < kBucketCapacity; ++i)
			if (bitVec[i] == 0)
				return (candidateBucket << 16) | i;
		throw invalid_argument("no missing element");
	}
}
