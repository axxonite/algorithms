#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
	LRUCache(size_t capacity) : m_capacity(capacity)
	{
	}

	int get(int key)
	{
		auto it = m_map.find(key);
		if (it == m_map.end())
			return -1;
		m_lru.splice(m_lru.begin(), m_lru, it->second); // move the node corresponding to key to front
		return it->second->second;
	}

	void set(int key, int value)
	{
		auto it = m_map.find(key);
		if (it != m_map.end())
		{
			m_lru.splice(m_lru.begin(), m_lru, it->second);  // move the node corresponding to key to front
			it->second->second = value;
			return;
		}
		if (m_map.size() == m_capacity) //reached capacity
		{
			int keyToDel = m_lru.back().first;
			m_lru.pop_back();
			m_map.erase(keyToDel);
		}
		m_lru.emplace_front(key, value);
		m_map[key] = m_lru.begin();
	}
private :
	size_t m_capacity;
	unordered_map<int, list<pair<int, int>>::iterator> m_map;
	list<pair<int, int>> m_lru;

};
