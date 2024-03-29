// the graph interface

#pragma once
#include <unordered_map>
#include <vector>

class Graph
{
private:
	std::unordered_map<char, std::vector<char>> adjacency_list;
public:
	void create_from_edge_list(std::vector<std::vector<char>>& edges);
	void create_ud_from_edge_list(std::vector<std::vector<char>>& edges);
	void add_node(char node);
	void add_edge(char node1, char node2);
	void add_undirected_edge(char node1, char node2);
	void print_graph();
	void print_neighbours(char node);
	std::vector<char> get_neighbours(char node);
	std::vector<char> get_nodes();
	void depth_first_traversal(char start_node);
	void breadth_first_traversal(char start_node);
	bool hasPath(char src, char dest);
};