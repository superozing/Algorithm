#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int dY[4]{ 1, 0, -1, 0 };
int dX[4]{ 0, 1, 0, -1 };

void BFS(vector<vector<bool>>& grid, pair<int, int> p)
{
	queue<pair<int, int>> q;
	q.push(p);
	grid[p.first][p.second] = false;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			auto next = cur;
			next.first += dY[i];
			next.second += dX[i];

			if (next.first >= 0 && next.first < grid.size() && 
				next.second >= 0 && next.second < grid[0].size() &&
				grid[next.first][next.second])
			{
				grid[next.first][next.second] = false;
				q.push(next);
			}
		}
	}
}

int EarthwormCount(vector<vector<bool>>& grid)
{
	int worm = 0;

	for (int y = 0; y < grid.size(); ++y)
	for (int x = 0; x < grid[0].size(); ++x)
	{
		if (grid[y][x])
		{
			BFS(grid, { y, x });
			++worm;
		}
	}

	return worm;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int M, N, K;
		cin >> M >> N >> K;

		vector<vector<bool>> grid(N, vector<bool>(M));

		int x, y;
		while (K--)
		{
			cin >> x >> y;
			grid[y][x] = true;
		}

		cout << EarthwormCount(grid) << endl;
	}

	return 0;
}
 