#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <string>

#define endl '\n'

using namespace std;

void DivideAndConquer(const vector<string>& grid, int startY, int startX, int dataCount)
{
	char first = grid[startY][startX];

	bool isSameValue = true;
	for (int y = startY; y < startY + dataCount; ++y)
	{
		for (int x = startX; x < startX + dataCount; ++x)
		{
			if (grid[y][x] != first)
			{
				isSameValue = false;
				break;
			}
		}

		if (!isSameValue)
			break;
	}


	// 한 번에 출력 가능한가? -> 숫자
	if (isSameValue)
	{
		cout << first;
		return;
	}


	// 한 번에 출력할 수 없는가 -> 분할
	int nextCount = dataCount / 2;
	cout << '(';
	DivideAndConquer(grid, startY, startX, nextCount);
	DivideAndConquer(grid, startY, startX + nextCount, nextCount);
	DivideAndConquer(grid, startY + nextCount, startX, nextCount);
	DivideAndConquer(grid, startY + nextCount, startX + nextCount, nextCount);
	cout << ')';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<string> grid(N);
	for (string& s : grid)
		cin >> s;

	DivideAndConquer(grid, 0, 0, N);

	return 0;
}
