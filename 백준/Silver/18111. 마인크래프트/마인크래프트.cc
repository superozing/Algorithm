#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

int GetTime(vector<vector<int>>& grid, int N, int M, int B, int height)
{
	//2초) 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
	//1초) 인벤토리에서 블록 하나를 꺼내어 좌표(i, j)의 가장 위에 있는 블록 위에 놓는다.

	// 어떻게 구할 것인가?
	// 일단 해당 높이로 "무조건" 맞추어야 하기 떄문에,
	// 해당 높이보다 높은 블럭은 무조건 깎고,
	// 낮은 블럭은 무조건 채워야 한다.

	int time = 0;

	// 블록 깎아내기
	for (int y = 0; y < N; ++y)
	for (int x = 0; x < M; ++x)
	{
		if (grid[y][x] <= height)
			continue;

		// 시간 증가
		time += (grid[y][x] - height) * 2;

		// 블록을 인벤토리에 넣기
		B += grid[y][x] - height;
		
		// 블록을 정상 크기로 맞추기
		grid[y][x] = height;
	}

	// 블록 추가하기
	for (int y = 0; y < N; ++y)
	for (int x = 0; x < M; ++x)
	{
		if (grid[y][x] == height)
			continue;

		// 시간 증가
		time += height - grid[y][x];

		// 블록을 놓기
		B -= height - grid[y][x];

		// 블록이 모자란가요?
		if (B < 0)
			return -1;
		
		// 블록을 정상 크기로 맞추기
		grid[y][x] = height;
	}

	return time;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, B; // 세로, 가로, 블록의 수
	cin >> N >> M >> B;

	vector<vector<int>> grid(N, vector<int>(M));


	int l = 256, r = 0;
	for (auto& vec : grid)
	for (int& i : vec)
	{
		cin >> i;
		l = min(l, i);
		r = max(r, i);
	}

	int ansTime = 1e9, ansHeight = 0;

	for (; l <= r; ++l)
	{
		int height = l;
		vector<vector<int>> copyGrid(grid);
		int curTime = GetTime(copyGrid, N, M, B, height);

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
