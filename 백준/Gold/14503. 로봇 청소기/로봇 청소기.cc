#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int dY[4]{ -1, 0, 1, 0 };
int dX[4]{ 0, 1, 0, -1 };

struct Pos
{
	int y, x, d;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 0 위
	// 1 오
	// 2 아
	// 3 왼

	int answer = 0;

	int N, M;
	cin >> N >> M;
	vector<vector<int>> grid(N, vector<int>(M));

	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < M; ++j)
		cin >> grid[i][j];

	queue<Pos> q;
	q.push({ r, c, d });

	while (!q.empty())
	{
		Pos cur = q.front();
		q.pop();

		//현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
		if (grid[cur.y][cur.x] == 0)
		{
			++answer;
			grid[cur.y][cur.x] = 2;
		}

		bool isClean = true;

		// 주변 네 칸 중 청소되지 않은 빈 칸이 있는지 체크
		for (int i = 0; i < 4; ++i)
		{
			Pos next = cur;
			next.y += dY[i];
			next.x += dX[i];

			// 주변 칸이 청소되지 않았는가?
			if (next.y < N && next.x < M && next.y >= 0 && next.x >= 0 && grid[next.y][next.x] == 0)
			{
				isClean = false;
				break;
			}
		}

		//현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
		if (!isClean)
		{
			//	반시계 방향으로 90도 회전한다.
			cur.d = (cur.d == 0 ? 3 : cur.d - 1);

			//	바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
			Pos next = cur;
			next.y += dY[next.d];
			next.x += dX[next.d];

			if (next.y < N && next.x < M && next.y >= 0 && next.x >= 0 && grid[next.y][next.x] == 0)
				q.push(next);
			else
				q.push(cur);

			//	1번으로 돌아간다.
			continue;
		}

		//현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
		//	바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
		Pos next = cur;
		next.d = (next.d < 2 ? next.d + 2 : next.d - 2);
		next.y += dY[next.d];
		next.x += dX[next.d];

		if (next.y < N && next.x < M && next.y >= 0 && next.x >= 0 && grid[next.y][next.x] != 1)
		{
			next.d = cur.d;
			q.push(next);
			continue;
		}

		//	바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
		break;
	}

	cout << answer;

	return 0;
}
