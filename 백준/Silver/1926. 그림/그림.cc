#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

struct Pos
{
	int y, x;
};

int dY[4]{ 0, 1, 0, -1 };
int dX[4]{ -1, 0, 1, 0};

vector<vector<int>> grid;

int Bfs(Pos start)
{
	int pictureSize = 1;

	queue<Pos> q;
	q.push(start);
	grid[start.y][start.x] = 0;

	while (!q.empty())
	{
		Pos cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			Pos next = cur;
			next.y += dY[i];
			next.x += dX[i];

			if (next.y >= grid.size() || next.y < 0 ||
				next.x >= grid[0].size() || next.x < 0 ||
				grid[next.y][next.x] == 0)
				continue;

			++pictureSize;
			q.push(next);
			grid[next.y][next.x] = 0;
		}
	}

	return pictureSize;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	grid.resize(N, vector<int>(M));

	for (auto& v : grid)
	for (auto& i : v)
		cin >> i;
	
	int pictureCount = 0;
	int maxSize = 0;
	for (int y = 0; y < N; ++y)
	for (int x = 0; x < M; ++x)
	{
		if (grid[y][x] == 1)
		{
			++pictureCount;
			maxSize = max(maxSize, Bfs({ y, x }));
		}
	}

	cout << pictureCount << endl << maxSize;

	return 0;
}
