#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

enum eDice
{
	_top,
	_bottom,
	_front,
	_back,
	_left,
	_right
};

int dice[6]{};
int nextDice[6]{};

int dY[4]{ 0, 0, -1, 1 };
int dX[4]{ 1, -1, 0, 0 };

void RotateDice(int dir)
{
	switch (dir)
	{
	case 1:
		nextDice[_front] = dice[_front];
		nextDice[_back] = dice[_back];

		nextDice[_bottom] = dice[_right];
		nextDice[_left] = dice[_bottom];
		nextDice[_top] = dice[_left];
		nextDice[_right] = dice[_top];
		break;

	case 2:
		nextDice[_front] = dice[_front];
		nextDice[_back] = dice[_back];

		nextDice[_bottom] = dice[_left];
		nextDice[_right] = dice[_bottom];
		nextDice[_top] = dice[_right];
		nextDice[_left] = dice[_top];
		break;

	case 3:
		nextDice[_left] = dice[_left];
		nextDice[_right] = dice[_right];

		nextDice[_bottom] = dice[_front];
		nextDice[_back] = dice[_bottom];
		nextDice[_top] = dice[_back];
		nextDice[_front] = dice[_top];
		break;

	case 4:
		nextDice[_left] = dice[_left];
		nextDice[_right] = dice[_right];

		nextDice[_top] = dice[_front];
		nextDice[_back] = dice[_top];
		nextDice[_bottom] = dice[_back];
		nextDice[_front] = dice[_bottom];
		break;
	}

	swap(dice, nextDice);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, y, x, K;
	cin >> N >> M >> y >> x >> K;

	vector<vector<int>> grid(N, vector<int>(M));
	for (auto& v : grid)
	for (auto& i : v)
		cin >> i;

	while (K--)
	{
		int dir;
		cin >> dir;

		// 인덱스 범위 초과
		if (y + dY[dir - 1] < 0 || x + dX[dir - 1] < 0 || y + dY[dir - 1] >= N || x + dX[dir - 1] >= M)
			continue;

		RotateDice(dir);
		
		y += dY[dir - 1];
		x += dX[dir - 1];

		if (grid[y][x] == 0)
			grid[y][x] = dice[_bottom];
		else
		{
			dice[_bottom] = grid[y][x];
			grid[y][x] = 0;
		}

		cout << dice[_top] << endl;
	}


	return 0;
}
