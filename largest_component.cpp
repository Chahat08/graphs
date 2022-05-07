/*
LARGEST COMPONENET:
	Return the size (number of nodes) of the
	largest component in the graph.
*/
#include <iostream>
#include <unordered_set>
#include <stack>
#include "graph.h"

using namespace std;

int dfs(Graph g, char node, unordered_set<char>& visited)
{
	int cnt = 0;

	stack<char> s;
	s.push(node);

	while (!s.empty())
	{
		char c = s.top();
		s.pop();
		if (visited.find(c) != visited.end()) continue;
		visited.insert(c);
		cnt++;
		for (char n : g.get_neighbours(c)) s.push(n);
	}

	return cnt;
}

int largest_component(Graph g)
{
	unordered_set<char> visited;
	int maxcnt = 0;

	for (char c : g.get_nodes())
	{
		if (visited.find(c) != visited.end()) continue;
		int cnt = dfs(g, c, visited);
		maxcnt = (cnt > maxcnt ? cnt : maxcnt);
	}

	return maxcnt;
}

int main()
{
	//using g6
	Graph g;

	/*g.add_node('0');
	g.add_node('1');
	g.add_node('5');
	g.add_node('8');
	g.add_node('2');
	g.add_node('4');
	g.add_node('3');

	g.add_undirected_edge('0', '1');
	g.add_undirected_edge('0', '5');
	g.add_undirected_edge('0', '8');
	g.add_undirected_edge('5', '8');
	g.add_undirected_edge('2', '3');
	g.add_undirected_edge('3', '4');
	g.add_undirected_edge('2', '4');
	*/

	g.add_node('1');
	g.add_node('2');
	g.add_node('3');
	g.add_node('4');
	g.add_node('5');
	g.add_node('6');
	g.add_node('7');
	g.add_node('8');

	g.add_undirected_edge('1', '2');
	g.add_undirected_edge('6', '4');
	g.add_undirected_edge('6', '5');
	g.add_undirected_edge('6', '7');
	g.add_undirected_edge('6', '8');

	cout << largest_component(g) << endl;

	return 0;
}