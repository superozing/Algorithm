#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int dY[4]{ -1, 0, 1, 0 };
int dX[4]{ 0, -1, 0, 1 };


struct Pos
{
	int y, x, c;
};

struct cmp
{
	bool operator () (const Pos& a, const Pos& b)
	{
		if (a.c != b.c) 
			return a.c > b.c;
		if (a.y != b.y) 
			return a.y > b.y;
		return a.x > b.x;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// 아기 상어의 위치부터
	// 매 번 움직일 때 BFS 돌려야 할 것 같은데?
	// 이 때 next로 옮길 때 위, 왼 순서로 먼저 이동해야 할 듯
	// 구조체는 y, x, c로 하고

	int N;
	cin >> N;

	vector<vector<int>> grid(N, vector<int>(N));
	
	Pos startPos{};

	for (int y = 0; y < N; ++y)
	for (int x = 0; x < N; ++x)
	{
		cin >> grid[y][x];

		if (grid[y][x] == 9)
		{
			grid[y][x] = 0;
			startPos.y = y;
			startPos.x = x;
		}
	}


	// 크면 못지나감
	// 같으면 지나갈 수 있다
	// 작으면 먹을 수 있다.
	// 작은 물고기를 자신 크기만큼 먹으면 크기가 1 성장한다.
	// 움직이면 1초 소모한다.
	// 더이상 못 먹으면 엄마 찾는다.

	int answer = 0;
	int size = 2;
	int eatCount = 0;
	bool umMaaaaaaaaaa = false;
	while (!umMaaaaaaaaaa)
	{
		bool ate = false;
		priority_queue<Pos, vector<Pos>, cmp> q;
		vector<vector<bool>> visited(N, vector<bool>(N));

		q.push(startPos);
		visited[startPos.y][startPos.x] = true;

		while (!q.empty())
		{
			Pos cur = q.top();
			q.pop();

			// 종료조건
			if (grid[cur.y][cur.x] < size && grid[cur.y][cur.x])
			{
				// 크기가 작으면 먹을 수 있다.
				answer += cur.c;

				//cout << "cur: (" << cur.y << ", " << cur.x << ')' << endl;
				//cout << "size: " << size << ", eatCount: " << eatCount << ", moveCount: " << cur.c << endl << endl;

				// 시작 지점 설정
				startPos = cur;
				startPos.c = 0;

				// 크기 증가
				++eatCount;
				if (size == eatCount)
				{
					++size;
					eatCount = 0;
				}

				// 먹은 지점 비우기
				grid[cur.y][cur.x] = 0;

				// 루프 조건 설정
				ate = true;
				break;
			}
			
			// 미리 1초 더하기
			++cur.c;

			for (int i = 0; i < 4; ++i)
			{
				Pos next = cur;
				next.y += dY[i];
				next.x += dX[i];

				// 인덱스 범위 초과 or visited or 크기가 커서 못지나감
				if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N || visited[next.y][next.x] || grid[next.y][next.x] > size)
					continue;

				visited[next.y][next.x] = true;
				q.push(next);
			}
		}

		if (!ate)
			umMaaaaaaaaaa = true;
	}

	//for (int y = 0; y < N; ++y)
	//{
	//	for (int x = 0; x < N; ++x)
	//		cout << grid[y][x] << ' ';
	//	cout << endl;
	//}

	cout << answer;

	return 0;
}
 