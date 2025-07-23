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

int N;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dY[4]{ 1, 0, -1, 0 };
int dX[4]{ 0, 1, 0, -1 };

void Bfs(int y, int x, int rain)
{
	queue<Pos> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty())
	{
		Pos cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			Pos next = cur;
			next.y += dY[i];
			next.x += dX[i];

			if (next.y < N && next.x < N && next.y >= 0 && next.x >= 0 && !visited[next.y][next.x] && grid[next.y][next.x] > rain)
			{
				visited[next.y][next.x] = true;
				q.push(next);
			}
		}
	}
}

int SafeZoneCount(int rain)
{
	int returnValue = 0;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			visited[y][x] = false;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (rain >= grid[y][x] || visited[y][x])
				continue;

			++returnValue;

			Bfs(y, x, rain);
		}
	}

	return returnValue;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 1. 빗물 높이 설정하기
	// 2. BFS로 안전한 지역 개수 고르기
	// 3. 최대 개수 기록하기

	cin >> N;
	grid.resize(N, vector<int>(N));
	visited.resize(N, vector<bool>(N));

	int maxHeight = 0;
	for (int y = 0; y < N; ++y)
	for (int x = 0; x < N; ++x)
	{
		cin >> grid[y][x];
		maxHeight = max(maxHeight, grid[y][x]);
	}

	int answer = 0;
	for (int i = 0; i < maxHeight; ++i)
		answer = max(answer, SafeZoneCount(i));

	cout << answer;

	return 0;
}
