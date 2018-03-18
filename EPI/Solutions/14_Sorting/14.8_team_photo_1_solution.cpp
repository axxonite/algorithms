// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Player
	{
		int height;

		bool operator < (const Player& other) const
		{
			return height < other.height;
		}
	};

	class Team
	{
	public:
		explicit Team(const vector<int>& height)
		{
			for (int h : height)
				players_.emplace_back(Player{ h });
		}

		// Checks if A can be placed in front of B.
		static bool valid_placement_exists(const Team& a, const Team& b)
		{
			vector<Player> sortedA = a.SortPlayers();
			vector<Player> sortedB = b.SortPlayers();
			for (int i = 0; i < sortedA.size() && i < sortedB.size(); ++i)
				if (sortedA[i].height >= sortedB[i].height)
					return false;
			return true;
		}

	private:
		vector<Player> players_;

		vector<Player> SortPlayers() const
		{
			vector<Player> result(players_);
			sort(result.begin(), result.end());
			return result;
		}
	};
}
