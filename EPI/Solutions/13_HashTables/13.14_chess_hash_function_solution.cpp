// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct ChessState
	{
		array<unsigned char, 32> bytes;

		ChessState()
		{
			for ( int i = 0; i < 32; ++i )
				bytes[i] = 0;
		}

		unsigned char Get( int y, int x ) const
		{
			int index = y * 8 + x;
			int mask = index % 2 ? 0xf0 : 0x0f;
			return bytes[index / 2] & mask;
		}

		void Set( int y, int x, unsigned char value )
		{
			int index = y * 8 + x;
			int mask = index % 2 ? 0xf0 : 0x0f;
			int shift = index % 2 ? 4 : 0;
			bytes[index / 2] = ( bytes[index / 2] & ~mask ) | ( value << shift );
		}
	};

	long long hashCodes[8][8][13];

	void InitHashes()
	{
		default_random_engine rnd;
		unordered_set<long long> hashes;
		uniform_int_distribution<long long> dis( 0, numeric_limits<long long>::max() );
		for ( int i = 0; i < 8; ++i )
		{
			for ( int j = 0; j < 8; ++j )
			{
				for ( int k = 0; k < 13; ++k )
				{
					do
					{
						hashCodes[i][j][k] = dis( rnd );
					} 
					while ( !hashes.emplace( hashCodes[i][j][k] ).second ); // Check for collisions.
				}
			}
		}
	}

	// Tricky.
	long long ChessHash( ChessState& state, long long stateHash, const pair<int, int>& start, const pair<int, int>& dest )
	{
		long long newHash = stateHash;
		newHash ^= hashCodes[start.first][start.second][state.Get( start.first, start.second )]; // Clear state at starting position.
		newHash ^= hashCodes[start.first][start.second][0]; // Add blank state at starting position.
		newHash ^= hashCodes[dest.first][dest.second][state.Get( dest.first, dest.second )]; // Remove state at destination.
		newHash ^= hashCodes[dest.first][dest.second][state.Get( start.first, start.second )]; // Add state at destination.
		state.Set( dest.first, dest.second, state.Get( start.first, start.second ) );
		state.Set( start.first, start.second, 0 );
		return newHash;
	}
}