#include "stdafx.h"

using namespace std;

namespace Solutions
{
	const unsigned int MaxSlots = 1000;

  // is there any way to simplify this?
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
		bool Search(const Key& key, T& func)
		{
			// find the hash slot for the given key.
			auto& l = slots[hash(key) % MaxSlots];
			// find the key within the hash slot.
			auto it = std::find_if(l.begin(), l.end(), [&](const KeyValuePair& kvp) { return kvp.key == key; });
			if (it != l.end())
			{
			// run lambda on that item.
				func(l, it);
				return true;
			}
			return false;
		}
	};
}