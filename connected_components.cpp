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
#include "graph.h"

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
	
	g.add_edge('1', '2');
	g.add_edge('2', '1');
	g.add_edge('6', '4');
	g.add_edge('2', '1');
}