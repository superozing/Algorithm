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

int dY[4]{ 1, 0, -1, 0 };
int dX[4]{ 0, 1, 0, -1 };

int N, L, R;

bool Bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, Pos start)
{
	int population = grid[start.y][start.x];

	vector<Pos> vPos;
	queue<Pos> q;
	q.push(start);
	vPos.push_back(start);
	visited[start.y][start.x] = true;

	//cout << "start: " << start.y << " " << start.x << endl;

	while (!q.empty())
	{
		Pos cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			Pos next = cur;
			next.y += dY[i];
			next.x += dX[i];

			if (next.y < N && next.x < N && next.y >= 0 && next.x >= 0 && !visited[next.y][next.x])
			{
				int diff = abs(grid[cur.y][cur.x] - grid[next.y][next.x]);
				if (diff < L || diff > R)
					continue;

				//cout << next.y << " " << next.x << endl;

				visited[next.y][next.x] = true;
				population += grid[next.y][next.x];
				vPos.push_back(next);
				q.push(next);
			}
		}
	}

	//cout << vPos.size() << endl;

	if (vPos.size() == 1)
		return false;

	population /= vPos.size();
	for (Pos& cur : vPos)
		grid[cur.y][cur.x] = population;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
	// 
	//위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
	// 
	//국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
	// 
	//연합을 이루고 있는 각 칸의 인구수는(연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다.편의상 소수점은 버린다.
	// 
	//연합을 해체하고, 모든 국경선을 닫는다.

	cin >> N >> L >> R;

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	// 굳이 국경선 여는 행위를 차례를 나누지 않고
	// 탐색하며 그때그때 조건 검사를 하면 될 것 같아요.

	vector<vector<int>> grid(N, vector<int>(N));
	for (vector<int>& v : grid)
	for (int& i : v)
		cin >> i;
	
	vector<vector<bool>> visited(N, vector<bool>(N));

	int answer = 0;
	bool isMoved = true;
	while (isMoved)
	{
		isMoved = false;

		for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			visited[y][x] = false;

		// 1. visited false -> 국경 탐색
		//	이 때 한 번이라도 다음 나라와 연결했을 경우 isMoved = true; 해주면 되겠다
		for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
		{
			if (!visited[y][x])
			{
				if (Bfs(grid, visited, { y, x }))
					isMoved = true;
			}
		}

		if (isMoved)
			++answer;
	}

	cout << answer;

	return 0;
}
