/*
HAS PATH PROBLEM STATEMENT:

	You have a directed, acyclic graph. 
	Given two nodes: src and dest, return true if there exists a path bw the two,
	and false otherwise.
*/

/*
	* Approach: Start dfs or bfs from the src node
	*			if dest node is encountered
	*			return true
	*			else return false
*/

/*
COMPLEXITIES:
e = no of edges, n = no of nodes

	Time: O(e) [Because we might have to look through all the edges to check]
	Space: O(n) [Because we might have to store in all the nodes in the stack/queue before starting popping]

	Time: O(n^2)
	Space: O(n)
	Because in the worst case scenario, no of edges = square of no of nodes
*/

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include "graph.h"

using namespace std;

bool hasPath1(Graph g, char src, char dest)
{
	// using depth first traversal

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

bool hasPath2(Graph g, char src, char dest)
{
	// using breadth first traversal

	queue<char> q;
	q.push(src);

	while (!q.empty())
	{
		char c = q.front();
		if (c == dest) return true;
		q.pop();
		vector<char> v = g.get_neighbours(c);
		for (char ch : v) q.push(ch);
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

	if (hasPath2(g, 'h', 'i')) cout << "yes";
	else cout << "no";

	if (hasPath1(g, 'i', 'h')) cout << "yes";
	else cout << "no";

	if (hasPath2(g, 'i', 'h')) cout << "yes";
	else cout << "no";

	return 0;

}