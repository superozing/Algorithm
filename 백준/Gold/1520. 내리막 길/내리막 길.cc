#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

int M, N;
vector<vector<int>> grid;
vector<vector<int>> dp;

int dY[4]{ 0, 1, 0, -1 };
int dX[4]{ -1, 0, 1, 0 };

int Dfs(int cy, int cx)
{
	// 도착 지점에 도착한 경우
	if (cy == M - 1 && cx == N - 1)
		return 1;

	// 이미 방문한 적 있는 자리라면 return
	if (dp[cy][cx] != -1)
		return dp[cy][cx];

	// 현재 dp 초기화
	dp[cy][cx] = 0;

	// 현재 위치로부터 4방향으로 탐색 후, 결과를 가져와야 한다.
	for (int i = 0; i < 4; ++i)
	{
		int ny = cy + dY[i];
		int nx = cx + dX[i];

		if (ny >= 0 && nx >= 0 && ny < M && nx < N	// 인덱스 범위
			&& grid[cy][cx] > grid[ny][nx])			// 이동 가능 여부
			dp[cy][cx] += Dfs(ny, nx);
	}

	return dp[cy][cx];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 만약 앞쪽 경로가 이미 탐색에 성공한 적 있는 경로라면
	// 더 탐색할 필요가 없다.

	cin >> M >> N;

	grid.resize(M, vector<int>(N));
	for (vector<int>& v : grid)
	for (int& i : v)
		cin >> i;

	// 초기 값: -1(미방문)
	dp.resize(M, vector<int>(N, -1));

	cout << Dfs(0, 0);

	return 0;
}
