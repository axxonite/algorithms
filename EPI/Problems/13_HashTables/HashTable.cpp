#include "stdafx.h"

using namespace std;

// #define TEST

const unsigned int MaxSlots = 1000;

template<class Key, class Value, typename HashFunc >
class HashTable
{
public:

	HashTable() : slots(MaxSlots)
	{
	}

	void Insert(const Key& key, const Value& value)
	{
	}

	bool Remove(const Key& key)
	{
    return true;
	}

	const Value& operator [] (Key key)
	{
    return Value();
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
#ifdef TEST
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
	hashTable.Insert("Test2", 22);
	assert(hashTable["Test2"] == 22);
#endif
}

#pragma endregion