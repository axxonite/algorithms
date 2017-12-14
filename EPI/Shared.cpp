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