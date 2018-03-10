// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// A tricky implementation due to the particulars of STL.
	template <size_t capacity>
	class LRUCache
	{

	public:
		bool Lookup( int isbn, int* price )
		{
			auto it = lookup.find( isbn );
			if ( it == lookup.end() )
				return false;
			*price = it->second.price;
			lruCache.erase( it->second.lru );
			lruCache.emplace_front( isbn );
			it->second.lru = lruCache.begin(); // Tricky part here. Iterators don't stay valid once you erase them from a list. You need to reassign a new iterator.
			return true;
		}

		void Insert( int isbn, int price )
		{
			int outPrice;
			if ( !Lookup( isbn, &outPrice ) )
			{
				if ( lookup.size() == capacity )
				{
					lookup.erase( lruCache.back() );
					lruCache.pop_back();
				}
				lruCache.emplace_front( isbn );
				lookup[isbn] = { lruCache.begin(), price };
			}
		}

		bool Erase( int isbn )
		{
			auto it = lookup.find( isbn );
			if ( it != lookup.end() )
			{
				lruCache.erase( it->second.lru );
				lookup.erase( it );
				return true;
			}
			return false;
		}

	private:

		struct CacheEntry
		{
			// Keep a pointer to the lru entry here.
			list<int>::iterator lru;
			int price;
		};
		unordered_map<int, CacheEntry> lookup;
		list<int> lruCache; // Easiest to keep the isbn values in the lru, although in a real world scenario that would be suboptimal.

	};
}