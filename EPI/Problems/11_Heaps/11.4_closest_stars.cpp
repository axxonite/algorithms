// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

struct Star 
{
	double x, y, z;

	double Distance() const { return sqrt( x * x + y * y + z * z ); } // why use a square root here?
};

// note: the stars should be returned in order of increasing distance.
vector<Star> FindClosestKStars( int k, istringstream* stars ) 
{
   return {};
}

#pragma region Test

string CreateStreamingString( const vector<Star>& stars ) {
	string s;
	for ( int i = 0; i < stars.size(); ++i ) {
		stringstream ss;
		ss << stars[i].x << ',' << stars[i].y << ',' << stars[i].z << endl;
		s += ss.str();
	}
	return s;
}

void FindClosestKStarsSimpleTest() {
	vector<Star> stars;
	stars.emplace_back( ( Star{ 1, 2, 3 } ) );
	stars.emplace_back( ( Star{ 5, 5, 5 } ) );
	stars.emplace_back( ( Star{ 0, 2, 1 } ) );
	stars.emplace_back( ( Star{ 9, 2, 1 } ) );
	stars.emplace_back( ( Star{ 1, 2, 1 } ) );
	stars.emplace_back( ( Star{ 2, 2, 1 } ) );
	istringstream sin( CreateStreamingString( stars ) );
	vector<Star> closest_stars = FindClosestKStars( 3, &sin );
	assert( 3 == closest_stars.size() );
	assert( closest_stars[0].Distance() == ( Star{ 0, 2, 1 }.Distance() ) );
	assert( closest_stars[0].Distance() == ( Star{ 2, 0, 1 }.Distance() ) );
	assert( closest_stars[1].Distance() == ( Star{ 1, 2, 1 }.Distance() ) );
	assert( closest_stars[1].Distance() == ( Star{ 1, 1, 2 }.Distance() ) );

	stars.clear();
	stars.emplace_back( ( Star{ 1, 2, 3 } ) );
	stars.emplace_back( ( Star{ 5, 5, 5 } ) );
	stars.emplace_back( ( Star{ 4, 4, 4 } ) );
	stars.emplace_back( ( Star{ 3, 2, 1 } ) );
	stars.emplace_back( ( Star{ 5, 5, 5 } ) );
	stars.emplace_back( ( Star{ 3, 2, 3 } ) );
	stars.emplace_back( ( Star{ 3, 2, 3 } ) );
	stars.emplace_back( ( Star{ 3, 2, 1 } ) );
	istringstream sin2( CreateStreamingString( stars ) );
	closest_stars = FindClosestKStars( 2, &sin2 );
	assert( 2 == closest_stars.size() );
	assert( closest_stars[0].Distance() == ( Star{ 1, 2, 3 }.Distance() ) );
	assert( closest_stars[1].Distance() == ( Star{ 3, 2, 1 }.Distance() ) );
}

void FindClosestKStarsTest()
{
#ifdef TEST
	FindClosestKStarsSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 20; ++times )
	{
		int num, k;
		uniform_int_distribution<int> num_dis( 1, 10000 );
		num = num_dis( gen );
		uniform_int_distribution<int> k_dis( 1, num );
		k = k_dis( gen );
		vector<Star> stars;
		// Randomly generate num of stars.
		uniform_real_distribution<double> dis( 0, 10000 );
		for ( int i = 0; i < num; ++i )
			stars.emplace_back( Star{ dis( gen ), dis( gen ), dis( gen ) } );
		istringstream sin( CreateStreamingString( stars ) );
		vector<Star> closest_stars( FindClosestKStars( k, &sin ) );
		sort( closest_stars.begin(), closest_stars.end() );
		sort( stars.begin(), stars.end() );
		cout << "k = " << k << endl;
		cout << stars[k - 1].x << " " << stars[k - 1].y << " " << stars[k - 1].z << " " << stars[k - 1].Distance() << endl;
		cout << closest_stars.back().x << " " << closest_stars.back().y << " " << closest_stars.back().z << " " << closest_stars.back().Distance() << endl;
		assert( fabs( stars[k - 1].Distance() - closest_stars.back().Distance() ) < 1.0e-2 );
	}
#endif
}

#pragma endregion