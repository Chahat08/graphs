// depth first traversal of a graph

/*
* 
* Explore neighbours in one direction for as long as we can, before switching directions.
* 
* IMPLEMENTATION: stacks are used.
* 
*/

#pragma once
#include <iostream>
#include "graph.h"

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
	g.add_edge('b', 'd');
	g.add_edge('c', 'e');
	g.add_edge('e', 'b');
	g.add_edge('f', 'd');

	g.print_graph();
}