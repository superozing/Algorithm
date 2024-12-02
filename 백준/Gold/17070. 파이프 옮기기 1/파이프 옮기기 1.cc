///////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cmath>

using namespace std;

#define endl ("\n")

enum dir
{
    horizontal, // 가로
    vertical,   // 세로
    diagonal,   // 대각선
};

struct pos
{
    dir d; 
    int y, x;
};

class Boj
{
private:
    int N; // NxN

    vector<vector<int>> grid;

public:

    void input()
    {
        // 1. enum 쓰면 어떨까?
        // 2. bfs 써야 할 것 같다.
        // 3. visited가 필요할까? 아마 아닐 것
        
        cin >> N;

        grid.resize(N, vector<int>(N));

        for (int y = 0; y < N; ++y)
        for (int x = 0; x < N; ++x)
            cin >> grid[y][x];
    }

    void progress()
    {
        int answer = 0;

        queue<pos> q;
        q.push({ dir::horizontal, 0, 1 });

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            // 마지막 지점에 도달?
            if (cur.x == N - 1 && cur.y == N - 1)
            {
                answer++;
                continue;
            }

            // 오른 쪽으로 이동(이전에 세로로 이동한 경우 제외)
            if (cur.d != dir::vertical && cur.x + 1 < N && !grid[cur.y][cur.x + 1])
                q.push({ dir::horizontal, cur.y, cur.x + 1 });

            // 아래 쪽으로 이동(이전에 가로로 이동한 경우 제외)
            if (cur.d != dir::horizontal && cur.y + 1 < N && !grid[cur.y + 1][cur.x])
                q.push({ dir::vertical, cur.y + 1, cur.x });

            // 대각선으로 이동
            if (cur.y + 1 < N && cur.x + 1 < N 
                && !grid[cur.y + 1][cur.x + 1]
                && !grid[cur.y + 1][cur.x]
                && !grid[cur.y][cur.x + 1])
                q.push({ dir::diagonal, cur.y + 1, cur.x + 1});
        }

        cout << answer;
    }

private:

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}

