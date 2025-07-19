#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

struct Pos
{
	int y, x, c;
	bool isBreakWall;
};

int dY[4]{ 1, 0, -1, 0 };
int dX[4]{ 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	enum e
	{
		Empty,
		Wall,
		Visited
	};

	int N, M;
	cin >> N >> M;

	// 1) 벽이 안뚫린 경우의 visited
	vector<vector<int>> grid1(N, vector<int>(M));

	// 2) 벽이 뚫린 경우의 visited
	vector<vector<int>> grid2(N, vector<int>(M));

	for (int y = 0; y < N; ++y)
	for (int x = 0; x < M; ++x)
	{
		char in;
		cin >> in;
		grid1[y][x] = in - '0';
		grid2[y][x] = in - '0';
	}


	// N, M이 1일 경우 예외 처리
	Pos start{ 0, 0, 1, false };
	
	if (start.y == N - 1 && start.x == M - 1)
	{
		cout << start.c;
		return 0;
	}

	queue<Pos> q;
	q.push(start);
	grid1[0][0] = e::Visited;

	while (!q.empty())
	{
		Pos cur = q.front();
		q.pop();

		cur.c++;

		for (int i = 0; i < 4; ++i)
		{
			Pos next = cur;
			next.y += dY[i];
			next.x += dX[i];

			// 종료조건?
			if (next.y == N - 1 && next.x == M - 1)
			{
				cout << next.c;
				return 0;
			}
			
			// 인덱스 범위에 맞지 않으면 continue
			if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M)
				continue;

			// 벽을 안 깬 노드인가?
			if (!next.isBreakWall)
			{
				// 다음으로 움직일 공간이 비어있다면 움직이기
				if (grid1[next.y][next.x] == e::Empty)
				{
					grid1[next.y][next.x] = e::Visited;
					q.push(next);
				}
				// 다음으로 움직일 공간이 벽이라면
				else if (grid1[next.y][next.x] == e::Wall)
				{
					// 가려는 벽이 이미 방문한 곳인지 체크
					if (grid2[next.y][next.x] == e::Wall)
					{
						next.isBreakWall = true;
						grid2[next.y][next.x] = e::Visited;
						q.push(next);
					}
				}
			}
			// 벽을 깬 노드인가?
			else
			{
				// 다음으로 움직일 공간이 비어있다면 움직이기
				if (grid2[next.y][next.x] == e::Empty)
				{
					grid2[next.y][next.x] = e::Visited;
					q.push(next);
				}
			}
		}
	}

	// 불가능
	cout << -1;

	return 0;
}
 