# Graphs
## _A master repository of problems based on Graphs_
___

## Sources

1. [X] https://www.youtube.com/watch?v=tWVWeAqZ0WU (basic problems with a focus on traversals)
2. [ ] https://www.youtube.com/watch?v=09_LlHjoEiY (more complex problems)

## Interface (graph.h)

The interface uses an adjacency list representation for the graph, which is implemented using a hashmap.
```cpp
std::unordered_map<char, std::vector<char>> adjacency_list;
```
The adjacency list maps each node to the nodes that are connected to it.

#### Functions defined by the interface
```cpp
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
```
 
**For details implementation details and the uses of each function, check out graph.cpp**

## Problems

Problems solved till now:

1. [Representation of Graph](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/representation.cpp)
2. [Depth First Traversal](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/dfs.cpp)
3. [Breadth First Traversal](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/bfs.cpp)
4. [Does any path exist between two nodes?](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/has_path.cpp)
5. [Undirected Graph Implementation](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/undirected_graph.cpp)
6. [Does path exist bw 2 nodes in an Undirected Graph?](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/undirected_has_path.cpp)
7. [Shortest Distance bw 2 nodes in a graph](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/shortest_distance.cpp)
8. [Find number of Connected Components in a graph](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/connected_components.cpp)
9. [Find the size of the largest Componenet of a graph](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/largest_component.cpp)
10. [GRID GRAPH: island count](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/island_count.cpp)
11. [GRID GRAPH: size of smallest island](https://github.com/Chahat08/graphs/blob/80e2f28ba93ef529850be1c1d5440342213b19d2/minimum_island.cpp)

