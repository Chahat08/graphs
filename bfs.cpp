#pragma once
#include <iostream>
#include <queue>
#include "graph.h"

using namespace std;

void bfs(Graph g, char start_node)
{
	queue<char> q;
	q.push(start_node);

	while (!q.empty())
	{
		char c = q.front();
		vector<char> neighbours = g.get_neighbours(c);
		for (char ch : neighbours) q.push(ch);
		cout << c << ' ';
		q.pop();
	}
	cout << endl;
}

int main()
{
	// used g2

	Graph g;

	g.add_node('a');
	g.add_node('b');
	g.add_node('c');
	g.add_node('d');
	g.add_node('e');
	g.add_node('f');
	
	g.add_edge('a', 'c');
	g.add_edge('a', 'b');
	g.add_edge('b', 'd');
	g.add_edge('d', 'f');
	g.add_edge('c', 'e');

	bfs(g, 'a');

	return 0;
}