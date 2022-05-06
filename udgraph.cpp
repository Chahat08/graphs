/*
	TRAVERSALS ON AN UNDIRECTED GRAPH
	Basically, an undirected graph is nothing but a directed graph, with edges going both ways bw two nodes.

	In an undirected graph, or basically any graph with cycles, it is important to keep 
	track of visited nodes while traversing.
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include "graph.h"

using namespace std;

void dfs(Graph g, char node, vector<bool>& visited)
{
	if (visited[node - 'a']) return;

	cout << node << " ";
	visited[node - 'a'] = true;

	vector<char> v = g.get_neighbours(node);
	for (char c : v) dfs(g, c, visited);
}

void bfs(Graph g, char node, unordered_set<char>& visited)
{
	queue<char> q;
	q.push(node);
	while (!q.empty())
	{
		char n = q.front();
		q.pop();
		if (visited.find(n) != visited.end()) continue;
		visited.insert(n);
		cout << n << " ";
		for (char c : g.get_neighbours(n)) q.push(c);
	}
}

int main()
{
	Graph g;

	g.add_node('i');
	g.add_node('j');
	g.add_node('k');
	g.add_node('m');
	g.add_node('l');
	g.add_node('n');
	g.add_node('o');

	g.add_edge('i', 'j');
	g.add_edge('j', 'i');
	g.add_edge('k', 'i');
	g.add_edge('i', 'k');
	g.add_edge('j', 'k');
	g.add_edge('k', 'j');
	g.add_edge('m', 'k');
	g.add_edge('k', 'm');
	g.add_edge('k', 'l');
	g.add_edge('l', 'k');
	g.add_edge('o', 'n');
	g.add_edge('n', 'o');

	// use some data structure where it takes const time to check for visited nodes
	/*
		Using vector<bool> here because the node names are just a char and there's only 26 chars in the dict.
		So very small extra space is required.
		unordered_map<char, bool> is ok to use too.
		Or unordered_set<char>
	*/

	vector<bool> visited(26, false);
	dfs(g, 'o', visited);

	cout << endl;

	// using an unordered_set for bfs just to mix things up a bit
	unordered_set<char> vis;
	bfs(g, 'o', vis);

	return 0;
}