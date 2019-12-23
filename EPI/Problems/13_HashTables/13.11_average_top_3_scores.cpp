// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

// #define TEST

// todo review ifstream vs stringstream
string FindStudentWithHighestBestOfThreeScores( ifstream* nameScoreData ) 
{
	string result;
	return result;
}

#pragma region Test

void FindStudentWithHighestBestOfThreeScoresSimpleTest() 
{
	ofstream ofs( "scores.txt" );
	ofs << "adnan 100";
	ofs << "amit 99";
	ofs << "adnan 98";
	ofs << "thl 90";
	ofs << "adnan 10";
	ofs << "amit 100";
	ofs << "thl 99";
	ofs << "thl 95";
	ofs << "dd 100";
	ofs << "dd 100";
	ofs << "adnan 95";
	ofs.close();
	ifstream name_score_data( "scores.txt" );
	string result = FindStudentWithHighestBestOfThreeScores( &name_score_data );
	cout << "result = " << result << endl;
	assert( result == "adnan" );
}

void FindStudentWithHighestBestOfThreeScoresTest()
{
#ifdef TEST
	FindStudentWithHighestBestOfThreeScoresSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	uniform_int_distribution<int> dis( 1, 10000 );
	int n = dis( gen );
	ofstream ofs( "/tmp/scores.txt" );
	for ( int i = 0; i < n; ++i ) {
		uniform_int_distribution<int> test_num_dis( 0, 20 );
		int test_num = test_num_dis( gen );
		uniform_int_distribution<int> len_dis( 5, 10 );
		string name = RandString( len_dis( gen ) );
		while ( test_num-- ) {
			uniform_int_distribution<int> score_dis( 0, 100 );
			ofs << name << " " << score_dis( gen ) << endl;
		}
	}
	ofs.close();
	ifstream name_score_data( "/tmp/scores.txt" );
	string name = FindStudentWithHighestBestOfThreeScores( &name_score_data );
	cout << "top student is " << name << endl;
	// Remove file after the execution.
	// remove("score.txt");
#endif
}

#pragma endregion