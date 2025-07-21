#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

int HorizontalLength(vector<string>& grid, int y)
{
	int returnValue = 0;
	int len = 1;
	for (int i = 1; i < grid.size(); ++i)
	{
		if (grid[y][i - 1] == grid[y][i])
			++len;
		else
			len = 1;

		returnValue = max(returnValue, len);
	}

	return returnValue;
}

int VerticalLength(vector<string>& grid, int x)
{
	int returnValue = 0;
	int len = 1;
	for (int i = 1; i < grid.size(); ++i)
	{
		if (grid[i - 1][x] == grid[i][x])
			++len;
		else
			len = 1;

		returnValue = max(returnValue, len);
	}

	return returnValue;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 일단 입력받으면 가능한 최대 길이 저장하기
	// 교환 후, 교환한 부분에 대해서 길이 측정하기
	// 이후 빠져나오면서 스왑 부분 돌려놓기

	int N;
	cin >> N;

	vector<string> grid(N, string(N, 0));
	for (string& s : grid)
		cin >> s;

	int answer = 1;

	// 1. 가로 길이 체크하기
	for (int y = 0; y < N; ++y)
		answer = max(answer, HorizontalLength(grid, y));

	// 2. 세로 길이 체크하기
	for (int x = 0; x < N; ++x)
		answer = max(answer, VerticalLength(grid, x));

	// 교환 시, 교환한 부분의 길이 체크를 하면 된다.

	// 1. 가로 교환하고 체크하기
	for (int y = 0; y < N; ++y)
	{
		for (int x = 1; x < N; ++x)
		{
			// 만약 다를 경우:
			if (grid[y][x] != grid[y][x - 1])
			{
				// 스왑하기
				swap(grid[y][x], grid[y][x - 1]);

				answer = max(answer, HorizontalLength(grid, y));
				answer = max(answer, VerticalLength(grid, x));
				answer = max(answer, VerticalLength(grid, x - 1));

				// 스왑 해제하기
				swap(grid[y][x], grid[y][x - 1]);
			}
		}
	}

	// 2. 세로 교환하고 체크하기
	for (int x = 0; x < N; ++x)
	{
		for (int y = 1; y < N; ++y)
		{
			// 만약 다를 경우:
			if (grid[y][x] != grid[y - 1][x])
			{
				// 스왑하기
				swap(grid[y][x], grid[y - 1][x]);

				answer = max(answer, HorizontalLength(grid, y));
				answer = max(answer, HorizontalLength(grid, y - 1));
				answer = max(answer, VerticalLength(grid, x));

				// 스왑 해제하기
				swap(grid[y][x], grid[y - 1][x]);
			}
		}
	}

	cout << answer;

	return 0;
}
