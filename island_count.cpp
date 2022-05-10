/*
* ISLAND COUNT
* Given a 2D array where each cell represents either LAND ('L'), or WATER ('W');
* You have to find the number of islands all the LAND cells form together.
*/
/*
* APPROACH
* Iterate over the 2D array, for each cell that is 'L' begin a traversal to its neighbours, their neighbours and so on.
* Mark each 'L' cell in the traversal as visited, skip them if found again.
* For each such traversal, increase the island count by 1.
* Return the island count.
*/
#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

void dfs(vector<vector<char>>& v, set<pair<int, int>>& visited, pair<int, int> p)
{
	stack<pair<int, int>> s;
	s.push(p);

	while (!s.empty())
	{
		pair<int, int> cell = s.top();
		s.pop();
		if (cell.first < 0 || cell.second < 0 || cell.first >= v.size() || cell.second >= v.size()) continue;
		if (visited.find(cell) != visited.end()) continue;
		visited.insert(cell);
		if (cell.first > 0) if (v[cell.first - 1][cell.second] == 'L') s.push({ cell.first - 1, cell.second });
		if (cell.second > 0) if (v[cell.first][cell.second - 1] == 'L') s.push({ cell.first, cell.second - 1});
		if (cell.second < v.size() - 1) if (v[cell.first][cell.second + 1] == 'L') s.push({ cell.first, cell.second + 1});
		if (cell.first < v.size() - 1) if (v[cell.first + 1][cell.second] == 'L') s.push({ cell.first + 1, cell.second });
	}
}

int island_count(vector<vector<char>>& v)
{
	int len = v.size(), cnt = 0;
	set<pair<int, int>> visited;

	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
			if (v[i][j] == 'L' && visited.find({ i, j }) == visited.end())
			{
				dfs(v, visited, { i, j });
				cnt++;
			}

	return cnt;
}

int main()
{
	vector<vector<char>> v = {
		{ 'W', 'L', 'W', 'W', 'L', 'W' },
		{ 'L', 'L', 'W', 'W', 'L', 'W' },
		{ 'W', 'L', 'L', 'W', 'L', 'W' },
		{ 'W', 'W', 'L', 'L', 'L', 'W' },
		{ 'W', 'L', 'L', 'L', 'L', 'W' },
		{ 'W', 'W', 'W', 'W', 'W', 'W' }
	};

	cout << island_count(v) << endl;
}