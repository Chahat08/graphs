/*
 CONNECTED COMPONENTS:
 Disjoint sets of nodes of the graph.

 Or, Groups of nodes comprising of nodes which are connected to each other
 But the groups themselves are unconnected.
*/
/*
Count Connected Components:
	In this problem you have to count the number of connected components
	in a graph.
*/
/*
APPROACH:
	Iterate over a list of nodes in the graph.

		If the current node is marked unvisited, 
		start a traversal (bf or df) from it.
		On completion of traversal, inc. the no. of connected components.

		If the current node is visited, skip it;
		as it is a part of some connected comp. already counted.

	Move onto the next node.
*/
#include <iostream>
#include <queue>
#include <unordered_set>
#include "graph.h"

using namespace std;

void bfs(Graph g, char node, unordered_set<char>& visited)
{
	queue<char> q;
	q.push(node);

	while (!q.empty())
	{
		char c = q.front();
		q.pop();
		if (visited.find(c) != visited.end()) continue;
		visited.insert(c);
		for (char ch : g.get_neighbours(c)) q.push(ch);
	}
}

int count_connected_components(Graph g)
{
	int cnt = 0;
	unordered_set<char> vis;

	for (char c : g.get_nodes())
	{
		if (vis.find(c) != vis.end()) continue;
		bfs(g, c, vis); // couldve done dfs instead too
		cnt++;
	}

	return cnt;
}

int main()
{
	Graph g;

	g.add_node('1');
	g.add_node('2');
	g.add_node('3');
	g.add_node('4');
	g.add_node('5');
	g.add_node('6');
	g.add_node('7');
	g.add_node('8');
	
	g.add_undirected_edge('1', '2');
	g.add_undirected_edge('6', '4');
	g.add_undirected_edge('6', '5');
	g.add_undirected_edge('6', '7');
	g.add_undirected_edge('6', '8');

	cout << count_connected_components(g) << endl;

	return 0;
}