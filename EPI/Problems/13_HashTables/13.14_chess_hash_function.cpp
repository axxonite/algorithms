// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

enum SquareState
{
	Blank,
	BlackPawn,
	BlackBishop,
	BlackKnight,
	BlackRook,
	BlackQueen,
	BlackKing,
	WhitePawn,
	WhiteBishop,
	WhiteKnight,
	WhiteRook,
	WhiteQueen,
	WhiteKing,
};

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

void InitHashes()
{
}

long long InitHash(const ChessState& state)
{
	return 0;
}


long long ChessHash( ChessState& state, long long stateHash, int srcY, int srcX, int dstY, int dstX )
{
	return 0;
}

#pragma region Test

void ChessHashTest()
{
#if TEST
	InitHashes();
	ChessState state;
	state.Set( 0, 0, BlackRook );
	state.Set( 0, 1, BlackKnight );
	state.Set( 0, 2, BlackBishop );
	state.Set( 0, 3, BlackQueen );
	state.Set( 0, 4, BlackKing );
	state.Set( 0, 5, BlackBishop );
	state.Set( 0, 6, BlackKnight );
	state.Set( 0, 7, BlackRook );
	state.Set( 7, 0, WhiteRook );
	state.Set( 7, 1, WhiteKnight );
	state.Set( 7, 2, WhiteBishop );
	state.Set( 7, 3, WhiteQueen );
	state.Set( 7, 4, WhiteKing );
	state.Set( 7, 5, WhiteBishop );
	state.Set( 7, 6, WhiteKnight );
	state.Set( 7, 7, WhiteRook );
	state.Set( 1, 0, BlackPawn );
	state.Set( 1, 1, BlackPawn );
	state.Set( 1, 2, BlackPawn );
	state.Set( 1, 3, BlackPawn );
	state.Set( 1, 4, BlackPawn );
	state.Set( 1, 5, BlackPawn );
	state.Set( 1, 6, BlackPawn );
	state.Set( 1, 7, BlackPawn );
	state.Set( 7, 0, WhitePawn );
	state.Set( 7, 1, WhitePawn );
	state.Set( 7, 2, WhitePawn );
	state.Set( 7, 3, WhitePawn );
	state.Set( 7, 4, WhitePawn );
	state.Set( 7, 5, WhitePawn );
	state.Set( 7, 6, WhitePawn );
	state.Set( 7, 7, WhitePawn );
	long long hash1 = InitHash( state );
	long long hash2 = ChessHash( state, hash1, 1, 3, 3, 3 );
	assert( hash2 != hash1 );
	long long hash3 = ChessHash( state, hash1, 3, 3, 1, 3 );
	assert( hash3 == hash1 );
	long long hash4 = ChessHash( state, hash1, 0, 3, 7, 3 );
	long long hash5 = ChessHash( state, hash1, 7, 3, 0, 3 );
	assert( hash4 != hash5 );
#endif
}

#pragma endregion