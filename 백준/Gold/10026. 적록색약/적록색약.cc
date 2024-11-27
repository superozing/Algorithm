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
    int N;

    vector<string> grid;
    vector<string> visited;

public:

    void input()
    {
        cin >> N;
        grid.resize(N);

        for (int i = 0; i < N; ++i)
            cin >> grid[i];
    }

    void progress()
    {
        cout << normal() << " " << daltonism();
    }

private:

    int dy[4]{ 1, 0, -1, 0 };
    int dx[4]{ 0, -1, 0, 1 };

    int normal()
    {
        visited = grid;
        int area = 0;

        for (int y = 0; y < N; ++y)
        for (int x = 0; x < N; ++x)
        {
            if (visited[y][x] != NULL)
            {
                bfs_normal({ y, x });
                ++area;
            }
        }

        return area;
    }

    void bfs_normal(pos s)
    {
        queue<pos> q;
        q.push(s);
        
        char color = visited[s.y][s.x];

        visited[s.y][s.x] = NULL;

        while (!q.empty())
        {
            pos cp = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                pos np = cp;
                np.y += dy[i];
                np.x += dx[i];

                if (np.y >= 0 && np.y < N &&
                    np.x >= 0 && np.x < N &&
                    visited[np.y][np.x] == color)
                {
                    visited[np.y][np.x] = NULL;
                    q.push(np);
                }
            }
        }
    }

    int daltonism()
    {
        visited = grid;
        int area = 0;

        for (int y = 0; y < N; ++y)
        for (int x = 0; x < N; ++x)
        {
            if (visited[y][x] != NULL)
            {
                bfs_daltonism({ y, x });
                ++area;
            }
        }
        return area;
    }

    bool isDaltonismValid(char c1, char c2)
    {
        if (c1 == c2)
            return true;

        if ((c1 == 'R' && c2 == 'G') || (c1 == 'G' && c2 == 'R'))
            return true;

        return false;
    }

    void bfs_daltonism(pos s)
    {
        queue<pos> q;
        q.push(s);

        char color = visited[s.y][s.x];

        visited[s.y][s.x] = NULL;

        while (!q.empty())
        {
            pos cp = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                pos np = cp;
                np.y += dy[i];
                np.x += dx[i];

                if (np.y >= 0 && np.y < N &&
                    np.x >= 0 && np.x < N &&
                    isDaltonismValid(visited[np.y][np.x], color))
                {
                    visited[np.y][np.x] = NULL;
                    q.push(np);
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

