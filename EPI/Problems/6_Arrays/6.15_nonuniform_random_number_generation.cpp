// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int NonuniformRandomNumberGeneration( const vector<int>& values, const vector<double>& probabilities)
{
  return 0;
}

#pragma region Test

void NonuniformRandomNumberGenerationTest()
{
#ifdef TEST
	default_random_engine gen( ( random_device() )( ) );
	size_t n;
	uniform_int_distribution<size_t> dis( 1, 50 );
	n = dis( gen );
	vector<int> T( n );
	iota( T.begin(), T.end(), 0 );
	vector<double> P;
	double sum = 0;
	for ( size_t i = 0; i < n; ++i ) 
	{
		uniform_real_distribution<double> dis( 0.0, 1.0f );
		double pi = dis( gen );
		sum += pi;
		P.emplace_back( pi );
	}
	for (auto& p : P)
		p = p / sum;
	for ( size_t i = 0; i < T.size(); ++i ) 
		cout << T[i] << ' ';
	cout << endl;
	for ( size_t i = 0; i < P.size(); ++i )
		cout << P[i] << ' ';
	cout << endl;
	cout << NonuniformRandomNumberGeneration( T, P ) << endl;
	// Test. Perform the nonuniform random number generation for n * kTimes
	// times and calculate the distribution of each bucket.
	const size_t kTimes = 1000;
	vector<int> counts( n, 0 );
	for ( size_t i = 0; i < n * kTimes; ++i ) 
	{
		int t = NonuniformRandomNumberGeneration( T, P );
		++counts[t];
	}
	for ( size_t i = 0; i < n; ++i ) 
	{
		cout << static_cast<double>( counts[i] ) / ( n * kTimes ) << " " << P[i] << endl;
		assert( fabs( static_cast<double>( counts[i] ) / ( n * kTimes ) - P[i] ) < 0.01 );
	}
#endif
}

#pragma endregion
