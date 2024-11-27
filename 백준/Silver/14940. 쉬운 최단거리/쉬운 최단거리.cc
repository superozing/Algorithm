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
    int y, x, c = 0;
};

class Boj
{
private:
    int N, M; // 가로와 세로의 크기

    vector<vector<int>> grid;
    pos start;

    int dy[4]{ 0, 1, 0, -1 };
    int dx[4]{ 1, 0, -1, 0 };

public:

    void input()
    {
        cin >> N >> M;

        grid.resize(N, vector<int>(M, -1));

        int in;
        for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> in;
            if (in == 2)
            {
                start.y = i;
                start.x = j;
            }
            else if (in == 0)
            {
                grid[i][j] = 0;
            }
        }
    }

    void progress()
    {
        queue<pos> q;
        grid[start.y][start.x] = 0;
        q.push(start);

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            ++cur.c;

            for (int i = 0; i < 4; ++i)
            {
                pos next = cur;

                next.y += dy[i];
                next.x += dx[i];

                if (next.x >= 0 && next.x < M &&
                    next.y >= 0 && next.y < N &&
                    grid[next.y][next.x] == -1)
                {
                    grid[next.y][next.x] = cur.c;
                    q.push(next);
                }
            }
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
                cout << grid[i][j] << " ";

            cout << endl;
        }

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

