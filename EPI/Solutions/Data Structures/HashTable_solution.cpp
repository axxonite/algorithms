#include "stdafx.h"

using namespace std;

namespace Solutions
{
	template<class Key, class Value, typename HashFunc >
	class HashTable
	{
	public:

		HashTable() : hashSlots(MaxSlots)
		{
		}

		void Insert(const Key& key, const Value& value)
		{
			auto& slot = hashSlots[hash(key) % MaxSlots];
			for (auto it = slot.begin(); it != slot.end(); ++it)
			{
				if (it->key == key)
				{
					it->value = value;
					return;
				}
			}
			slot.emplace_back(KeyValuePair{ key, value });
		}

		bool Remove(const Key& key)
		{
			auto& slot = hashSlots[hash(key) % MaxSlots];
			for (auto it = slot.begin(); it != slot.end(); ++it)
			{
				if (it->key == key)
				{
					slot.erase(it);
					return true;
				}
			}
			return false;
		}

		const Value& operator [] (Key key)
		{
			auto& slot = hashSlots[hash(key) % MaxSlots];
			for (auto it = slot.begin(); it != slot.end(); ++it)
			{
				if (it->key == key)
					return it->value;
			}
			throw invalid_argument("");
		}

	private:

		struct KeyValuePair
		{
			Key key;
			Value value;
		};

		const int MaxSlots = 0x1000;

		vector<list<KeyValuePair>> hashSlots;
		HashFunc hash;
	};
}