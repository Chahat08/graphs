/*
SHORTEST DISTANCE
Given two nodes, find the shortest distance between them.
*/
/*
Approach used:
While traversingm (bfs),
keep track of distance of each node from the source node,
On finding the destination, return the distance,
because this distance which is found first will be the smallest one.

NOTE:
BFS is preferred here over DFS because DFS might keep
going unnecessarily in the same direction, 
without hitting the destination node for a long time.
BFS is more evenly distributed in all directions from the source.
*/
#include <iostream>
#include <queue>
#include <vector>
#include "graph.h"

using namespace std;

int shortest_distance(Graph g, char src, char dest)
{
	queue<pair<char, int>> q;
	q.push({ src, 0 });

	while (!q.empty())
	{
		pair<char, int> p = q.front();
		q.pop();
		if (p.first == dest) return p.second;
		for (char c : g.get_neighbours(p.first)) q.push({ c, p.second + 1 });
	}

	// it is not possible to reach dest from src
	return -1;
}

int main()
{
	// using g7

	Graph g;

	vector<vector<char>> edges = {
		{'w', 'x'},
		{'x', 'y'},
		{'z', 'y'},
		{'z', 'v'},
		{'w', 'v'}
	};

	g.create_ud_from_edge_list(edges);

	cout << shortest_distance(g, 'w', 'z') << endl;

	return 0;
}