///////////////////////////////////////////https://www.acmicpc.net/problem/7576
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
    int y, x, c;
};

class Boj
{
private:
    int X, Y; // M: 가로, N: 세로
    vector<vector<int>> box;
    list<pos> q;

public:
    void input()
    {
        cin >> X >> Y;

        box.resize(Y, vector<int>(X));

        for (int y = 0; y < Y; ++y)
        for (int x = 0; x < X; ++x)
        {
            cin >> box[y][x];
            if (box[y][x] == 1)
            {
                box[y][x] = 0;
                q.push_back({ y, x, 0 });
            }
            else if (box[y][x] == 0)
            {
                box[y][x] = 1e9;
            }
        }
    }

    void progress()
    {
        // 0: 익지 않은 토마토
        // 1: 익은 토마토
        // -1: 토마토가 비어있는 칸
        // 익은 토마토가 들어있는 모든 칸에 대해서 bfs를 돌리면 될 것 같아요.

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop_front();

            cur.c++;

            for (int i = 0; i < 4; ++i)
            {
                pos np = cur;
                np.y += dy[i];
                np.x += dx[i];

                // 1. 익지 않은 토마토이면서 첫 방문일 경우
                // 2. 익지 않은 토마토이면서 첫 방문이 아니고, 
                //    토마토 익는 기간이 기록된 것보다 짧을 경우
                if (np.y < Y && np.y >= 0 &&
                    np.x < X && np.x >= 0 &&
                    box[np.y][np.x] > np.c && box[np.y][np.x] != -1)
                {
                    box[np.y][np.x] = np.c;
                    q.push_back(np);
                }
            }
        } // while end



        int answer = 0;
        for (int y = 0; y < Y; ++y)
        for (int x = 0; x < X; ++x)
        {
            if (box[y][x] == 1e9)
            {
                cout << -1;
                return;
            }
            if (box[y][x] == -1)
                continue;

            answer = max(box[y][x], answer);
        }

        cout << answer;
        return;
    }

private:

    int dy[4]{ 0, 1, 0, -1 };
    int dx[4]{ 1, 0, -1, 0 };
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

