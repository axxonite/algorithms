#include "stdafx.h"

using namespace std;

namespace Solutions
{
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
			if (!Search(key, [&](list<KeyValuePair> & l, list<KeyValuePair> ::iterator & it) { it->value = value; }))
				slots[hash(key) % MaxSlots].emplace_back(KeyValuePair{ key, value });
		}

		bool Remove(const Key& key)
		{
			return Search(key, [](list<KeyValuePair> & l, list<KeyValuePair>::iterator & it) { l.erase(it); });
		}

		const Value& operator [] (Key key)
		{
			const Value* value;
			if (!Search(key, [&](list<KeyValuePair> & l, list<KeyValuePair> ::iterator & it) { value = &it->value; }))
				throw invalid_argument("");
			return *value;
		}

	private:

		struct KeyValuePair
		{
			Key key;
			Value value;
		};
		vector<list<KeyValuePair>> slots;
		HashFunc hash;

		template <typename T>
		bool Search(const Key& key, T&& func)
		{
			int slot = hash(key) % MaxSlots;
			for (auto it = slots[slot].begin(); it != slots[slot].end(); ++it)
			{
				if (it->key == key)
				{
					func(slots[slot], it);
					return true;
				}
			}
			return false;
		}
	};
}