#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Pos
{
    int y, x;
};

struct Node
{
    Pos r;
    Pos b;
    int c;
    vector<string> grid;
};


int dY[4]{ 1, 0, -1, 0 };
int dX[4]{ 0, -1, 0, 1 };

// 공이 홀에 들어갔는가? 를 반환해요.
// 0 -> 아무 일도 일어나지 않음
// 1 -> 빨간 공이 들어감
// 2 -> 파란 공이 들어감
// 3 -> 공이 움직이지 않음
int MoveBall(Pos& ball, int dirIdx, vector<string>& grid, char ballColor)
{
    auto startPos = ball;
    // 방향 미리 가져다놓기
    int mY = dY[dirIdx];
    int mX = dX[dirIdx];

    while (true)
    {
        int cY = ball.y;
        int cX = ball.x;

        int nY = cY + mY;
        int nX = cX + mX;

        // 다음 이동 위치 인덱스 유효 검사
        if (nY >= 0 && nY < grid.size() && nX >= 0 && nX < grid[0].size())
        {
            // 움직일 수 있는 경우
            if (grid[nY][nX] == '.')
            {
                // 1. 스왑
                swap(grid[cY][cX], grid[nY][nX]);

                // 2. cur 갱신
                ball.y = nY;
                ball.x = nX;
            }
            // 움직일 수 없는 경우
            else if (grid[nY][nX] == '#' || grid[nY][nX] == 'R' || grid[nY][nX] == 'B')
                break;
            // 구멍에 공이 들어간 경우
            else if (ballColor == 'R')
            {
                grid[ball.y][ball.x] = '.';
                return 1;
            }
            else
                return 2;
        }
    }

    // 한발짝도 안움직임
    if (startPos.y == ball.y && startPos.x == ball.x)
        return 3;

    // 목표 방향으로 전부 움직인 상태
    return false;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (auto& str : grid)
        cin >> str;

    Pos red{};
    Pos blue{};

    Pos hole{};

    for (int y = 0; y < N; ++y)
    for (int x = 0; x < M; ++x)
    {
        if (grid[y][x] == 'R')
            red = { y, x };
        if (grid[y][x] == 'B')
            blue = { y, x };
        if (grid[y][x] == 'H')
            hole = { y, x };
    }


    // 그냥 시뮬레이션 문제?
    // BFS 사용해야 할 것 같아요.

    // BFS 메모리 양이 감당이 가능한가?


    queue<Node> q;
    q.push({ red, blue, 0, grid });

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        cur.c++;

        if (cur.c > 10)
        {
            cout << -1;
            return 0;
        }

        for (int i = 0; i < 4; ++i)
        {
            auto next = cur;

            // 구슬 옮기는 로직을 따로 짜야 할 듯..
            // 만약에 아래로 구슬을 움직인다면 더 아래 있는 구슬이 먼저 옮겨져야 한다. (구슬끼리 겹치는 경우를 생각할 때)
            // 방향에 따라 예외처리 해주어야 해요.
            
            // 1. 방향에 따라 더 방향에 가까운 구슬을 찾기
            // 그 구슬 먼저 옮겨주어야 한다.
            // 구슬 옮기는 함수에 구슬 색을 먼저 넣어주는 것이 좋아보여요.

            // 위 왼 아 오 순
            
            bool isRedFirst = true;
            if (i == 0) // 아래
                isRedFirst = next.r.y > next.b.y;
            else if (i == 1) // 왼쪽
                isRedFirst = next.r.x < next.b.x;
            else if (i == 2) // 위
                isRedFirst = next.r.y < next.b.y;
            else if (i == 3) // 오른쪽
                isRedFirst = next.r.x > next.b.x;

            int isEnd = 0;
            isEnd = MoveBall(isRedFirst ? next.r : next.b, i, next.grid, isRedFirst ? 'R' : 'B');

            // 파란 공이 먼저 들어간 경우
            if (isEnd == 2)
                continue;

            int isEnd2 = 0;
            isEnd2 = MoveBall(isRedFirst ? next.b : next.r, i, next.grid, isRedFirst ? 'B' : 'R');

            if (isEnd2 == 1)
            {
                cout << next.c;
                return 0;
            }
            if (isEnd2 == 2)
                continue;

            if (isEnd == 1)
            {
                cout << next.c;
                return 0;
            }

            if (isEnd == 3 && isEnd2 == 3)
                continue;

            q.push(next);
        }

    }

    cout << -1; 

	return 0;
}