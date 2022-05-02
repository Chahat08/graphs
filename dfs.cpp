// depth first traversal of a graph

/*
* 
* Explore neighbours in one direction for as long as we can, before switching directions.
* 
* IMPLEMENTATION: stacks are used
* Stacks: LIFO, insertion and deletion at the same side.
* 
*/

#pragma once
#include <iostream>
#include <stack>
#include "graph.h"

using namespace std;

void dfs(Graph g, char start_node)
{
	stack<char> s;
	s.push(start_node);

	while (!s.empty())
	{
		char c = s.top();
		s.pop();
		cout << c << " ";
		for (char ch : g.get_neighbours(c)) s.push(ch);
	}
	cout << endl;
}

int main()
{
	Graph g;

	g.add_node('a');
	g.add_node('c');
	g.add_node('b');
	g.add_node('e');
	g.add_node('d');
	g.add_node('f');

	g.add_edge('a', 'c');
	g.add_edge('a', 'b');
	g.add_edge('c', 'e');
	g.add_edge('b', 'd');
	g.add_edge('d', 'f');

	dfs(g, 'a');
	g.depth_first_traversal('a');

	//g.print_graph();
}