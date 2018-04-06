// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int MaxSquareSubmatrix( const vector<deque<bool>>& A ) 
{
	return 0;
}
#pragma region Test

int MaxSquareSubmatrixSpaceEfficient( const vector<deque<bool>>& A ) 
{
	vector<int> pre( A.front().size(), 0 );
	int max_side = 0;
	for ( const deque<bool>& row : A ) {
		vector<int> curr( begin( row ), end( row ) );
		for ( int j = 1; j < curr.size(); ++j ) {
			curr[j] *= ( min( { pre[j - 1], pre[j], curr[j - 1] } ) + 1 );
		}
		max_side = max( max_side, *max_element( begin( curr ), end( curr ) ) );
		pre = move( curr );
	}
	return max_side * max_side;
}

// O(m^3 n^3) time solution.
int MaxSquareSubmatrixCheckAns( const vector<deque<bool>>& A ) {
	int max = 0;
	for ( int a = 0; a < A.size(); ++a ) {
		for ( int b = 0; b < A[a].size(); ++b ) {
			for ( int r = 1; a + r <= A.size() && b + r <= A[0].size(); ++r ) {
				int count = 0;
				bool all_1 = true;
				for ( int c = a; c < a + r; ++c ) {
					for ( int d = b; d < b + r; ++d ) {
						if ( A[c][d] ) {
							++count;
						}
						else {
							all_1 = false;
							count = 0;
							break;
						}
					}
					if ( all_1 == false ) {
						break;
					}
				}
				if ( count > max ) {
					max = count;
				}
			}
		}
	}
	return max;
}

void MaxSquareSubmatrixTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times )
	{
		int n, m;
		uniform_int_distribution<int> dis( 1, 50 );
		n = dis( gen ), m = dis( gen );
		vector<deque<bool>> A( n, deque<bool>( m ) );
		for ( int i = 0; i < n; ++i ) {
			for ( int j = 0; j < m; ++j ) {
				uniform_int_distribution<int> true_or_false( 0, 1 );
				A[i][j] = true_or_false( gen ) ? true : false;
			}
		}
		for ( int i = 0; i < n; ++i ) {
			for ( int j = 0; j < m; ++j ) {
				cout << A[i][j] << ' ';
			}
			cout << endl;
		}
		cout << MaxSquareSubmatrix( A ) << endl;
		cout << MaxSquareSubmatrixCheckAns( A ) << endl;
		cout << MaxSquareSubmatrixSpaceEfficient( A ) << endl;
		assert( MaxSquareSubmatrixCheckAns( A ) == MaxSquareSubmatrix( A ) );
		assert( MaxSquareSubmatrix( A ) == MaxSquareSubmatrixSpaceEfficient( A ) );
	}
#endif
}

#pragma endregion
