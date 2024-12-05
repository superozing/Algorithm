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

struct pos
{
    int y, x;
};

class Boj
{
private:
    int N, M;

    vector<vector<int>> grid;
    vector<vector<int>> visited;

    int maxSafeArea = 0;

public:

    void input()
    {
        cin >> N >> M;

        grid.resize(N, vector<int>(M));
        visited.resize(N, vector<int>(M));

        for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
    }

    void progress()
    {
        // 3개를 세워봐요.
        // 조합 냄새가 나요.

        for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
        {
            if (grid[y][x] != 0)
                continue;

            grid[y][x] = 1;
            permutation({ y, x }, 1);
            grid[y][x] = 0;
        }

        cout << maxSafeArea;
    }

private:

    void permutation(pos p, int cnt)
    {
        if (cnt == 3)
        {
            maxSafeArea = max(safeArea(), maxSafeArea);
            return;
        }

        for (int y = p.y; y < N; ++y)
        for (int x = 0; x < M; ++x)
        {
            if ((y == p.y && x < p.x) || grid[y][x] != 0)
                continue;

            grid[y][x] = 1;
            permutation({ y, x }, cnt + 1);
            grid[y][x] = 0;
        }

        return;
    }

    int safeArea()
    {
        visited = grid;

        for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
        {
            if (visited[y][x] == 2)
                bfs({y, x});
        }

        int area = 0;

        for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
        {
            if (visited[y][x] == 0)
                ++area;
        }

        return area;
    }

    int dy[4]{ 1, 0, -1, 0 };
    int dx[4]{ 0, 1, 0, -1 };

    void bfs(pos p)
    {
        queue<pos> q;
        q.push(p);

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                pos next = cur;
                next.y += dy[i];
                next.x += dx[i];

                if (next.y >= 0 && next.y < N &&
                    next.x >= 0 && next.x < M &&
                    visited[next.y][next.x] == 0)
                {
                    visited[next.y][next.x] = -1;
                    q.push(next);
                }
            }
        }
    }
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

