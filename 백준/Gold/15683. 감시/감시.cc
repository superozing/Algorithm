#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

struct CCTV
{
	int y, x;
	int type;
};

int N, M;

vector<vector<int>> grid;
vector<vector<int>> visited;

vector<CCTV> cams;

int dY[4]{ 0, 1, 0, -1 };
int dX[4]{ 1, 0, -1, 0 };

int answer = 1e9;

void Mark(int y, int x, int dir)
{
	if (y < 0 || x < 0 || y >= N || x >= M || grid[y][x] == 6)
		return;

	visited[y][x]++;

	y += dY[dir];
	x += dX[dir];

	Mark(y, x, dir);
}

void Mark(int curCam, int dir)
{
	CCTV& cam = cams[curCam];
	int camType = cam.type;

	switch (camType)
	{
	case 1:
		Mark(cam.y, cam.x, dir);
		break;
	case 2:
		Mark(cam.y, cam.x, (dir + 1) % 4);
		Mark(cam.y, cam.x, (dir + 3) % 4);
		break;
	case 3:
		Mark(cam.y, cam.x, dir);
		Mark(cam.y, cam.x, (dir + 1) % 4);
		break;
	case 4:
		Mark(cam.y, cam.x, dir);
		Mark(cam.y, cam.x, (dir + 1) % 4);
		Mark(cam.y, cam.x, (dir + 3) % 4);
		break;
	case 5:
		Mark(cam.y, cam.x, dir);
		Mark(cam.y, cam.x, (dir + 1) % 4);
		Mark(cam.y, cam.x, (dir + 2) % 4);
		Mark(cam.y, cam.x, (dir + 3) % 4);
		break;
	default:
		break;
	}
}

void Unmark(int y, int x, int dir)
{
	if (y < 0 || x < 0 || y >= N || x >= M || grid[y][x] == 6)
		return;

	visited[y][x]--;

	y += dY[dir];
	x += dX[dir];

	Unmark(y, x, dir);
}

void Unmark(int curCam, int dir)
{
	CCTV& cam = cams[curCam];
	int camType = cam.type;

	switch (camType)
	{
	case 1:
		Unmark(cam.y, cam.x, dir);
		break;
	case 2:
		Unmark(cam.y, cam.x, (dir + 1) % 4);
		Unmark(cam.y, cam.x, (dir + 3) % 4);
		break;
	case 3:
		Unmark(cam.y, cam.x, dir);
		Unmark(cam.y, cam.x, (dir + 1) % 4);
		break;
	case 4:
		Unmark(cam.y, cam.x, dir);
		Unmark(cam.y, cam.x, (dir + 1) % 4);
		Unmark(cam.y, cam.x, (dir + 3) % 4);
		break;
	case 5:
		Unmark(cam.y, cam.x, dir);
		Unmark(cam.y, cam.x, (dir + 1) % 4);
		Unmark(cam.y, cam.x, (dir + 2) % 4);
		Unmark(cam.y, cam.x, (dir + 3) % 4);
		break;
	default:
		break;
	}
}

void Bfs(int curCam)
{
	if (curCam == cams.size())
	{
		int blindSpot = 0;
		for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
		{
			// 사각지대인가?
			if (!visited[y][x] && grid[y][x] != 6)
				blindSpot++;
		}

		answer = min(answer, blindSpot);

		return;
	}

	int reps = cams[curCam].type == 2 ? 2 : (cams[curCam].type == 5 ? 1 : 4);

	for (int dir = 0; dir < reps; ++dir)
	{
		Mark(curCam, dir);
		Bfs(curCam + 1);
		Unmark(curCam, dir);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 1번 cctv의 경우 4가지 방향의 방법이 있고
	// 2번의 경우 2가지 방향의 방법이 있고
	// 3번은 4가지 방향의 방법이 있고
	// 4번은 4가지 방향의 방법이 있고
	// 5번은 없고...

	cin >> N >> M;

	grid.resize(N, vector<int>(M));
	visited.resize(N, vector<int>(M));

	for (int y = 0; y < N; ++y)
	for (int x = 0; x < M; ++x)
	{
		cin >> grid[y][x];

		if (grid[y][x] <= 5 && grid[y][x] >= 1)
			cams.push_back({ y, x, grid[y][x] });
	}

	Bfs(0);

	cout << answer;

	return 0;
}
