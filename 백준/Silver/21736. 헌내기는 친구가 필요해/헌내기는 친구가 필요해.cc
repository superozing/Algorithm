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

class Boj
{
private:
    int N, M; // NxM
    int sy, sx; // 시작 y, 시작 x
    vector<string> grid;

    int dy[4]{ 0, 1, 0, -1 };
    int dx[4]{ 1, 0, -1, 0 };
public:

    void input()
    {
        sy = -1;

        cin >> N >> M;
        grid.resize(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> grid[i];
            
            // 아직 도연이 위치를 찾지 못한 경우
            if (sy == -1)
            {
                for (int j = 0; j < M; ++j)
                {
                    if ('I' == grid[i][j])
                    {
                        sy = i;
                        sx = j;
                        break;
                    }
                }
            }
        }

    }

    void progress()
    {
        int ans = dfs(sy, sx);

        if (ans == 0)
            cout << "TT";
        else
            cout << ans;
    }

    int dfs(int y, int x)
    {
        int ret = 0;

        // 도연이가 사람을 만난 경우
        if (grid[y][x] == 'P')
            ++ret;

        // visited 처리
        grid[y][x] = 'X';

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < M && grid[ny][nx] != 'X')
                ret += dfs(ny, nx);
        }

        return ret;
    }

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

