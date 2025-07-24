#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int dY[8]{ -1, 1, 2, 2, 1, -1, -2, -2 };
int dX[8]{ -2, -2, -1, 1, 2, 2, 1, -1 };

struct Pos
{
	int y, x, c;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int L, startY, startX, destY, destX;
		cin >> L >> startY >> startX >> destY >> destX;

		// 종료 조건
		if (startY == destY && startX == destX)
		{
			cout << 0 << endl;
			continue;
		}

		vector<vector<bool>> visited(L, vector<bool>(L));
		queue<Pos> q;
		
		q.push({ startY, startX, 0 });

		visited[startY][startX] = true;
		
		while (!q.empty())
		{
			Pos cur = q.front();
			q.pop();
			cur.c++;

			bool isSearchEnded = false;
			for (int i = 0; i < 8; ++i)
			{
				Pos next = cur;
				next.y += dY[i];
				next.x += dX[i];

				// 종료 조건
				if (next.y == destY && next.x == destX)
				{
					isSearchEnded = true;
					cout << next.c << endl;
					break;
				}

				// 인덱스, visited 체크
				if (next.y < 0 || next.y >= L || next.x < 0 || next.x >= L || visited[next.y][next.x])
					continue;

				q.push(next);
				visited[next.y][next.x] = true;
			}

			if (isSearchEnded)
				break;
		}
	}


	return 0;
}
