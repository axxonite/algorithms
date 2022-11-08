#include "stdafx.h"
#include "Graphs.h"
#include <vector>
#include <deque>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

template <class T>
struct GraphVertex
{
	T value;
	vector<GraphVertex<T>*> edges;
};

typedef enum
{
	White,
	Gray,
	Black
} Color; // Note how enums are defined.. sigh, really? I forgot.

// ----------------------------------------------------------
//19.1 SEARCH A MAZE

struct Coordinate
{
	int x, y;
};

vector<Coordinate> SearchMaze(vector<vector<Color>>& maze, const Coordinate& s, const Coordinate& e)
{
	// Perform a breadth-first search.
	return vector<Coordinate>();
}

// ----------------------------------------------------------
// 19.2 PAINT A BOOLEAN MATRIX
void PaintBooleanMatrix(int x, int y, vector<deque<bool>>& a)
{
	// Perform a depth-first search.
}

// ----------------------------------------------------------
// 19.3 COMPUTE ENCLOSED REGIONS
void ComputeEnclosedRegions(vector<vector<char>>& a)
{
	// Start with the white cells on the edges and perform a breadth-first search from them.
}

// ----------------------------------------------------------
// 19.4 DEADLOCK DETECTION*

bool HasCycle(GraphVertex<Color>* v)
{
	if (v->value == Gray)
		return true;
	v->value = Gray;
	for (auto e : v->edges)
	{
		if (e != v && e->value != Black && HasCycle(v))
			return true;
	}
	v->value = Black;
	return false;
}

bool IsDeadlocked(const vector<GraphVertex<Color>*>& g)
{
	// A cycle exists if we start from a gray vertex and reach another gray vertex in a DFS.
	for (auto v : g)
		if (v->value == White && HasCycle(v))
			return true;
	return false;
}

// ----------------------------------------------------------
// 19.5 CLONE A GRAPH
GraphVertex<int>* CloneGraph(GraphVertex<int>* g)
{
	// Traverse the graph and use a hash table to map existing nodes to their clones.
	return nullptr;
}

// ----------------------------------------------------------
// 19.6 MAKING WIRED CONNECTIONS**
bool IsAnyPlacementPossible(GraphVertex<int>* v)
{
	queue<GraphVertex<int>*> q;
	q.emplace(v);
	while (!q.empty())
	{
		auto n = q.back();
		for (auto e : n->edges)
		{
			if (e->value == -1)
			{
				e->value = n->value + 1;
				q.emplace(e);
			}
			else if (e->value == v->value)
				return false;
		}
		q.pop();
	}
	return true;
}

bool IsAnyPlacementPossible(vector<GraphVertex<int>*> g)
{
	// If any edge is from a distance k vertex to another distance k vertex, return false.
	for (auto v : g)
		v->value = -1;
	for (auto v : g)
	{
		if (v->value == -1)
		{
			v->value = 0;
			if (!IsAnyPlacementPossible(v))
				return false;
		}
	}
	return true;
}

// ----------------------------------------------------------
// 19.7 TRANSFORM ONE STRING TO ANOTHER**
struct StringWithDistance
{
    string s;
    int dist;
};

int TransformOneStringToAnother(unordered_set<string> d, const string& s, const string& t)
{
    // Perform an inline BFS search, building the graph as you go and looking for neighbors that differ by one letter.
    queue<StringWithDistance> q;
    q.emplace(StringWithDistance({s, 0}));
    d.erase(s);
    while ( !q.empty()) // BFS
    {
        auto n = q.back();
        auto s2 = n.s;
        if ( s2 == t ) // Found destination vertex at this distance, and this is the shortest path since the graph is undirected.
            return n.dist;
        for ( int i = 0; i < static_cast<int>(n.s.size()); i++) // Find all possible adjacent vertices to connect to this vertex.
        {
            for ( int j = 0; j < 26; j++ )
            {
                s2[i] = 'a' + j;
                auto it = d.find(s2); // Is it a dictionary word?
                if ( it != d.end())
                {
                    d.erase(it); // Yes, remove it so we don't visit again.
                    q.emplace(StringWithDistance{s2, n.dist + 1}); // Add to graph. Note how we need the structure name for the {} initialization.
                }
            }
            s2[i] = n.s[i]; // Restore the previous character.
        }
        q.pop();
    }
    return -1;
}

void TestTransformOneStringToAnother()
{
	unordered_set<string> d = {"bat", "cot", "dog", "dag", "dot", "cat"};
	auto r = TransformOneStringToAnother(d, "cat", "dog");
	assert(r == 3);
}

// ----------------------------------------------------------
// 19.8 TEAM PHOTO DAY 2**
struct TeamPhoto
{
    int maxDist = 1; // Note how we can assign directly to members for initialization.
    bool visited = false;
};

void DFS(GraphVertex<TeamPhoto>* v, stack<GraphVertex<TeamPhoto>*>& ordering)
{
    v->value.visited = true;
    for ( auto e : v->edges )
        if ( !e->value.visited )
            DFS(e, ordering);
    ordering.emplace(v);
}

stack<GraphVertex<TeamPhoto>*> BuildTopologicalOrder(GraphVertex<TeamPhoto>* g)
{
    stack<GraphVertex<TeamPhoto>*> ordering;
    for ( auto v : g ->edges)
    {
        if ( !v->value.visited )
            DFS(g, ordering);
    }
    return ordering;
}

int FindLargestNumberTeams(GraphVertex<TeamPhoto>* g)
{
    // Every sequence of teams where a team can be placed behind another team corresponds to a path in G. Perform a topological sort. 
    // The longest path terminating at vertex v is the maximum of the longest paths terminating at v's fan-in concatenated with v itself.
    auto ordering = BuildTopologicalOrder(g);
    int maxDist = 0;
    while ( !ordering.empty())
    {
        auto u = ordering.top();
        maxDist = max(maxDist, u->value.maxDist);
        for ( auto v : u->edges )
            v->value.maxDist = max(v->value.maxDist, u->value.maxDist + 1);
        ordering.pop();
    }
    return maxDist;
}

// ----------------------------------------------------------
// 19.9 COMPUTE A SHORTEST PATH WITH FEWEST EDGES*
// Dijkstra's implementation.

void TestGraphs()
{
	TestTransformOneStringToAnother();
}