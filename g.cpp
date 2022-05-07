// implementation of functions defined by the graph interface

#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include "graph.h"

void Graph::create_from_edge_list(std::vector<std::vector<char>>& edges)
{
	// create a graph from directed edges in the list

	for (auto& v : edges)
		adjacency_list[v[0]].push_back(v[1]);
}

void Graph::create_ud_from_edge_list(std::vector<std::vector<char>>& edges)
{
	// create a graph from undirected edges in the list

	for (auto& v : edges)
	{
		adjacency_list[v[0]].push_back(v[1]);
		adjacency_list[v[1]].push_back(v[0]);
	}
}

void Graph::add_node(char node)
{
	adjacency_list[node] = {};
}

void Graph::add_edge(char node1, char node2)
{
	adjacency_list[node1].push_back(node2);
}

void Graph::add_undirected_edge(char node1, char node2)
{
	// add an edge from n1 to n2 and vice versa;
	adjacency_list[node1].push_back(node2);
	adjacency_list[node2].push_back(node1);
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

std::vector<char> Graph::get_nodes()
{
	// returns a vector<char> containing all nodes in the graph.
	std::vector<char> v;
	for (auto& x : adjacency_list) v.push_back(x.first);
	return v;
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

bool Graph::hasPath(char src, char dest)
{
	// has path using depth first traversal
	std::stack<char> s;
	s.push(src);

	while (!s.empty())
	{
		char c = s.top();
		if (c == dest) return true;
		s.pop();
		for (char ch : adjacency_list[c]) s.push(ch);
	}
	return false;
}

