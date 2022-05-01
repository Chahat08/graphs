// implementation of functions defined by the graph interface

#pragma once
#include <iostream>
#include "graph.h"

void Graph::add_node(char node)
{
	adjacency_list[node] = {};
}

void Graph::add_edge(char node1, char node2)
{
	adjacency_list[node1].push_back(node2);
}

void Graph::print_graph()
{
	for (auto& x : adjacency_list)
	{
		std::cout << x.first << ": ";
		for (char c : x.second) std::cout << c << " ";
		std::cout << std::endl;
	}
}

void Graph::print_neighbours(char node)
{
	std::cout << node << ": ";
	for (char c : adjacency_list[node])
		std::cout << c << " ";
	std::cout << std::endl;
}
