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
    int R, C; // 행과 열

    vector<string> grid;
    vector<int> visited;

    int maxCnt = 0;

public:

    void input()
    {
        cin >> R >> C;
        grid.resize(R);

        visited.resize('Z' + 1);

        for (string& s : grid)
            cin >> s;
    }

    void progress()
    {
        visited[grid[0][0]] = true;
        dfs({ 0,0 }, 1);
        visited[grid[0][0]] = false;

        cout << maxCnt;
    }

private:
    int dY[4]{ 1, 0, -1, 0 };
    int dX[4]{ 0, 1, 0, -1 };

    void dfs(pos p, int cnt)
    {
        maxCnt = max(maxCnt, cnt);

        for (int i = 0; i < 4; ++i)
        {
            pos next = p;
            next.y += dY[i];
            next.x += dX[i];

            if (next.x >= 0 && next.x < C &&
                next.y >= 0 && next.y < R &&
                !visited[grid[next.y][next.x]])
            {
                visited[grid[next.y][next.x]] = true;
                dfs(next, cnt + 1);
                visited[grid[next.y][next.x]] = false;
            }
        }

        return;
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

