/*
HAS PATH PROBLEM STATEMENT:

	You have a directed, acyclic graph. 
	Given two nodes: src and dest, return true if there exists a path bw the two,
	and false otherwise.
*/
#include <iostream>
#include <stack>
#include <vector>
#include "graph.h"

using namespace std;

bool hasPath1(Graph g, char src, char dest)
{
	// using depth first traversal
	/*
	* Approach: Start dfs from the src node
	*			if dest node is encountered
	*			return true
	*			else return false
	*/

	stack<char> s;
	s.push(src);

	while (!s.empty())
	{
		char c = s.top();
		s.pop();

		if (c == dest) return true;
		vector<char> v = g.get_neighbours(c);
		for (char ch : v) s.push(ch);
	}

	return false;

}

int main()
{
	Graph g;

	g.add_node('f');
	g.add_node('g');
	g.add_node('h');
	g.add_node('i');
	g.add_node('j');
	g.add_node('k');

	g.add_edge('f', 'g');
	g.add_edge('f', 'i');
	g.add_edge('i', 'g');
	g.add_edge('j', 'i');
	g.add_edge('i', 'k');
	g.add_edge('g', 'h');

	if (hasPath1(g, 'h', 'i')) cout << "yes";
	else cout << "no";

	if (hasPath1(g, 'i', 'h')) cout << "yes";
	else cout << "no";

	return 0;

}