#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

struct Pos
{
    int y, x, c;
};

struct Cmp
{
    bool operator()(const Pos& a, const Pos& b)
    {
        return a.c > b.c;
    }
};

int dy[4]{ 1, 0, -1, 0 };
int dx[4]{ 0, 1, 0, -1 };

vector<vector<int>> grid;
vector<vector<int>> dp;
int N;

// 최대 땅 반환
int Search(Pos cur)
{
    // 이론상 pq로 작은 값 부터 끌어오니까
    // 자신보다 작은 값의 dp는 무조건 초기화되어있고
    // 자신보다 큰 값의 dp는 무조건 초기화되어있지 않을 것.
    // 그렇기 때문에 주변 4방향만 체크해도 결과를 얻을 수 있겠어요.

    int area = 1;

    for (int i = 0; i < 4; ++i)
    {
        Pos nextPos = cur;
        nextPos.y += dy[i];
        nextPos.x += dx[i];

        if (nextPos.y >= 0 && nextPos.y < N && nextPos.x >= 0 && nextPos.x < N && grid[nextPos.y][nextPos.x] < cur.c)
            area = max(area, 1 + dp[nextPos.y][nextPos.x]);
    }

    dp[cur.y][cur.x] = area;

    return area;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    // 판다는 대나무를 먹고 상 하 좌 우 중 한 방향으로 이동할 수 있다.
    // 판다는 현재 칸보다 더 많은 대나무가 있는 곳으로만 이동할 수 있다.
    // 분명 모든 경우의 수를 다 돌면 시간 초과가 날 것 같아요.

    // DP + 그래프 탐색을 해야 할 것 같아요.

    // DP는 해당 칸으로부터 최대 몇 칸 더 움직일 수 있는지를 기록하면 되겠네요.

    // PQ로 낮은 숫자 위치부터 하면 최적화 할 수 있겠어요.

    cin >> N;
    grid.resize(N, vector<int>(N));
    dp.resize(N, vector<int>(N, -1));


    priority_queue<Pos, vector<Pos>, Cmp> pq;

    for (int y = 0; y < N; ++y)
    for (int x = 0; x < N; ++x)
    {
        int in;
        cin >> in;
        pq.push({ y, x, in });
        grid[y][x] = in;
    }


    int answer = -1e9;
    while (!pq.empty())
    {
        Pos cur = pq.top();
        pq.pop();
        
        answer = max(Search(cur), answer);
    }

    cout << answer;

    return 0;
}
