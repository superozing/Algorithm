#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <string>
#include <set>

#define endl '\n'

using namespace std;

// visited가 0이면 비어있는 공간 => 데이터를 넣을 수 있는 공간
vector<vector<int>> grid;
int answer = 0;
int N;

void QueenSet(int y, int x)
{
	// 가로 세로
	for (int i = 0; i < N; ++i)
	{
		grid[y][i] += 1;
		grid[i][x] += 1;
	}

	// 대각선
	for (int i = 0, cy = y, cx = x; cy - i >= 0 && cy - i < N && cx - i >= 0 && cx - i < N; ++i)
		grid[cy - i][cx - i] += 1;
	for (int i = 0, cy = y, cx = x; cy + i >= 0 && cy + i < N && cx + i >= 0 && cx + i < N; ++i)
		grid[cy + i][cx + i] += 1;
	for (int i = 0, cy = y, cx = x; cy - i >= 0 && cy - i < N && cx + i >= 0 && cx + i < N; ++i)
		grid[cy - i][cx + i] += 1;
	for (int i = 0, cy = y, cx = x; cy + i >= 0 && cy + i < N && cx - i >= 0 && cx - i < N; ++i)
		grid[cy + i][cx - i] += 1;
}

void QueenReset(int y, int x)
{
	// 가로 세로
	for (int i = 0; i < N; ++i)
	{
		grid[y][i] -= 1;
		grid[i][x] -= 1;
	}

	// 대각선
	for (int i = 0, cy = y, cx = x; cy - i >= 0 && cy - i < N && cx - i >= 0 && cx - i < N; ++i)
		grid[cy - i][cx - i] -= 1;
	for (int i = 0, cy = y, cx = x; cy + i >= 0 && cy + i < N && cx + i >= 0 && cx + i < N; ++i)
		grid[cy + i][cx + i] -= 1;
	for (int i = 0, cy = y, cx = x; cy - i >= 0 && cy - i < N && cx + i >= 0 && cx + i < N; ++i)
		grid[cy - i][cx + i] -= 1;
	for (int i = 0, cy = y, cx = x; cy + i >= 0 && cy + i < N && cx - i >= 0 && cx - i < N; ++i)
		grid[cy + i][cx - i] -= 1;
}

void DFS(int y)
{
	if (N == y)
	{
		++answer;
		return;
	}

	for (int x = 0; x < N; ++x)
	{
		if (!grid[y][x])
		{
			QueenSet(y, x);
			DFS(y + 1);
			QueenReset(y, x);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	grid.resize(N, vector<int>(N));
	
	DFS(0);

	cout << answer;
	
	return 0;
}
 