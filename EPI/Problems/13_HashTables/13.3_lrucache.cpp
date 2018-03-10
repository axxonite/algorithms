// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

// A tricky implementation due to the particulars of STL.
template <size_t capacity>
class LRUCache
{

public:
	bool Lookup( int isbn, int* price )
	{
		return false;
	}

	void Insert( int isbn, int price )
	{
	}

	bool Erase( int isbn )
	{
		return false;
	}

private:

};

#pragma region Test

void LRUCacheTest()
{
#if TEST
	const int kCapacity = 2;
	{
		LRUCache<kCapacity> c;
		cout << "c.Insert(1, 1)" << endl;
		c.Insert( 1, 1 );
		cout << "c.Insert(1, 10)" << endl;
		c.Insert( 1, 10 );
		int val;
		cout << "c.Lookup(2, val)" << endl;
		assert( !c.Lookup( 2, &val ) );
		cout << "c.Lookup(1, val)" << endl;
		assert( c.Lookup( 1, &val ) );
		assert( val == 1 );
		c.Erase( 1 );
		assert( !c.Lookup( 1, &val ) );
	}

	// test capacity constraints honored, also FIFO ordering
	{
		LRUCache<kCapacity> c;
		c.Insert( 1, 1 );
		c.Insert( 2, 1 );
		c.Insert( 3, 1 );
		c.Insert( 4, 1 );
		int val;
		assert( !c.Lookup( 1, &val ) );
		assert( !c.Lookup( 2, &val ) );
		assert( c.Lookup( 3, &val ) );
		assert( val == 1 );
		assert( c.Lookup( 4, &val ) );
		assert( val == 1 );
	}

	// test retrieval moves to front
	{
		LRUCache<kCapacity> c;
		c.Insert( 1, 1 );
		c.Insert( 2, 1 );
		c.Insert( 3, 1 );
		int val;
		c.Lookup( 2, &val );
		c.Insert( 4, 1 );
		assert( !c.Lookup( 1, &val ) );
		assert( c.Lookup( 2, &val ) );
		assert( val == 1 );
		assert( !c.Lookup( 3, &val ) );
		assert( c.Lookup( 4, &val ) );
		assert( val == 1 );
	}

	// test update moves to front
	{
		LRUCache<kCapacity> c;
		c.Insert( 1, 1 );
		c.Insert( 2, 1 );
		c.Insert( 3, 1 );
		c.Insert( 2, 2 );
		c.Insert( 4, 1 );
		int val;
		assert( !c.Lookup( 1, &val ) );
		assert( c.Lookup( 2, &val ) );
		assert( val == 1 );
		assert( !c.Lookup( 3, &val ) );
		assert( c.Lookup( 4, &val ) );
		assert( val == 1 );
	}

	// test remove
	{
		LRUCache<kCapacity> c;
		c.Insert( 1, 1 );
		c.Insert( 2, 1 );
		c.Erase( 2 );
		c.Insert( 3, 3 );
		int val;
		assert( c.Lookup( 1, &val ) );
		assert( val == 1 );
		assert( !c.Lookup( 2, &val ) );
		assert( c.Lookup( 3, &val ) );
		assert( val == 3 );
	}
#endif
}

#pragma endregion
