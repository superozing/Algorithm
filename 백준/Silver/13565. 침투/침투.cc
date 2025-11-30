#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

struct Pos
{
    int y, x;
};

int dy[]{ 0,1,0,-1 };
int dx[]{ 1,0,-1,0 };

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int M, N;
    cin >> M >> N;

    vector<string> grid(M);

    for (string& s : grid)
        cin >> s;

    queue<Pos> q;

    string& outerSide = grid[0];

    for (int i = 0; i < outerSide.size(); ++i)
    {
        if (outerSide[i] == '0')
        {
            outerSide[i] = '1';
            q.push({ 0, i });
        }
    }

    while (!q.empty())
    {
        Pos cPos = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            Pos nPos = cPos;
            nPos.y += dy[i];
            nPos.x += dx[i];

            if (nPos.y >= 0 && nPos.y < M &&
                nPos.x >= 0 && nPos.x < N &&
                grid[nPos.y][nPos.x] == '0')
            {
                // 종료 조건
                if (nPos.y == M - 1)
                {
                    cout << "YES";
                    return 0;
                }

                grid[nPos.y][nPos.x] = '1';
                q.push(nPos);
            }
        }
    }

    cout << "NO";

    return 0;
}

