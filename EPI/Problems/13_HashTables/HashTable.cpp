#include "stdafx.h"

using namespace std;

#define TEST 0

template<class Key, class Value, typename HashFunc >
class HashTable
{
public:

	HashTable() : hashSlots(MaxSlots)
	{
	}

	void Insert(const Key& key, const Value& value)
	{
	}

	bool Remove(const Key& key)
	{
		return false;
	}

	const Value& operator [] (Key key)
	{
	}

private:

};

#pragma region Test

struct HashFunc
{
	unsigned long operator () (const string& obj) const
	{
		return static_cast<unsigned long>(std::hash<std::string>{}(obj));
	}
};

void HashTableTest()
{
#if TEST
	HashTable<string, int, HashFunc> hashTable;
	hashTable.Insert("Test2", 999);
	hashTable.Insert("Test", 1);
	assert(hashTable["Test2"] == 999);
	hashTable.Remove("Test2");
	try
	{
		assert(hashTable["Test2"] == 999);
	}
	catch (const invalid_argument&)
	{
	}
	assert(hashTable["Test"] == 1);
	try
	{
		assert(hashTable["Test3"] == 1234);
	}
	catch (const invalid_argument&)
	{
	}
#endif
}

#pragma endregion