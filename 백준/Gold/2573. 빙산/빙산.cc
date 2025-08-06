#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

struct Ice
{
	int height, speed;
};

int dY[4]{ 0, 1, 0, -1 };
int dX[4]{ -1, 0, 1, 0 };

int N, M;

vector<vector<Ice>> grid;
vector<vector<bool>> visited;

bool Melting()
{
	vector<pair<int, int>> melted;

	// 빙산 녹이기
	for (int y = 0; y < N; ++y)
	for (int x = 0; x < M; ++x)
	{
		Ice& ice = grid[y][x];
		if (ice.height == 0)
			continue;
		
		ice.height -= ice.speed;

		if (ice.height <= 0)
		{
			melted.push_back({ y, x });
			ice.height = 0;
		}
	}

	// 녹은 빙산의 주변 빙산 녹는 속도 ++
	for (auto& cur : melted)
	for (int i = 0; i < 4; ++i)
	{
		int y = cur.first;
		int x = cur.second;

		if (y + dY[i] < 0 || y + dY[i] >= N || x + dX[i] < 0 || x + dX[i] >= M)
			continue;

		if (grid[y + dY[i]][x + dX[i]].height > 0)
			grid[y + dY[i]][x + dX[i]].speed++;
	}
	
	return melted.size();
}

void Bfs(int y, int x)
{
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push({ y, x });

	while (!q.empty())
	{
		auto& cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			if (cur.first + dY[i] < 0 || cur.first + dY[i] >= N || cur.second + dX[i] < 0 || cur.second + dX[i] >= M
				|| visited[cur.first + dY[i]][cur.second + dX[i]] || grid[cur.first + dY[i]][cur.second + dX[i]].height == 0)
				continue;

			visited[cur.first + dY[i]][cur.second + dX[i]] = true;
			q.push({ cur.first + dY[i], cur.second + dX[i] });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 녹는 속도를 미리 기록하는 것이 좋아보여요.
	// 그리고 만약 녹아서 사라진 경우, 
	// 1. 주변 빙산의 사라지는 속도 ++ 해주어야 해요.
	// 2. 모든 빙산 높이 깎은 이후 bfs로 종료 조건 체크해야 할 것 같아요.

	cin >> N >> M;

	grid.resize(N, vector<Ice>(M));
	visited.resize(N, vector<bool>(M));

	int maxHeight = 0;
	for (auto& v : grid)
	for (auto& ice : v)
	{
		cin >> ice.height;
		maxHeight = max(maxHeight, ice.height);
	}

	for (int y = 0; y < N; ++y)
	for (int x = 0; x < M; ++x)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (y + dY[i] < 0 || y + dY[i] >= N || x + dX[i] < 0 || x + dX[i] >= M)
				continue;

			// 주변에 물 있으면 녹는 속도 ++
			if (grid[y + dY[i]][x + dX[i]].height == 0)
				++grid[y][x].speed;
		}
	}

	int answer = 0;
	while (true)
	{
		++answer;

		// 빙산이 녹지 않았다면 continue;
		if (!Melting())
			continue;
		
		// visited 초기화
		for (auto& v : visited)
			v.assign(v.size(), false);
		
		bool isAllMelted = true; // 전부 녹아서 더 검사할 필요 없는가?
		bool isFirstBfs = true;

		// BFS 2회 이상 실행 시 => 빙산이 두 개 이상으로 나뉘어짐
		for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
		{
			Ice& ice = grid[y][x];

			if (ice.height == 0 || visited[y][x])
				continue;

			if (!isFirstBfs)
			{
				cout << answer;
				return 0;
			}

			isAllMelted = false;
			isFirstBfs = false;
			Bfs(y, x);
		}

		if (isAllMelted)
			break;
	}

	cout << 0;

	return 0;
}
