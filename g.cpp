// implementation of functions defined by the graph interface

#pragma once
#include <iostream>
#include <stack>
#include <queue>
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

std::vector<char> Graph::get_neighbours(char node)
{
	return adjacency_list[node];
}

void Graph::depth_first_traversal(char start_node)
{
	std::cout << "DEPTH FIRST TRAVERSAL" << std::endl;
	std::stack<char> s;
	s.push(start_node);

	while (!s.empty())
	{
		char c = s.top();
		s.pop();
		std::cout << c << " ";
		for (char ch : adjacency_list[c]) s.push(ch);
	}
	std::cout << std::endl;
}

void Graph::breadth_first_traversal(char start_node)
{
	std::cout << "BREADTH FIRST TRAVERSAL" << std::endl;
	std::queue<char> q;
	q.push(start_node);

	while (!q.empty())
	{
		char c = q.front();
		for (char ch : adjacency_list[c]) q.push(ch);
		std::cout << c << " ";
		q.pop();
	}

	std::cout << std::endl;
}