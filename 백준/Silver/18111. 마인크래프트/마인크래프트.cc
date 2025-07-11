#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

int GetTime(vector<int>& grid, int B, int height)
{
	int time = 0;

	for (int cur : grid)
	{
		//2초) 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
		if (cur > height)
		{
			time += (cur - height) * 2;

			// 블록을 인벤토리에 넣기
			B += cur - height;
		}
		//1초) 인벤토리에서 블록 하나를 꺼내어 좌표(i, j)의 가장 위에 있는 블록 위에 놓는다.
		else if (cur < height)
		{
			time += height - cur;

			// 블록을 놓기
			B -= height - cur;
		}
	}

	// 실패 시 -1
	return B < 0 ? -1 : time;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, B; // 세로, 가로, 블록의 수
	cin >> N >> M >> B;

	vector<int> grid(N * M);

	int l = 256, r = 0;
	for (int& i : grid)
	{
		cin >> i;
		l = min(l, i);
		r = max(r, i);
	}

	int ansTime = 1e9, ansHeight = 0;

	for (; l <= r; ++l)
	{
		int height = l;
		int curTime = GetTime(grid, B, height);

		if (curTime == -1)
			break;

		if (ansTime >= curTime)
		{
			ansHeight = height;
			ansTime = curTime;
		}
		// cout << "l: " << l << ", r: " << r << ", h: " << height << endl;
		// cout << "curTime: " << curTime << endl;
		// cout << "ansTime: " << ansTime << ", ansHeight: " << ansHeight << endl << endl;
	}

	cout << ansTime << ' ' << ansHeight;

	return 0;
}
