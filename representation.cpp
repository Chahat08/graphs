// Graph Representation: Adjacency List

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph
{
private:
	unordered_map<char, vector<char>> adjacency_list;
public:
	void add_node(char node);
	void add_edge(char node1, char node2);
	void print_graph();
	void print_neighbours(char node);
};

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
		cout << x.first << ": ";
		for (char c : x.second) cout << c << " ";
		cout << endl;
	}
}

void Graph::print_neighbours(char node)
{
	cout << node << ": ";
	for (char c : adjacency_list[node])
		cout << c << " ";
	cout << endl;
}

int main()
{
	// used g1

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

	return 0;
}