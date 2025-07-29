#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <deque>

#define endl '\n'

using namespace std;

int dY[4]{ 0, 1, 0, -1 };
int dX[4]{ 1, 0, -1, 0 };

struct Pos
{
	int y, x;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> grid(N, vector<int>(N));

	// 0: 빈
	// 1: 사과
	// 2: 뱀
	for (int i = 0; i < K; ++i)
	{
		int y, x;
		cin >> y >> x;
		grid[y - 1][x - 1] = 1;
	}

	// front: 머리
	// back: 꼬리
	
	// dy dx를 순서대로 작성했다.
	// ++ 시 우회전, -- 시 좌회전
	int curDir = 0;
	int curSec = 0;
	int answer = 0;
	bool isCollision = false;

	deque<Pos> dq;
	dq.push_front({ 0, 0 });
	grid[0][0] = 2;
	
	int L;
	cin >> L;
	while (L--)
	{
		int wait;
		char dir;
		cin >> wait >> dir;

		// 현재 초가 wait초가 될 때 까지 반복
		for (; curSec < wait; ++curSec)
		{
			Pos cur = dq.front();
			// 방향에 맞게 다음 칸으로 이동하기
			cur.y += dY[curDir];
			cur.x += dX[curDir];

			// 초 증가
			++answer;

			// 벽에 부딪히거나 자신 몸뚱아리에 부딪힌 경우 break
			if (cur.y < 0 || cur.x < 0 || cur.y >= N || cur.x >= N || grid[cur.y][cur.x] == 2)
			{
				isCollision = true;
				break;
			}

			// 사과가 없을 경우 pop_back();
			if (grid[cur.y][cur.x] == 0)
			{
				Pos popPos = dq.back();
				dq.pop_back();
				
				grid[popPos.y][popPos.x] = 0;
			}
		
			// 머리 늘리기
			grid[cur.y][cur.x] = 2;
			dq.push_front(cur);
		}

		if (isCollision)
			break;

		// wait초가 지난 후 방향 전환
		if (dir == 'D')
			curDir = curDir == 3 ? 0 : curDir + 1; // 우회전
		else
			curDir = curDir == 0 ? 3 : curDir - 1; // 좌회전
	}

	// 회전 후에도 충돌하지 않았는가?
	while (!isCollision)
	{
		// 방향에 맞게 다음 칸으로 이동하기
		Pos cur = dq.front();
		cur.y += dY[curDir];
		cur.x += dX[curDir];

		// 초 증가
		++answer;

		// 벽에 부딪히거나 자신 몸뚱아리에 부딪힌 경우 break
		if (cur.y < 0 || cur.x < 0 || cur.y >= N || cur.x >= N || grid[cur.y][cur.x] == 2)
			break;

		// 사과가 없을 경우 pop_back();
		if (grid[cur.y][cur.x] == 0)
		{
			Pos popPos = dq.back();
			dq.pop_back();

			grid[popPos.y][popPos.x] = 0;
		}

		// 머리 늘리기
		grid[cur.y][cur.x] = 2;
		dq.push_front(cur);
	}

	cout << answer;

	return 0;
}
