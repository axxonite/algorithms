#include "stdafx.h"

string RandString(int len)
{
	string ret;
	default_random_engine gen((random_device())());
	while (len--)
	{
		uniform_int_distribution<int> dis('a', 'z');
		ret += dis(gen);
	}
	return ret;
}

string RandIntString( int len )
{
	default_random_engine gen( ( random_device() )( ) );
	string ret;
	if ( len == 0 )
		return { "0" };
	uniform_int_distribution<int> pos_or_neg( 0, 1 );
	if ( pos_or_neg( gen ) )
		ret.push_back( '-' );
	uniform_int_distribution<int> num_dis( '1', '9' );
	ret.push_back( num_dis( gen ) );
	while ( --len )
	{
		uniform_int_distribution<int> dis( '0', '9' );
		ret.push_back( dis( gen ) );
	}
	return ret;
}