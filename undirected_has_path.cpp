// Has Path problem for undirected and/or cyclic graphs.
#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

bool hasPath(Graph g, char src, char dest, vector<bool>& visited)
{
	if (src == dest) return true;

	if (visited[src - 'a']) return false;
	visited[src - 'a'] = true;

	for (char c : g.get_neighbours(src))
	{
		if(hasPath(g, c, dest, visited)) 
			return true;
	}

	return false;
}

int main(int argc, char* argv[])
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

	vector<bool> v(26, false);

	if (hasPath(g, argv[1][0], argv[2][0], v)) cout << "yes" << endl;
	else cout << "no" << endl;

	return 0;
}