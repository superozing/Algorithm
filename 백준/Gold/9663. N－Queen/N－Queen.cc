#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

vector<vector<int>> grid;
int answer = 0;
int N;

void QueenSet(int y, int x)
{
	// 세로
	for (int i = 0; i < N; ++i)
		grid[i][x] += 1;

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
	// 세로
	for (int i = 0; i < N; ++i)
		grid[i][x] -= 1;

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
 