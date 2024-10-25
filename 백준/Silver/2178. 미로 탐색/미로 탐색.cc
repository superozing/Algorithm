///////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

struct pos
{
    int y, x, cnt;
};

class Boj
{
private:
    int N, M;

    vector<vector<int>> grid;

    int dy[4]{ 0, -1, 0, 1 };
    int dx[4]{ -1, 0, 1, 0 };

public:
    void input()
    {
        cin >> N >> M;

        grid.resize(N, vector<int>(M));

        for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    void progress()
    {
        list<pos> q;
        q.push_back({ 0, 0, 1 });
        grid[0][0] = 0;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop_front();

            if (cur.y == N - 1 && cur.x == M - 1)
            {
                cout << cur.cnt;
                return;
            }

            ++cur.cnt;

            for (int i = 0; i < 4; ++i)
            {
                pos np = cur;
                np.y += dy[i];
                np.x += dx[i];

                if (np.y < N && np.x < M && np.y >= 0 && np.x >= 0 
                    && grid[np.y][np.x] == 1)
                {
                    grid[np.y][np.x] = 0;
                    q.push_back(np);
                }
            }
        }

        return;
    }

private:
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}

