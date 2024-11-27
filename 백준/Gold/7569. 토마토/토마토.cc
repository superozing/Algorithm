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
    int h, y, x, c;
};

class Boj
{
private:
    int H, N, M;
    vector<vector<vector<int>>> grid;
    vector<vector<vector<int>>> visited;

    queue<pos> q;
public:

    void input()
    {
        cin >> M >> N >> H;

        grid.resize(H, vector<vector<int>>(N, vector<int>(M)));
        visited.resize(H, vector<vector<int>>(N, vector<int>(M, 1e9)));

        for (int i = 0; i < H; ++i)
        for (int j = 0; j < N; ++j)
        for (int k = 0; k < M; ++k)
        {
            cin >> grid[i][j][k];

            if (grid[i][j][k] == 1)
            {
                q.push({ i, j, k, 0 });
                visited[i][j][k] = 0;
            }
        }
    }

    void progress()
    {
        bfs();

        int answer = 0;
        for (int i = 0; i < H; ++i)
        for (int j = 0; j < N; ++j)
        for (int k = 0; k < M; ++k)
        {
            if (grid[i][j][k] != -1)
                answer = max(answer, visited[i][j][k]);
        }

        if (answer == 1e9)
            cout << -1;
        else
            cout << answer;
    }

private:

    int dh[6]{ 1, -1, 0, 0, 0, 0 };
    int dy[6]{ 0, 0, 0, 1, 0, -1 };
    int dx[6]{ 0, 0, 1, 0, -1 ,0 };

    void bfs()
    {
        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            cur.c++;

            for (int i = 0; i < 6; ++i)
            {
                pos next = cur;
                next.h += dh[i];
                next.y += dy[i];
                next.x += dx[i];

                if (next.h >= 0 && next.h < H &&
                    next.y >= 0 && next.y < N &&
                    next.x >= 0 && next.x < M &&
                    grid[next.h][next.y][next.x] != -1 &&
                    visited[next.h][next.y][next.x] > cur.c)
                {
                    visited[next.h][next.y][next.x] = cur.c;
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

