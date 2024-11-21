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
    int x, y;
};

class Boj
{
private:
    int T; // 테케 개수
    int M, N; // 가로 길이, 세로 길이

    int K; // 배추 개수

    vector<vector<bool>> grid;

public:

    void input()
    {
        cin >> T;

    }

    void progress()
    {
        while (T--)
        {
            cin >> M >> N >> K;
            grid.clear();
            grid.resize(M, vector<bool>(N));

            int x, y;
            while (K--)
            {
                cin >> x >> y;
                grid[x][y] = true;
            }


            ////////////////

            int answer = 0;

            for (int x = 0; x < grid.size(); ++x)
            for (int y = 0; y < grid[0].size(); ++y)
            {
                if (grid[x][y] == true)
                {
                    ++answer;
                    bfs(x, y);
                }
            }

            cout << answer << endl;
        }
    }

private:

    int dx[4]{ 1, 0, -1, 0 };
    int dy[4]{ 0, 1, 0, -1 };

    void bfs(int x, int y)
    {
        queue<pos> q;

        q.push({ x, y });

        grid[x][y] = false;

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                pos np = cur;

                np.x += dx[i];
                np.y += dy[i];

                if (np.x >= 0 && np.x < grid.size() &&
                    np.y >= 0 && np.y < grid[0].size() &&
                    grid[np.x][np.y])
                {
                    q.push(np);
                    grid[np.x][np.y] = false;
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

