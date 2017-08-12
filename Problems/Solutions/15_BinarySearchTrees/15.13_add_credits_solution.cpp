// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

class ClientsCreditsInfo
{
public:
	void Insert(const string& client_id, int c)
	{
		Remove(client_id); // Remember to remove prior entry for the client if it already exists.
		// Tricky: remember to remove the offset before starting - we store all values relative to the offset since the offset is added back in at the output.
		client_to_credit_.emplace(client_id, c - offset_);
		// Note that simply referencing the entry in the map will assign a new element for the key if it doesn't exist.
		credit_to_clients_[c - offset_].emplace(client_id);
	}

	bool Remove(const string& client_id)
	{
		auto credit_iter = client_to_credit_.find(client_id);
		if (credit_iter != client_to_credit_.end())
		{
			// Remove entry from credit to client map.
			credit_to_clients_[credit_iter->second].erase(client_id);
			if (credit_to_clients_[credit_iter->second].empty()) // If this was the last client with that number of credits, remove that entry. 
				credit_to_clients_.erase(credit_iter->second);
			// Remove entry from client to credit map.
			client_to_credit_.erase(credit_iter);
			return true;
		}
		return false;
	}

	int Lookup(const string& client_id) const
	{
		auto credit_iter = client_to_credit_.find(client_id);
		// Remember to check if the client actually exists, and to add the offset.
		return credit_iter == client_to_credit_.cend() ? -1 : credit_iter->second + offset_;
	}

	void AddAll(int C) { offset_ += C; }

	string Max() const
	{
		// Use a constant reverse iterator so we get the max value.
		auto iter = credit_to_clients_.crbegin();
		return iter == credit_to_clients_.crend() || iter->second.empty() ? "" : *iter->second.cbegin();
	}

private:
	int offset_ = 0; // the global offset.
	unordered_map<string, int> client_to_credit_; // map client to credits.
	map<int, unordered_set<string>> credit_to_clients_; // map credits to client - this is an ordered BST, actually.
};
