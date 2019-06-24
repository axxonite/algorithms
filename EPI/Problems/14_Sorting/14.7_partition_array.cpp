// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

// #define TEST

struct Person 
{
	int age;
	string name;
};

void GroupByAge( vector<Person>& people ) 
{
}

#pragma region Test

static void GroupByAgeSimpleTest() 
{
	vector<Person> people = { Person( { 20, "foo" } ), Person( { 10, "bar" } ), Person( { 20, "widget" } ), Person( { 20, "something" } ) };

	GroupByAge( people );
	if ( people[0].age == 10 )
		assert( people[1].age == 20 && people[2].age == 20 && people[3].age == 20 );
	else
		assert( people[1].age == 20 && people[2].age == 20 && people[3].age == 10 );
}

void GroupByAgeTest()
{
#ifdef TEST
	GroupByAgeSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 10; ++times ) 
	{
    uniform_int_distribution<int> dis( 1, 10000 );
		int size = dis(gen);
		int k;
		uniform_int_distribution<int> dis2( 1, size );
		k = dis2( gen );
		vector<Person> people;
		uniform_int_distribution<int> k_dis( 0, k - 1 );
		uniform_int_distribution<int> len_dis( 1, 10 );
		for ( int i = 0; i < size; ++i ) 
			people.emplace_back( Person{ k_dis( gen ), RandString( len_dis( gen ) ) } );
		unordered_set<int> age_set;
		for ( const Person& p : people ) 
			age_set.emplace( p.age );

		GroupByAge( people );

		// Check the correctness of sorting.
		int diff_count = 1;
		for ( int i = 1; i < people.size(); ++i ) 
		{
			if ( people[i].age != people[i - 1].age ) 
				++diff_count;
		}
		assert( diff_count == age_set.size() );
	}
#endif
}

#pragma endregion
