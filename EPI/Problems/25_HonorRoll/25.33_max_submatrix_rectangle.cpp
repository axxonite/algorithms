// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 1

struct MaxHW
{
	int w, h;
};

int MaxRectangleSubmatrix( const vector<deque<bool>>& a )
{
	vector<vector<MaxHW>> longestSpans(a.size(), vector<MaxHW>(a[0].size()));
	for (int i = a.size() - 1; i >= 0; --i)
		for (int j = a[i].size() - 1; j >= 0; --j)
			longestSpans[i][j] = a[i][j] ? 
				MaxHW{ i + 1 < a.size() ? longestSpans[i+1][j].w + 1 : 1, j + 1 < a[i].size() ? longestSpans[i][j+1].h : 1} : 
				MaxHW{ 0, 0 };

	int best = 0;
	for ( int i = 0; i < a.size(); ++i)
		for( int j = 0; j < a[i].size(); ++j)
			if ( a[i][j] && longestSpans[i][j].w * longestSpans[i][j].h > best)
			{
				int minWidth = numeric_limits<int>::max();
				for ( int k = 0; k < longestSpans[i][j].h; ++k)
				{
					minWidth = min(minWidth, longestSpans[i][j].w);
					best = max(best, (k + 1) * minWidth);
				}
			}
	return best;
}

#pragma region Test

int MaxRectangleSubmatrixBruteForce( const vector<deque<bool>> &A ) {
	int max = 0;
	for ( int a = 0; a < A.size(); ++a ) {
		for ( int b = 0; b < A[a].size(); ++b ) {
			for ( int c = a; c < A.size(); ++c ) {
				for ( int d = b; d < A[c].size(); ++d ) {
					bool all_1 = true;
					int count = 0;
					for ( int i = a; i <= c; ++i ) {
						for ( int j = b; j <= d; ++j ) {
							if ( A[i][j] == false ) {
								all_1 = false;
								count = 0;
								break;
							}
							else {
								++count;
							}
						}
						if ( all_1 == false ) {
							break;
						}
					}
					if ( all_1 == true && count > max ) {
						max = count;
					}
				}
			}
		}
	}
	return max;
}

void MaxRectangleSubmatrixTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times ) {
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
		cout << MaxRectangleSubmatrix( A ) << endl;
		int test_area = MaxRectangleSubmatrixBruteForce( A );
		cout << test_area << endl;
		assert( test_area == MaxRectangleSubmatrix( A ) );
	}
#endif
}

#pragma endregion
