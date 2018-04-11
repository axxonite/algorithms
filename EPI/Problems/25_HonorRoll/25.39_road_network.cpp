// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct HighwaySection 
{
	int x, y;
	double distance;
};

HighwaySection FindBestProposals( const vector<HighwaySection>& H, const vector<HighwaySection>& P, int n )
{
	return {};
}

#pragma region Test

void FindBestProposalsSimpleTest() {
	vector<HighwaySection> H = { HighwaySection{ 0, 1, 10 },
		HighwaySection{ 1, 2, 10 },
		HighwaySection{ 2, 3, 10 } };
	vector<HighwaySection> P = { HighwaySection{ 0, 3, 1 },
		HighwaySection{ 0, 2, 2 },
		HighwaySection{ 0, 1, 3 } };
	HighwaySection t = FindBestProposals( H, P, 4 );
	assert( t.x == 0 && t.y == 3 && t.distance == 1.0 );
}

void FindBestProposalsTest()
{
#if TEST
	FindBestProposalsSimpleTest();
	for ( int times = 0; times < 2; ++times ) {
		default_random_engine gen( ( random_device() )( ) );
		int n, m, k;
		uniform_int_distribution<int> five_to_100( 5, 100 );
		n = five_to_100( gen );
		uniform_int_distribution<int> dis1( 1, n * ( ( n - 1 ) / 2 ) - 1 );
		m = dis1( gen );
		uniform_int_distribution<int> dis2( 1, n * ( ( n - 1 ) / 2 ) - m );
		k = dis2( gen );
		cout << "n = " << n << ", m = " << m << ", k = " << k << endl;

		vector<deque<bool>> have_edges( n, deque<bool>( n, false ) );
		vector<HighwaySection> H;  // Existing highway sections
		uniform_int_distribution<int> vertex_dis( 0, n - 1 );
		uniform_real_distribution<double> cost_dis( 1.0, 10000.0 );
		for ( int i = 0; i < m; ++i ) {
			int a, b;
			do {
				a = vertex_dis( gen ), b = vertex_dis( gen );
			} while ( a == b || have_edges[a][b] == true );
			have_edges[a][b] = have_edges[b][a] = true;
			H.emplace_back( HighwaySection{ a, b, cost_dis( gen ) } );
		}
		//*
		for ( int i = 0; i < m; ++i ) {
			cout << "H[i] = " << H[i].x << " " << H[i].y << " " << H[i].distance
				<< endl;
		}
		//*/

		vector<HighwaySection> P;  // Proposals
		for ( int i = 0; i < k; ++i ) {
			int a, b;
			do {
				a = vertex_dis( gen ), b = vertex_dis( gen );
			} while ( a == b || have_edges[a][b] == true );
			have_edges[a][b] = have_edges[b][a] = true;
			uniform_real_distribution<double> new_cost_dis( 1.0, 50.0 );
			P.emplace_back( HighwaySection{ a, b, new_cost_dis( gen ) } );
		}
		//*
		for ( int i = 0; i < k; ++i ) {
			cout << "P[i] = " << P[i].x << " " << P[i].y << " " << P[i].distance
				<< endl;
		}
		//*/

		HighwaySection t = FindBestProposals( H, P, n );
		cout << t.x << ' ' << t.y << ' ' << t.distance << endl;
	}
#endif
}

#pragma endregion
