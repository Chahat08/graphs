/*
* MINIMUM ISLAND:
Among all the islands (see island count) in the grid, return the size of the smallest one.
*/
/*
* APPROACH
* Iterate over the grid, doing a dfs over unvisited 'L' cells.
* Return the min size of each size island.
* ( if an island of size 1 is found, do an early return of 1 because it is the smallest possible size).
*/
/*
r = num rows, c = num cols
Time: O(rc)
Space: O(rc)
*/
#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int dfs(vector<vector<char>>& v, set<pair<int, int>>& visited, pair<int, int> p)
{
	stack<pair<int, int>> s;
	s.push(p);

	int sz = 0;

	while (!s.empty())
	{
		pair<int, int> pr = s.top();
		s.pop();
		if (visited.find(pr) != visited.end()) continue;

		visited.insert(pr);
		sz++;
		
		if (pr.first != 0 && v[pr.first - 1][pr.second] == 'L') s.push({ pr.first - 1, pr.second });
		if (pr.second != 0 && v[pr.first][pr.second - 1] == 'L') s.push({ pr.first, pr.second - 1 });
		if (pr.first != v.size() - 1 && v[pr.first + 1][pr.second] == 'L') s.push({ pr.first + 1, pr.second });
		if (pr.second != v.size() - 1 && v[pr.first][pr.second + 1] == 'L') s.push({ pr.first, pr.second + 1 });
	}

	return sz;
}

int minimum_island(vector<vector<char>>& v)
{
	int min_size = INT_MAX;
	set<pair<int, int>> visited;

	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v.size(); ++j)
			if (v[i][j] == 'L' && visited.find({ i, j }) == visited.end())
			{
				int sz = dfs(v, visited, { i, j });
				if (sz == 1) return 1;
				if (sz < min_size) min_size = sz;
			}

	return min_size;
}

int main()
{
	vector<vector<char>> v = {
		{'W','L','W','W','L','W'},
		{'L','L','W','W','L','W'},
		{'W','L','W','W','W','W'},
		{'W','W','W','L','L','W'},
		{'W','W','W','L','L','W'},
		{'W','W','W','L','W','W'}
	};
	cout << minimum_island(v) << endl;

	return 0;
}