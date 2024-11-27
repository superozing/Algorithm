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
    int y, x, c;
};

class Boj
{
private:
    int N, M;
    vector<vector<int>> grid;
    vector<vector<int>> visited;

    queue<pos> q;
public:

    void input()
    {
        cin >> M >> N;

        grid.resize(N, vector<int>(M));
        visited.resize(N, vector<int>(M, 1e9));

        for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
    }

    void progress()
    {
        for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (grid[i][j] == 1)
            {
                q.push({ i, j, 0 });
                visited[i][j] = 0;
            }
        }

        bfs();
        //for (int i = 0; i < N; ++i)
        //{
        //    for (int j = 0; j < M; ++j)
        //    {
        //        cout << visited[i][j] << " ";
        //    }
        //    cout << endl;
        //}

        int answer = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (grid[i][j] != -1)
                    answer = max(answer, visited[i][j]);
            }
        }

        if (answer == 1e9)
            cout << -1;
        else
            cout << answer;
    }

private:

    int dy[4]{ 0, 1, 0, -1 };
    int dx[4]{ 1, 0, -1 ,0 };

    void bfs()
    {
        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            cur.c++;

            for (int i = 0; i < 4; ++i)
            {
                pos next = cur;
                next.y += dy[i];
                next.x += dx[i];

                if (next.y >= 0 && next.y < N &&
                    next.x >= 0 && next.x < M &&
                    grid[next.y][next.x] != -1 &&
                    visited[next.y][next.x] > cur.c)
                {
                    visited[next.y][next.x] = cur.c;
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

