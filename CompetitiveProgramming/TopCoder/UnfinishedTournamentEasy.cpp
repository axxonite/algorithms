#include <string>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> g;

// build a dp with a separate row for each possible mean (of which there are n possible means).
// for each mean, test every combinations of allowed players in the match, from none, to all of them.
// we are essentially testing every possible match up, and using dp to ensure we don't compute the
// same values twice.
// 
double dp[1 << 20][20]; // dp of variance for a specified mask of allowed players, for a specified mean.
int def_wins[20];

struct UnfinishedTournamentEasy
{
	double maximal(vector<string> _g)
	{
		g = _g;
		n = static_cast<int>(g.size());
		double mid = 0.5; // For every win there is a loss, so we add 0.5 to the sequence of r whenever we calculate the variance.
						  // Calculate wins for each player so far.
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (g[i][j] == 'W')
					def_wins[i]++;

		// This mask will test all of 1^20 combinations.
		// The mask represents which players are allowed to play.
		for (int mask = 1; mask < (1 << n); mask++)
		{
			for (int i = 0; i < n; i++)
			{
				if (!(mask & (1 << i))) // Skip if mask bit is not set for player i
					continue;
				int cnt = def_wins[i];
				for (int j = 0; j < n; j++)
				{
					if (i == j) // can't play against yourself.
						continue;
					if (!(mask & (1 << j))) // Skip if mask is not set for player j
						continue;
					if (g[i][j] == '?') // if an unknown match, mark it as a win for player i
						cnt++;
				}
				// See how many wins player i has, calculate mean of wins.
				double winRate = cnt;
				winRate /= n - 1; // Divide by n - 1 to get the win rate;  n - 1 since you can't win against yourself.
								  // Is this the mean???

								  // cnt can only take a value from 0..20. Hence winrate can only have one of 21 possibles values.

								  // ????? for all c
				for (int j = cnt; j < n; j++)
					// add player i to the variance of another subset of players.
					// take the variance for when all other players besides i are allowed to play, add the current variance, and test if we get a better variance.
					// For a given cnt, we should always be adding the same winrate here, so it's constant...
					// So we take the mask where player i is not playing and where the mean is 1/cnt, and we add another constant to it.
					// We do this for all js higher than cnt... why?
					// maybe cnt is not wins.
					dp[mask][j] = max(dp[mask][j], dp[mask ^ (1 << i)][cnt] + (mid - winRate) * (mid - winRate));
			}
		}
		// print dp[1][2];

		double _max = 0;
		for (int i = 0; i < n; i++)
			_max = max(_max, dp[(1 << n) - 1][i]); // all players allowed to play, and every possible mean.
		return _max / n;
	}
};